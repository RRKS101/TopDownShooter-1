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
	
	virtual void Update(float dt) 
	{
		sf::Vector2f p1 = owner->getPos();
		sf::Vector2f p2 = owner->getTarget();

		p1.x += owner->getShape()->getSize().x / 2;
		p1.y += owner->getShape()->getSize().y / 2;

		float grad = getAngle(p1, p2);

		//std::cout << grad << " | " << p1.x << ", " << p1.y << " | " << p2.x << ", " << p2.y << std::endl;				<<====== DEBUG LINE

		if (grad > 180)
		{
			if (owner->getCurrentTextureLabel() != "FACE_LEFT") this->owner->setTexture("FACE_LEFT");
		}
		else if (grad > 0 && grad < 180)
		{
			if(owner->getCurrentTextureLabel() != "FACE_RIGHT") this->owner->setTexture("FACE_RIGHT");
		}
	}

	virtual void Render() 
	{
		
	}
};