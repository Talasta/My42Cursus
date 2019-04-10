#include <Scene.hpp>
#include <EntityFactory.hpp>
#include <game.hpp>

int		main()
{
	Scene			scene;
	int				ret;

	if (!(ret = scene.init()))
	{
		scene.addEntity(EF::build(PLAYER_SPAWN_POS_VEC, EF::Player));

		while ((ret = scene.update()) > 0)
			scene.updateEntities();
	}
	return -ret;
}
