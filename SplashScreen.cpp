#include "stdafx.h"
#include "SplashScreen.h"
#include <windows.h>

void SplashScreen::Show(sf::RenderWindow& renderWindow) {
	sf::Texture image;
	if (image.loadFromFile("images/SplashScreen.png") != true) {

		return;
	}

	sf::Sprite sprite(image);

	/*sprite.setColor(sf::Color(255, 255, 255, 128));
	renderWindow.draw(sprite);
	renderWindow.display();
 */


 // splash screen fade out
	int a = 255;
	while (a > 0)
	{
	//	if (a < 0) { a = 255; }
		sprite.setColor(sf::Color(255, 255, 255, a));
		a--;

		renderWindow.clear(sf::Color::Black);
		renderWindow.draw(sprite);
		renderWindow.display();
		Sleep(10);
	}

	sf::Event event;
	while (true) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed || event.type == sf::Event::EventType::Closed) { 
				return;
			}
		}
	}
}