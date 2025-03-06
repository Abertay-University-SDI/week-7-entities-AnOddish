#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Space)) {
		beachBallManager.spawn();
	}
}

// Update game objects
void Level::update(float dt)
{
	beachBallManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	beachBallManager.render(window);
	endDraw();
}
