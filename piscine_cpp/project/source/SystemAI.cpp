#include "SystemAI.hpp"

#include "ComponentCollisionBox.hpp"
#include "ComponentMove.hpp"
#include "ComponentPlayerControl.hpp"

#include "Vars.hpp"

#include "Operations.hpp"

#include <SFML/Graphics/Rect.hpp>

#include <cstdlib>

#define MAP_WIDTH 64
#define BOX_SIZE 16
#define getIndex(vector) vector.x / BOX_SIZE + (unsigned int)vector.y / BOX_SIZE * MAP_WIDTH

#define PATH_REFRESH_RATE .5f


AISystem::AISystem()
{
    for(unsigned int i = 0; i != (MAP_WIDTH * MAP_WIDTH); ++i)
    {
        m_map.push_back(false);
    }
}

void AISystem::update()
{
    for(Entity* entity : m_entities)
    {
        AI* ai = entity->getComponent<AI>();

        if(ai->getState() == AI::moving)
        {
            Path* path = ai->getPath();

            if(getDistance(entity->getPosition(), m_player->getPosition()) < ai->getAttackDistance())
            {
                delete path;

                ai->setState(AI::attacking);

                Message msg(Message::MSetMove);
                msg.vector = sf::Vector2f(0,0);
                entity->receive(msg);
            }
            else
            {
                path->counter += dt;

                if(path->counter > PATH_REFRESH_RATE)
                {
                    delete path;
                    ai->setPath(pathFind(entity->getPosition(), m_player->getPosition()));
                }
                if(path->travelledDistance > abs(path->lines[0].x) + abs(path->lines[0].y))
                {
                    path->travelledDistance = 0;
                    path->lines.erase(path->lines.begin());

                    Message msg(Message::MSetMove);
                    msg.vector.x = path->lines[0].x != 0 ? (path->lines[0].x > 0) * 2 - 1 : 0;
                    msg.vector.y = path->lines[0].y != 0 ? (path->lines[0].y > 0) * 2 - 1 : 0;

                    entity->receive(msg);
                }
            }
        }
        else
        {
            if(getDistance(entity->getPosition(), m_player->getPosition()) > ai->getAttackDistance())
            {
                ai->setState(AI::moving);
                ai->setPath(pathFind(entity->getPosition(), m_player->getPosition()));
            }
            else
            {
                ai->attack(m_player);
            }
        }
    }
}

void AISystem::add(Entity* entity)
{
    AI* ai = entity->getComponent<AI>();
    if(ai)
    {
        m_entities.push_back(entity);
        if(getDistance(entity->getPosition(), m_player->getPosition()) < ai->getAttackDistance())
        {
            ai->setState(AI::attacking);
        }
        else
        {
            entity->getComponent<AI>()->setPath(pathFind(entity->getPosition(), m_player->getPosition()));
        }
    }
    else if(entity->getComponent<CollisionBox>() && !entity->getComponent<Move>())
    {
        sf::FloatRect boxRect(entity->getComponent<CollisionBox>()->getBoxRect());

        unsigned int topLeftCorner = boxRect.left / BOX_SIZE + floor(boxRect.top / BOX_SIZE) * MAP_WIDTH;

        unsigned int yTabsNb = ceil(boxRect.height / BOX_SIZE) + ((unsigned int)boxRect.height % BOX_SIZE > BOX_SIZE - (unsigned int)boxRect.top % BOX_SIZE);
        unsigned int xTabsNb = ceil(boxRect.width / BOX_SIZE) + ((unsigned int)boxRect.width % BOX_SIZE > BOX_SIZE - (unsigned int)boxRect.left % BOX_SIZE);

        for(unsigned int i = 0; i != xTabsNb; ++i)
        {
            m_map[topLeftCorner + i] = true;

            for(unsigned int j = 0; j != yTabsNb; ++j)
            {
                m_map[topLeftCorner + i + j * MAP_WIDTH] = true;
            }
        }
    }
    else if(!m_player && entity->getComponent<PlayerControl>())
    {
        m_player = entity;
    }
}

void AISystem::remove(Entity* entity)
{
    if(entity->getComponent<AI>())
    {
        for(unsigned int i = 0; i != m_entities.size(); ++i)
        {
            if(m_entities[i] == entity)
            {
                m_entities.erase(m_entities.begin() + i);

                Message msg;
                msg.number = m_entities.size();
                msg.vector = entity->getPosition();

                systems[System::spawner]->receive(msg);

                break;
            }
        }
    }
}


struct node{

    node(unsigned int Index, unsigned int G, unsigned int H, node* Parent = nullptr) : index(Index), g(G), h(H), parent(Parent){}

    unsigned int f() const
    {
        return g + h;
    }

    unsigned int index;

    unsigned int g;
    unsigned int h;

    node* parent;
};

Path* AISystem::pathFind(const sf::Vector2f& basePos, const sf::Vector2f& destinationPos)
{
    std::vector<node*> openedList;
    std::vector<node*> closedList;

    unsigned int destinationIndex = getIndex(destinationPos);


    openedList.push_back(new node(getIndex(basePos), 0, getDistance(basePos, destinationPos) / BOX_SIZE));

    while(true)
    {
        node* currentNode;

        {
            unsigned int f = -1;
            unsigned int index;

            for(unsigned int i = openedList.size(); i-- != 0;)
            {
                if(openedList[i]->f() < f)
                {
                    index = i;
                    f = openedList[i]->f();
                }
            }

            currentNode = openedList[index];
            openedList.erase(openedList.begin() + index);
            closedList.push_back(currentNode);
        }


        unsigned int indexesUsed[4];

        for(unsigned int i = 0; i != 4; ++i)
        {
            unsigned int index;
            unsigned char rand;

            for(bool freeIndex = false; !freeIndex;)
            {
                rand = std::rand() & 3;

                index = currentNode->index;
                index += rand < 2 ? - rand * 2 + 1 : MAP_WIDTH * (2 * (rand - 2) - 1);

                freeIndex = true;

                for(unsigned char j = 0; j != i; ++j)
                {
                    if(index == indexesUsed[j])
                    {
                        freeIndex = false;
                        break;
                    }
                }
            }

            indexesUsed[i] = index;


            if(m_map[index] == true && index != destinationIndex)
            {
                continue;
            }

            bool isInClosedList = false;
            for(unsigned int j = 0; j != closedList.size(); ++j)
            {
                if(closedList[j]->index == index)
                {
                    isInClosedList = true;
                    break;
                }
            }

            if(isInClosedList)
            {
                continue;
            }

            node* Node = nullptr;

            for(unsigned int j = openedList.size(); --j != (unsigned int)-1;)
            {
                if(openedList[j]->index == index)
                {
                    Node = openedList[j];
                    break;
                }
            }

            if(!Node)
            {
                if(index == destinationIndex)
                {
                    Path* path = new Path;

                    Node = currentNode;
                    int shift = destinationIndex - Node->index;

                    unsigned int lineLength = 1;

                    while(Node->parent)
                    {
                        if((int)(Node->index - Node->parent->index) != shift)
                        {
                            sf::Vector2i move(0,0);
                            if(abs(shift) == 1)
                            {
                                move.x = shift * lineLength * BOX_SIZE;
                            }
                            else
                            {
                                move.y = shift / MAP_WIDTH * lineLength * BOX_SIZE;
                            }

                            path->lines.insert(path->lines.begin(), move);
                            shift = Node->index - Node->parent->index;

                            lineLength = 0;
                        }

                        Node = Node->parent;
                        ++lineLength;
                    }

                    sf::Vector2i move(0,0);
                    if(abs(shift) == 1)
                    {
                        move.x = shift * lineLength * BOX_SIZE;
                    }
                    else
                    {
                        move.y = shift / MAP_WIDTH * lineLength * BOX_SIZE;
                    }

                    path->lines.insert(path->lines.begin(), move);

                    path->lines.emplace(path->lines.begin(), sf::Vector2f(0,0));

                    for(node* Node : openedList)
                    {
                        delete Node;
                    }

                    for(node* Node : closedList)
                    {
                        delete Node;
                    }

                    return path;
                }

                openedList.push_back(new node(index, currentNode->g + 1,
                                              abs(index % MAP_WIDTH - destinationIndex % MAP_WIDTH) + abs(index / MAP_WIDTH - destinationIndex / MAP_WIDTH),
                                              currentNode));
            }
            else if(currentNode->g + 1 < Node->g)
            {
                Node->parent = currentNode;
                Node->g = currentNode->g + 1;
            }
        }
    }
}
