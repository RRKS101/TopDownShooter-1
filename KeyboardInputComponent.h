#pragma once
#include "BaseComponent.h"

class KeyboardInputComponent : public BaseComponent
{
private:
	void ApplyFriction()
	{
		owner->setAccel(sf::Vector2f(owner->getAccel().x * owner->getRateDecel().x, owner->getAccel().y * owner->getRateDecel().y));
		owner->setVel(sf::Vector2f(owner->getVel().x * owner->getRateDecel().x, owner->getVel().y * owner->getRateDecel().y));
	}

	void ApplyKeypress()
	{
		for (auto& i : *owner->getKeybinds())
		{
			if (sf::Keyboard::isKeyPressed(i.second))
			{
				if (i.first == "UP") owner->setAccel(owner->getAccel() + sf::Vector2f(0.0f, -owner->getRateAccel().y));
				else if (i.first == "DOWN") owner->setAccel(owner->getAccel() + sf::Vector2f(0.0f, owner->getRateAccel().y));
				else if (i.first == "LEFT") owner->setAccel(owner->getAccel() + sf::Vector2f(-owner->getRateAccel().x, 0.0f));
				else if (i.first == "RIGHT") owner->setAccel(owner->getAccel() + sf::Vector2f(owner->getRateAccel().x, 0.0f));
			}
		}
	}

	void CapSpeed() 
	{
		if (owner->getVel().x > owner->getMaxVel().x) owner->setVel(sf::Vector2f(owner->getMaxVel().x, owner->getVel().y));
		else if (owner->getVel().x < -owner->getMaxVel().x) owner->setVel(sf::Vector2f(-owner->getMaxVel().x, owner->getVel().y));
		if (owner->getVel().y > owner->getMaxVel().y) owner->setVel(sf::Vector2f(owner->getVel().x, owner->getMaxVel().y));
		else if (owner->getVel().y < -owner->getMaxVel().y) owner->setVel(sf::Vector2f(owner->getVel().x, -owner->getMaxVel().y));
	}

public:
	KeyboardInputComponent(Entity* o) : BaseComponent(o) { }

	virtual ~KeyboardInputComponent() {}


	virtual void Update() 
	{
		ApplyFriction();
		ApplyKeypress();
		CapSpeed();
	}

	virtual void Render() 
	{
		
	}
};