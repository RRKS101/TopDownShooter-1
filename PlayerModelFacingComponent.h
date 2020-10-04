#include "BaseFacingComponent.h"

class PlayerModelFacingComponent : public BaseFacingComponent
{
private:

public:
	PlayerModelFacingComponent(Entity* o) : BaseFacingComponent(o)
	{
	
	}

	virtual ~PlayerModelFacingComponent() 
	{
	
	}
	
	virtual void Update() 
	{
		sf::RectangleShape* s = owner->getShape();
		sf::IntRect sp = s->getTextureRect();
		sf::Vector2f p1 = owner->getPos();
		sf::Vector2f p2 = owner->getTarget();

		p1.x += s->getSize().x / 2;
		p1.y += s->getSize().y / 2;

		float grad = getAngle(p1, p2);


#ifdef FACING_COMPONENT_DEBUG
		std::cout << grad << " | " << p1.x << ", " << p1.y << " | " << p2.x << ", " << p2.y << std::endl;
#endif


		if (grad < 0.08f)
		{
			if (s->getTextureRect().width > 0) sp.width = -s->getSize().x;
		}
		else if (grad > 0.08f)
		{
			if (s->getTextureRect().width <= 0) sp.width = -s->getSize().x;
		}


		s->setTextureRect(sp);
	}

	virtual void Render() 
	{
		
	}
};