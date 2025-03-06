#include "BeachBallManager.h"

BeachBallManager::BeachBallManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 20; i++) {
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BeachBallManager::~BeachBallManager()
{
}

void BeachBallManager::spawn()
{
	for (int i = 0; i < balls.size(); i++) {
		if (!balls[i].isAlive()) {
			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
		}
		else if (i == balls.size() - 1 && balls.size() < MAX_BALLS) {
			balls.push_back(Ball());
			balls[i].setTexture(&texture);
			balls[i].setSize(sf::Vector2f(100, 100));
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			std::cout << balls.size() << std::endl;
		}
	}
}

void BeachBallManager::update(float dt)
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void BeachBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			if (balls[i].getPosition().x < -100) {
				balls[i].setAlive(false);
			}
			else if (balls[i].getPosition().x > 800) {
				balls[i].setAlive(false);
			}

			if (balls[i].getPosition().y < -100) {
				balls[i].setAlive(false);
			}
			else if (balls[i].getPosition().y > 600) {
				balls[i].setAlive(false);
			}
		}
	}
}

void BeachBallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			window->draw(balls[i]);
		}
	}
}
