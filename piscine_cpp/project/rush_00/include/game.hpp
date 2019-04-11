#ifndef GAME_HPP
#define GAME_HPP

#include "globals.hpp"

#define		PLAYER_SPAWN_POS_VEC Vector2f(.5f,.5f)

// Used in EntityFactory
#define     ENEMY_SPEED_LIMITE 30.f
#define		BULLET_SPEED 100.f
#define 	BULLET_SPEED_VECTORF Vector2f(BULLET_SPEED, 0.f)
#define     ENEMY_BULLET_SPEED -50.f
#define 	ENNEMY_BULLET_SPEED_VECTORF Vector2f(ENEMY_BULLET_SPEED, 0.f)
#define		BULLET_BOX_VECTORF Vector2f(.4f, .4f)
#define     BACKGROUND_SPEED std::rand() % 50 + 200
#define     BACKGROUND_SPEED_VECTORF Vector2f(-static_cast<float>(BACKGROUND_SPEED), 0.f)

// Used in SystemPlayerInput
#define     INIT_ENEMY_BULLET_TIME static_cast<float>(std::rand() % 2000) / 1000.f
#define		BULLETTIME_LIMIT .1f
#define		BULLETTIME_LIMIT_ENEMIES 2.f

// Used in SystemEnemies
#define     BASE_ENEMIES_SPAWNED 8
#define		BULLET_SPAWN_PLAYER_DIST 3.f
#define		BULLET_SPAWN_ENEMY_DIST -5.f

// Game Over menu relative
#define		CENTER_TEXT_WINDOW(s) ((g_gamesize.x-sizeof(s))/2)
#define		GAMEOVER_STR "GAME OVER"
#define		GAMEOVER_POS_VEC Vector2f(CENTER_TEXT_WINDOW(GAMEOVER_STR),g_gamesize.y/3)
#define		GAMEOVER_CHOICES_DIST (g_gamesize.y/12.f)
#define		GAMEOVER_CHOICE_Y(x) (g_gamesize.y*.5f+GAMEOVER_CHOICES_DIST*x)
#define		GAMEOVER_SEL_X (g_gamesize.x / 2.5f)
#define		GAMEOVER_RETRY_STR "Retry"
#define		GAMEOVER_RETRY_POS_VEC Vector2f(CENTER_TEXT_WINDOW(GAMEOVER_RETRY_STR),GAMEOVER_CHOICE_Y(0))
#define		GAMEOVER_ADMIRE_STR "Admire"
#define		GAMEOVER_ADMIRE_POS_VEC Vector2f(CENTER_TEXT_WINDOW(GAMEOVER_ADMIRE_STR),GAMEOVER_CHOICE_Y(1))
#define		GAMEOVER_QUIT_STR "Quit"
#define		GAMEOVER_QUIT_POS_VEC Vector2f(CENTER_TEXT_WINDOW(GAMEOVER_QUIT_STR),GAMEOVER_CHOICE_Y(2))

#define		UI_HEIGHT 4

#endif
