#pragma once
#include "Scene.h"
class Ball;

class SceneCollision : public Scene
{
protected:
	sf::RectangleShape slide;
	sf::RectangleShape ground;
	Ball* ball;
	sf::RectangleShape start;

	bool isShoot;
	sf::Vector2i mouseStart;
	sf::Vector2i mouseEnd;

	float COR = 0.3f;

public:
	SceneCollision();
	~SceneCollision() = default;

	void Init() override;
	void Enter() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

