#include "DisplaySfml.hpp"
#include <string>
#include <cstring>
#include <sstream>

/*
** Builtin functions
*/

DisplaySfml::DisplaySfml(std::deque<DataMessage*> data): _data(data), _window(sf::VideoMode(600, 800), "SFML works!"), _x(0), _y(0)
{}

DisplaySfml::~DisplaySfml()
{
}

/*
** Class Specific functions
*/

void    DisplaySfml::render(std::deque<DataMessage*> lst)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        exit(0) ;
    if (_window.isOpen())
    {
        DataMessage*    data;
        sf::Event event;
        if (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        _x = 5;
        _y = 0;
        for (std::deque<DataMessage*>::iterator it = lst.begin(); it != lst.end(); ++it)
        {
            data = *it;
            if (data->getType() == DataMessage::Single)
            {
                renderSingle(*data);
                _y += 45;
            }
            if (data->getType() == DataMessage::Serie)
            {
                renderSerie(*data);
                _y += 45;
            }
        }
        _window.display();
    }
}

void    DisplaySfml::renderSingle(DataMessage & msg)
{
    sf::Text            text;
    sf::Font            font;
    std::stringstream   stream;
    std::string         string;
    
    if (!font.loadFromFile("font/roboto/Roboto-Medium.ttf")) {
        std::cout << "Error while loading font" << std::endl;
        _window.close();
        exit(1);
    }
    text.setFont(font);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::Green);
    if (msg.getTitle().length() != 0)
    {
        stream << msg.getTitle() << std::endl;
        stream >> string;
        text.setString(string);
        text.setPosition(_x, _y);
        _window.draw(text);
        stream.str(std::string());
    }
    std::string  a = *(reinterpret_cast<std::string*>(msg.getAddr()));
    text.setString(a);
    stream.str(std::string());
    text.setCharacterSize(16);  
    text.setFillColor(sf::Color::White);
    text.setPosition(_x, _y + 20);
    _window.draw(text);
}

void    DisplaySfml::renderSerie(DataMessage & msg)
{
    sf::Text            text;
    sf::Font            font;
    std::stringstream   stream;
    std::string         string;

    if (!font.loadFromFile("font/roboto/Roboto-Medium.ttf")) {
        std::cout << "Error while loading font" << std::endl;
        _window.close();
        exit(1);
    }
    text.setFont(font);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::Green);
    text.setPosition(_x, _y);
    if (msg.getTitle().length() != 0)
    {
        stream << msg.getTitle() << std::endl;
        stream >> string;
        text.setString(string);
        _window.draw(text);
        stream.str(std::string());
    }
    stream << "[";
    std::deque<float>  data = *(reinterpret_cast<std::deque<float>*>(msg.getAddr()));
    int len = 100;
    text.setFillColor(sf::Color::White);
    if (len > 10)
    {
        std::string     bar("");
        stream >> bar;
        while (bar.length() < static_cast<unsigned long>(static_cast<float>(len) * data.back())) {
            bar += "|";
        }
        bar += "]";
        text.setString(bar);
        text.setFillColor(sf::Color::White);
        text.setPosition(_x, _y + 20);
        _window.draw(text);
        
    }
    stream.str(std::string());
}