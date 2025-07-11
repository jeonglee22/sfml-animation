#include "stdafx.h"
#include "Block.h"

Block::Block(const std::string& name)
	: GameObject(name)
{
}

void Block::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	body.setPosition(pos);
}

void Block::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	body.setRotation(rot);
}

void Block::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	body.setScale(s);
}

void Block::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	body.setOrigin(o);
}

void Block::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(body, preset);
	}
}

void Block::Init()
{
	auto size = FRAMEWORK.GetWindowSizeF();

	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;

	restitution = 0.3f;

	body.setSize({ size.x, 800.f });
	body.setFillColor(sf::Color::Green);
	SetScale({ 1.f,1.f });
	SetRotation(30.f);
	SetPosition({ 0.f , 400.f });

	hitBox.SetType(HitBox::Type::Rectangle);
}

void Block::Release()
{
}

void Block::Reset()
{
	
}

void Block::Update(float dt)
{
	hitBox.UpdateTransform(body, GetLocalBounds());
}

void Block::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	hitBox.Draw(window);
}