#include "SystemPhysics.hpp"

#include "Vars.hpp"

#include "ComponentPlayerControl.hpp"


void PhysicsSystem::update()
{
    for(unsigned int i = 0 ; i != m_movingBoxes; ++i)
    {
        if(!m_moves[i]->isMoving())
        {
            continue;
        }

        CollisionBox* box = m_boxes[i];

        m_boxes.erase(m_boxes.begin() + i);

        sf::Vector2f finalMove = m_moves[i]->getMove() * dt;

        sf::FloatRect ownFinalBox = box->getBoxRect();
        ownFinalBox.left += finalMove.x;
        ownFinalBox.top += finalMove.y;


        for(unsigned int j = 0; j != m_boxes.size(); ++j)
        {
            if(ownFinalBox.intersects(m_boxes[j]->getBoxRect()))
            {
                const sf::FloatRect& collidedRect = m_boxes[j]->getBoxRect();

                if(box->reactsOnCollision())
                {
                    box->collision(m_boxes[j]->getOwner());
                }

                if(finalMove.y > 0)
                {
                    if(finalMove.x == 0 || (ownFinalBox.left > collidedRect.left && ownFinalBox.left + ownFinalBox.width < collidedRect.left + collidedRect.width))
                    {
                        finalMove.y -= ownFinalBox.top + ownFinalBox.height - collidedRect.top;
                    }
                    else if(finalMove.x > 0)
                    {
                        if(ownFinalBox.top + ownFinalBox.height - (finalMove.y / finalMove.x) * (ownFinalBox.left + ownFinalBox.width - collidedRect.left) < collidedRect.top)
                        {
                            finalMove.y -= ownFinalBox.top + ownFinalBox.height - collidedRect.top;
                        }
                        else
                        {
                            finalMove.x -= ownFinalBox.left + ownFinalBox.width - collidedRect.left;
                        }
                    }
                    else
                    {
                        if(ownFinalBox.top + ownFinalBox.height + (finalMove.y / finalMove.x) * (collidedRect.left + collidedRect.width - ownFinalBox.left) < collidedRect.top)
                        {
                            finalMove.y -= ownFinalBox.top + ownFinalBox.height - collidedRect.top;
                        }
                        else
                        {
                            finalMove.x += collidedRect.left + collidedRect.width - ownFinalBox.left;
                        }
                    }
                }
                else if(finalMove.y < 0)
                {
                    if(finalMove.x == 0 || (ownFinalBox.left > collidedRect.left && ownFinalBox.left + ownFinalBox.width < collidedRect.left + collidedRect.width))
                    {
                        finalMove.y += collidedRect.top + collidedRect.height - ownFinalBox.top;
                    }
                    else if(finalMove.x > 0)
                    {
                        if(ownFinalBox.top - (finalMove.y / finalMove.x) * (ownFinalBox.left + ownFinalBox.width - collidedRect.left) > collidedRect.top + collidedRect.height)
                        {
                            finalMove.y += collidedRect.top + collidedRect.height - ownFinalBox.top;
                        }
                        else{
                            finalMove.x -= ownFinalBox.left + ownFinalBox.width - collidedRect.left;
                        }
                    }
                    else
                    {
                        if(ownFinalBox.top + (finalMove.y / finalMove.x) * (collidedRect.left + collidedRect.width - ownFinalBox.left) > collidedRect.top + collidedRect.height)
                        {
                            finalMove.y += collidedRect.top + collidedRect.height - ownFinalBox.top;
                        }
                        else
                        {
                            finalMove.x += collidedRect.left + collidedRect.width - ownFinalBox.left;
                        }
                    }
                }
                else
                {
                    finalMove.x += finalMove.x > 0 ? - (ownFinalBox.left + ownFinalBox.width - collidedRect.left) : collidedRect.left + collidedRect.width - ownFinalBox.left;
                }

                ownFinalBox.left = box->getBoxRect().left + finalMove.x;
                ownFinalBox.top = box->getBoxRect().top + finalMove.y;
            }
        }

        Message msg(Message::MMove);
        msg.vector = finalMove;
        m_moves[i]->getOwner()->receive(msg);

        m_boxes.insert(m_boxes.begin() + i, box);
    }


    for(unsigned int i = m_movingBoxes; i != m_moves.size(); ++i)
    {
        if(m_moves[i]->isMoving())
        {
            Message msg(Message::MMove);
            msg.vector = m_moves[i]->getMove() * dt;
            m_moves[i]->getOwner()->receive(msg);
        }
    }

    for(CollisionBoxPlayer* boxPlayer : m_boxesPlayer)
    {
        if(m_playerCollisionBox->getBoxRect().intersects(boxPlayer->getBoxRect()))
        {
            boxPlayer->collision(m_playerCollisionBox->getOwner());
        }
    }
}

void PhysicsSystem::add(Entity* entity)
{
    CollisionBox* box = entity->getComponent<CollisionBox>();
    Move* move = entity->getComponent<Move>();

    if(box)
    {
        if(move)
        {
            m_boxes.insert(m_boxes.begin(), box);
            m_moves.insert(m_moves.begin(), move);
            ++ m_movingBoxes;

            if(!m_playerCollisionBox && entity->getComponent<PlayerControl>())
            {
                m_playerCollisionBox = box;
            }
        }
        else
        {
            m_boxes.push_back(box);
        }
    }
    else if(move)
    {
        m_moves.push_back(move);
    }
    else if(entity->getComponent<CollisionBoxPlayer>())
    {
        m_boxesPlayer.push_back(entity->getComponent<CollisionBoxPlayer>());
    }
}

void PhysicsSystem::remove(Entity* entity)
{
    Move* move = entity->getComponent<Move>();

    if(move)
    {
        for(unsigned int i = 0; i != m_moves.size(); ++i)
        {
            if(move == m_moves[i])
            {
                m_moves.erase(m_moves.begin() + i);
                if(i < m_movingBoxes)
                {
                    m_boxes.erase(m_boxes.begin() + i);
                    --m_movingBoxes;
                }

                break;
            }
        }
    }
    else
    {
        CollisionBox* box = entity->getComponent<CollisionBox>();
        if(box)
        {
            for(unsigned int i = m_movingBoxes; i != m_boxes.size(); ++i)
            {
                if(box == m_boxes[i])
                {
                    m_boxes.erase(m_boxes.begin() + i);
                    break;
                }
            }
        }
        else if(entity->getComponent<CollisionBoxPlayer>())
        {
            CollisionBoxPlayer* boxPlayer = entity->getComponent<CollisionBoxPlayer>();

            for(unsigned char i = 0; i != m_boxesPlayer.size(); ++i)
            {
                if(boxPlayer == m_boxesPlayer[i])
                {
                    m_boxesPlayer.erase(m_boxesPlayer.begin() + i);
                    break;
                }
            }
        }
    }
}
