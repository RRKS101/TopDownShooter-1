#pragma once
#include "BaseGun.h"
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

		p->setPos(sf::Vector2f(12, 12));
		// Configure Keybinds
		p->setKeybind("UP", sf::Keyboard::Key::W);
		p->setKeybind("DOWN", sf::Keyboard::Key::S);
		p->setKeybind("LEFT", sf::Keyboard::Key::A);
		p->setKeybind("RIGHT", sf::Keyboard::Key::D);
		// Add Components
		p->addComponent("KeybordInput", new KeyboardInputComponent(p));
		p->addComponent("ScreenBounder", new ScreenBounder(p));
		p->addComponent("ModelFaceTarget", new PlayerModelFacingComponent(p));

		// Configure Movement rates
		p->setMaxAccel(sf::Vector2f(1800, 1800));
		p->setMaxVel(sf::Vector2f(3600, 3600));
		p->setRateAccel(sf::Vector2f(1400, 1400));
		p->setRateDecel(sf::Vector2f(1 / 1.35, 1 / 1.35));

		// Load Player Textures
		sf::Texture *t = new sf::Texture[2];

		t[0].loadFromFile("./Assets/Images/Player_X.png");
		
		sf::Image i = t[0].copyToImage();
		i.flipHorizontally();
		t[1].loadFromImage(i);

		p->addTexture("FACE_RIGHT", t[0]);
		p->addTexture("FACE_LEFT", t[1]);
		
		p->ConfigurePlayer(Window, &t[0], sf::RectangleShape(sf::Vector2f(25, 50)));
		delete[] t;

		// Push Entities onto vector
		entities.push_back(p); // Push player instance onto vector
		

		// Run main loop
		loop();

		
	}

	virtual ~Game() 
	{
		
	}

	void loop() 
	{
		sf::Clock dtCLK;
		float dt;

		while (Window->isOpen()) 
		{
			dt = (float)dtCLK.restart().asMilliseconds()/1000.0f;

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




			for (auto* i : entities) i->Update(dt);

			Window->clear(sf::Color(33, 33, 33));
			for (auto* i : entities) i->Render();
			Window->display();
		}
	}
};