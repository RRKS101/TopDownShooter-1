#pragma once
#include "BaseComponent.h"

class Entity 
{
private:
	
protected:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f accel;

	sf::Vector2f max_vel;
	sf::Vector2f max_accel;
	
	sf::Vector2f rate_accel;
	sf::Vector2f rate_decel;

	sf::RectangleShape shape;
	sf::Texture *tex;
	std::string texLabel;

	sf::RenderWindow* Window;

	std::map<std::string, BaseComponent*> components;
	std::map<std::string, sf::Texture*> textures;
	std::map<std::string, sf::Keyboard::Key> kbb;

	sf::Vector2f target;
public:
	Entity() {}
	virtual ~Entity() {}

	
	virtual void setPos(sf::Vector2f n) { this->pos = n; }
	virtual sf::Vector2f getPos() { return this->pos; }

	virtual void setVel(sf::Vector2f n) { this->vel = n; }
	virtual sf::Vector2f getVel() { return this->vel; }

	virtual void setAccel(sf::Vector2f n) { this->accel = n; }
	virtual sf::Vector2f getAccel() { return this->accel; }
	
	virtual void setMaxVel(sf::Vector2f n) { this->max_vel = n; }
	virtual sf::Vector2f getMaxVel() { return this->max_vel; }

	virtual void setMaxAccel(sf::Vector2f n) { this->max_accel = n; }
	virtual sf::Vector2f getMaxAccel() { return this->max_accel; }

	virtual void setRateAccel(sf::Vector2f n) { this->rate_accel = n; }
	virtual sf::Vector2f getRateAccel() { return this->rate_accel; }

	virtual void setRateDecel(sf::Vector2f n) { this->rate_decel = n; }
	virtual sf::Vector2f getRateDecel() { return this->rate_decel; }

	virtual void setTexture(std::string label) { this->tex = this->textures[label]; this->texLabel = label; this->shape.setTexture(this->tex); }
	virtual sf::Texture* getTexture() { return this->tex; }

	virtual void setShape(sf::RectangleShape s) { this->shape = s; }
	virtual sf::RectangleShape* getShape() { return &this->shape; };

	virtual void setWindow(sf::RenderWindow* w) { this->Window = w; }
	virtual sf::Window* getWindow() { return this->Window; }

	virtual void addComponent(std::string label, BaseComponent* comp) { this->components[label] = comp; }
	virtual void removeComponent(std::string label) { this->components.erase(label); }
	virtual BaseComponent* getComponent(std::string label) { return this->components[label]; }

	virtual void setKeybind(std::string action, sf::Keyboard::Key key) { this->kbb[action] = key; }
	virtual std::map<std::string, sf::Keyboard::Key>* getKeybinds() { return &this->kbb; }

	virtual void setTarget(sf::Vector2f n) { this->target = n; }
	virtual sf::Vector2f getTarget() { return this->target; }

	virtual void addTexture(std::string label, sf::Texture &i) 
	{
		sf::Texture *t = new sf::Texture(i);
		this->textures[label] = t;
	}
	virtual std::string getCurrentTextureLabel() { return this->texLabel; }

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
};