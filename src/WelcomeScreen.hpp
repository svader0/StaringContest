#ifndef WELCOME_SCREEN_H
#define WELCOME_SCREEN_H
#include <SFML/Graphics.hpp>

class WelcomeScreen 
{
private:
	const char * filePath = "res\\welcomeScreen.png";

	sf::RenderWindow m_window;
	sf::Event m_event;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	WelcomeScreen()
	{
		m_window.create(sf::VideoMode(800, 800), "Startup Screen");
		m_texture.loadFromFile(filePath);
		m_sprite.setTexture(m_texture);
	}

	void display() 
	{
		while (m_window.isOpen()) 
		{
			m_window.clear();
			m_window.draw(m_sprite);
			m_window.display();
			while (m_window.pollEvent(m_event))
			{
				if (m_event.type == sf::Event::Closed)
					m_window.close();

				if (m_event.type == sf::Event::KeyPressed)
					m_window.close();
			}
		}
	}
};

#endif