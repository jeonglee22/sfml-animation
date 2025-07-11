#include "stdafx.h"
#include "Ball.h"
#include "SceneCollision.h"

SceneCollision::SceneCollision()
	: Scene(SceneIds::Collision)
{
}

void SceneCollision::Init()
{
	auto size = FRAMEWORK.GetWindowSizeF();

	start.setSize({ 20.f,20.f });
	start.setOrigin({ 10.f,10.f });
	start.setPosition({ 100.f, 100.f });

	ground.setSize({ size.x, 200.f });
	ground.setOrigin({ size.x / 2.f , 100.f });
	ground.setPosition({ size.x / 2.f , 700.f });
	ground.setFillColor(sf::Color::Green);

	slide.setSize({ size.x, 800.f });
	slide.setOrigin({ size.x / 2.f , 100.f });
	slide.setRotation(30.f);
	slide.setPosition({ 0.f , 400.f });
	slide.setFillColor(sf::Color::Green);

	ball = (Ball*)AddGameObject(new Ball("Ball"));
	ball->GetBody().setRadius(10.f);
	ball->SetOrigin(Origins::MC);

	isShoot = false;
	Variables::isDrawHitBox = false;

	Scene::Init();
}

void SceneCollision::Enter()
{
	auto size = FRAMEWORK.GetWindowSizeF();
	sf::Vector2f center{ size.x * 0.5f, size.y * 0.5f };
	uiView.setSize(size);
	uiView.setCenter(center);
	worldView.setSize(size);
	worldView.setCenter(center);

	ball->SetPosition(start.getPosition());

	Scene::Enter();
}

void SceneCollision::Update(float dt)
{
	Scene::Update(dt);

	if(!ball->GetShoot())
	{
		ball->SetPosition(start.getPosition());
	}
}

void SceneCollision::Draw(sf::RenderWindow& window)
{
	window.draw(start);
	window.draw(ground);
	window.draw(slide);

	Scene::Draw(window);
}