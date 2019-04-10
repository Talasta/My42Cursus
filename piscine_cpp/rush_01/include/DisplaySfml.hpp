#ifndef DISPLAYSFML_HPP
# define DISPLAYSFML_HPP

# include <SFML/Graphics.hpp>
# include "IMonitorDisplay.hpp"

class DisplaySfml : public IMonitorDisplay
{
public:

	DisplaySfml(std::deque<DataMessage*>);
	virtual ~DisplaySfml();

	virtual void    render(std::deque<DataMessage*>);
    virtual void    renderSingle(DataMessage& msg);
    virtual void    renderSerie(DataMessage& msg);

private:
    std::deque<DataMessage*>    _data;
    sf::RenderWindow            _window;
    float                       _x;
    float                       _y;

	DisplaySfml(const DisplaySfml &);
	DisplaySfml & operator=(const DisplaySfml &);

};

#endif