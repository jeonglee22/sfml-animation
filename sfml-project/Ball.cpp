#include "stdafx.h"
#include "Ball.h"

Ball::Ball(const std::string& name)
	: GameObject(name)
{
}

void Ball::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	body.setPosition(pos);
}

void Ball::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	body.setRotation(rot);
}

void Ball::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	body.setScale(s);
}

void Ball::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	body.setOrigin(o);
}

void Ball::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(body, preset);
	}
}

void Ball::Init()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;

	restitution = 0.3f;

	isShoot = false;

	hitBox.SetType(HitBox::Type::Circle);
}

void Ball::Release()
{
}

void Ball::Reset()
{	
	SetVelocity(400.f);
	SetDirection({ 1.f,0.f });
	SetScale({ 1.f,1.f });
	SetRotation(0.f);
}

void Ball::Update(float dt)
{
	if (!isShoot)
	{
		SetShoot(true);
	}
	else
	{
		std::cout << (int) hitBox.type << std::endl;
		direction += 0.5f * sf::Vector2f(0, FRAMEWORK.GetGravity()) * dt * dt;
		SetPosition(position + speed * dt * direction);
		if (GetPosition().x > 1200.f)
		{
			SetShoot(false);
			Reset();
		}
		if (GetPosition().y >= 590.f)
		{
			SetPosition({ position.x, 590.f });
			SetDirection({ direction.x,direction.y * -1.f });
			SetVelocity(speed * restitution);
			if (speed <= 10.f)
			{
				speed = 0.f;
			}
		}
		float radius = body.getRadius();
		hitBox.UpdateTransform(body, radius);
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	if(isShoot)
	{
		window.draw(body);
		hitBox.Draw(window);
	}
}