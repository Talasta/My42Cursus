#include "Vars.hpp"


int main()
{
    GameStateManager game;

	while(game.isRunning)
	{
        game.update();
		game.draw();
	}

	return 0;
}
