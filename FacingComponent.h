#pragma once
#include "ScreenBounder.h"
#include <stdlib.h>
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
		sf::IntRect sp = s->getTextureRect();
		sf::Vector2f p1 = owner->getPos();
		sf::Vector2f p2 = owner->getTarget();

		float grad =  atan2((double)p1.x - p2.x, (double)p1.y - p2.y) * (180/PI);
		
		std::cout << grad << std::endl;

		if (grad < -110 && grad > -130)
		{
			if (s->getTextureRect().width > 0) sp.width = -s->getSize().x;
		}
		if (sp.width < 0) sp.width = -s->getSize().x;

		s->setTextureRect(sp);
	}

	virtual void Render() 
	{
		
	}
};