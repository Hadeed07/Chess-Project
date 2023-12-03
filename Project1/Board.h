#pragma once
#include <SFML/Graphics.hpp>

class Board
{
public:
	Board();
	~Board();

	void DrawBoard(sf::RenderWindow& window);
	void DrawPieces(sf::RenderWindow& window);

	//	Draws the Selected Squares
	void HighlightSelectedSq(sf::RenderWindow& window, std::pair<int, int>Si, std::pair<int, int>Sf);
	void DrawCoord(sf::RenderWindow& window);

protected:

	void LoadPieces();		// Sets the initial position of Pieces

	enum Pieces
	{
		None, Pawn, Rook, Knight, Bishop, Queen, King
	};

	enum color
	{
		Black, White
	};

	struct pieces
	{
		sf::Texture pawn, rook, knight, bishop, queen, king;
		sf::Sprite sPawn, sRook, sKnight, sBishop, sQueen, sKing;

	}white, black;

	float size = 80;	// Size of Squares

	sf::Font coord;
	sf::Text Coord;

	bool tileID;	//	Determine which square is to be light or dark

	// Initial Board Layout
	int board[8][8] =
	{
		{-2,-3,-4,-5,-6,-4,-3,-2},
		{-1,-1,-1,-1,-1,-1,-1,-1},
		{0 ,0 ,0 ,0 ,0 ,0 ,0 , 0},
		{0 ,0 ,0 ,0, 0 ,0 ,0 , 0},
		{0 ,0 ,0 ,0, 0 ,0 ,0 , 0},
		{0 ,0 ,0 ,0, 0 ,0 ,0 , 0},
		{1 ,1 ,1 ,1 ,1 ,1 ,1 , 1},
		{2, 3, 4, 5, 6, 4, 3 , 2},
	};

};

