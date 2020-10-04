#pragma once
#include "PlayerModelFacingComponent.h"
class Game 
{
private:
	sf::RenderWindow *Window;
	sf::Event e;

	std::vector<Entity*> entities;
	std::map<std::string, sf::Keyboard::Key> *keybindings;
public:
	Player *p;

	Game() 
	{
		// Initialize Components
		p = new Player();
		Window = new sf::RenderWindow(sf::VideoMode(640, 480), "TopDown Shooter");
		Window->setFramerateLimit(60);

		// Define Player variables
		sf::Texture t;
		t.loadFromFile("./Assets/Player_X.png");

		p->setPos(sf::Vector2f(12, 12));
		
		p->setKeybind("UP", sf::Keyboard::Key::W);
		p->setKeybind("DOWN", sf::Keyboard::Key::S);
		p->setKeybind("LEFT", sf::Keyboard::Key::A);
		p->setKeybind("RIGHT", sf::Keyboard::Key::D);



		p->addComponent("KeybordInput", new KeyboardInputComponent(p));
		p->addComponent("ScreenBounder", new ScreenBounder(p));
		p->addComponent("FaceTarget", new PlayerModelFacingComponent(p));

		//p->addComponent("move_manager", &ApplyMoveComponent(p));

		p->setMaxAccel(sf::Vector2f(5, 5));
		p->setMaxVel(sf::Vector2f(5, 5));
		p->setRateAccel(sf::Vector2f(0.33, 0.33));
		p->setRateDecel(sf::Vector2f(1 / 1.35, 1 / 1.35));

		p->ConfigurePlayer(Window, &t, sf::RectangleShape(sf::Vector2f(25, 50)));
		
		// Push Entities onto vector
		entities.push_back(p);

		// Run main loop
		loop();
	}

	virtual ~Game() 
	{
		
	}

	void loop() 
	{
		while (Window->isOpen()) 
		{
			while (Window->pollEvent(e)) 
			{
				switch (e.type)
				{
				case sf::Event::Closed:
					Window->close();
					break;
				default:
					break;
				}
			}





			for (auto* i : entities) i->Update();

			Window->clear(sf::Color(33, 33, 33));
			for (auto* i : entities) i->Render();
			Window->display();
		}
	}
};