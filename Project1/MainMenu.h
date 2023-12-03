#pragma once
#include <SFML/Graphics.hpp>

class MainMenu
{
public:

	MainMenu();
	MainMenu(float width, float height);
	~MainMenu();

	int MainMenuPressed();
	void LoadBackgrounds(sf::RenderWindow& window);
	void DrawMainMenu(sf::RenderWindow& window);
	void DrawIcon(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

private:

	int MainMenuSelected;

	sf::RectangleShape MenuBackground;
	sf::RectangleShape AboutBackground;

	sf::Font font;
	sf::Text mainMenu[3];
};

