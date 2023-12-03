#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::MainMenu(float width, float height)
{
	font.loadFromFile("Assets/OpenSans.ttf");

	//	Play
	mainMenu[0].setString("Play");
	mainMenu[0].setPosition(170, 120);

	//	About
	mainMenu[1].setString("About");
	mainMenu[1].setPosition(170, 200);

	//	Exit
	mainMenu[2].setString("Exit");
	mainMenu[2].setPosition(170, 280);

	for (int i = 0; i < 3; i++)
	{
		mainMenu[i].setFont(font);
		mainMenu[i].setFillColor(sf::Color(36, 38, 33, 255));
		mainMenu[i].setOutlineColor(sf::Color(89, 160, 198, 255));
		mainMenu[i].setOutlineThickness(2.5);
		mainMenu[i].setCharacterSize(70);
	}

	MainMenuSelected = -1;
}

MainMenu::~MainMenu()
{
}

int MainMenu::MainMenuPressed()
{
	return MainMenuSelected;
}

void MainMenu::LoadBackgrounds(sf::RenderWindow& window)
{
	//MainMenu();
	MenuBackground.setSize(sf::Vector2f(940.0f, 450.0f));
	sf::Texture tex1;
	tex1.loadFromFile("Assets/Menu.png");
	MenuBackground.setTexture(&tex1);
	window.draw(MenuBackground);
}

void MainMenu::DrawMainMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu[i]);
	}
}

void MainMenu::DrawIcon(sf::RenderWindow& window)
{
	sf::Image icon;
	icon.loadFromFile("Assets/Icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color(36, 38, 33, 255));
		MainMenuSelected--;

		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 1;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color(89, 160, 198, 255));
		mainMenu[MainMenuSelected].setOutlineColor(sf::Color(166, 200, 224, 255));
	}
}

void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= 2)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color(36, 38, 33, 255));
		MainMenuSelected++;

		if (MainMenuSelected == 3)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color(89, 160, 198, 255));
		mainMenu[MainMenuSelected].setOutlineColor(sf::Color(166, 200, 224, 255));
	}
}
