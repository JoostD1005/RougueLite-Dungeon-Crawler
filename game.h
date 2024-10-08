#pragma once
#include "Player.hpp"
#include "Tilemap.hpp"


namespace Tmpl8 {

class Surface;

enum class State
{
	start,
	game,
	gameOver,

};


class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );

	void StartScreen(float deltaTime);
	void GameScreen(float deltaTime);
	void GameOverScreen(float deltaTime);




	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp(int key);
	void KeyDown(int key);





private:

	State state = State::game;

	Surface* screen;
	Player player = Player("assets/Player.png", 1);
	Tilemap tilemap;

	Tmpl8::vec2 playerStartingPos = 0;

	Tmpl8::vec2 cameraOffset = { 0, 0 };
	
	bool isWDown = false;
	bool isADown = false;
	bool isSDown = false;
	bool isDDown = false;
};

}; // namespace Tmpl8