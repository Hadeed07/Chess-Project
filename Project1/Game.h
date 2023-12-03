#pragma once
#include "PiecesMoves.h"
#include "MainMenu.h"
#include <iostream>

class Game : public PiecesMoves, MainMenu
{
public:
	Game();
	~Game();

	void Run();

private:

	void EventHandler(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

	void DrawCheck(sf::RenderWindow& window);		//	Draws the Checks on Kings
	void DrawWins(sf::RenderWindow& window);

	sf::RenderWindow Menu;
	sf::RenderWindow Chess;
	sf::RenderWindow About;

	MainMenu mainmenu;

	std::string str, s1, s2;
	std::string pos = "";

	int movingPiece = 0;		// Stores the value of moving pieces and utilizes in release events

	std::pair<int, int>Pi;		//	Initial Position
	std::pair<int, int>Pf;		//	Final Position

	std::pair<int, int>kingpos;

	bool isMove = false;		//	Regulates the Mouse Interactions

	bool CheckWhite = false;
	bool CheckBlack = false;

	bool turn = White;			// Maintain the turns

	float dx = 0, dy = 0;		//	To store the offset between mouse click and sprite origin

	sf::Sprite mPiece;			//	Draws the sprite of moving piece
	sf::Vector2i mousePos;

	sf::Clock frameClock;								// For controlling the frame rate
	const sf::Time frameTime = sf::seconds(1.0f / 60);   // Target frame time (60 FPS)
	sf::Clock inputClock;
};

