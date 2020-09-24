#pragma once
#include "ScreenBounder.h"

class FacingComponent : public BaseComponent
{
private:

public:
	FacingComponent(Entity* o) : BaseComponent(o) 
	{
		
	}

	virtual ~FacingComponent() 
	{
		
	}

	virtual void Update() 
	{
		sf::RectangleShape* s = owner->getShape();
		sf::Vector2f p1 = owner->getPos();
		sf::Vector2f p2 = owner->getTarget();

		float grad = atan((p2.y - p1.y) / (p2.x - p1.x))*(180/PI);
		// Gotta 

		if (grad > 25.6 && grad < 31.0)
		{
			// Negative Scale
			if(s->getScale().x < 0) s->setScale(s->getScale());
			else s->setScale(-s->getScale().x, s->getScale().y);
		}
		else 
		{
			// Positive Scale
			if(s->getScale().x > 0) s->setScale(s->getScale());
			else s->setScale(-s->getScale().x, s->getScale().y);
		}
		
	}

	virtual void Render() 
	{
		
	}
};