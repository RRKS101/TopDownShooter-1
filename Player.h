#pragma once
#include "Entity.h"

class Player : public Entity
{
protected:
	void UpdateComponents(float dt) 
	{ 
		for (auto i : this->components) 
		{
			i.second->Update(dt);
		} 
	}

	void RenderComponents() { for (auto i : this->components) i.second->Render(); }

public:
	Player() 
	{

		this->pos = sf::Vector2f(0, 0);
		this->vel = sf::Vector2f(0, 0);
		this->accel = sf::Vector2f(0, 0);
	}

	~Player() 
	{
	
	}
	
	virtual void Update(float dt) 
	{
		this->setTarget((sf::Vector2f)sf::Mouse::getPosition(*this->Window));

		setVel(getVel() + getAccel() * dt);
		setPos(getPos() + getVel() * dt);

		UpdateComponents(dt);

		
		this->shape.setPosition(this->getPos());
	}

	virtual void Render() 
	{
		this->Window->draw(this->shape);
		RenderComponents();
	}


	void ConfigurePlayer(sf::RenderWindow* w, sf::Texture* t, sf::RectangleShape s)
	{
		this->Window = w;
		this->tex = t;
		this->shape = s;

		this->shape.setTexture(this->tex);
	}

	
};