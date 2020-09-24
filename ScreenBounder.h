#pragma once
#include "KeyboardInputComponent.h"
class ScreenBounder : public BaseComponent
{
public:
	ScreenBounder(Entity* o) : BaseComponent(o)
	{
		
	}

	virtual ~ScreenBounder()
	{

	}

	virtual void Update()
	{
		sf::Vector2u binder = this->owner->getWindow()->getSize();
		sf::Vector2f s = this->owner->getShape()->getSize();

		sf::Vector2f p1 = this->owner->getPos();
		if (p1.x > (binder.x - s.x)) this->owner->setPos(sf::Vector2f(binder.x - s.x, this->owner->getPos().y));
		if (p1.x < 0) this->owner->setPos(sf::Vector2f(0, this->owner->getPos().y));

		p1 = this->owner->getPos();
		if (p1.y > (binder.y - s.y)) this->owner->setPos(sf::Vector2f(this->owner->getPos().x, binder.y - s.y));
		if (p1.y < 0) this->owner->setPos(sf::Vector2f(this->owner->getPos().x, 0));


		//std::cout << (p1.x > binder.x) << (p1.x < 0) << (p1.y > binder.y) << (p1.y < 0) << " | ";
		//std::cout << this->owner->getPos().x << ", " << this->owner->getPos().y << std::endl;
	}

	virtual void Render()
	{

	}
};