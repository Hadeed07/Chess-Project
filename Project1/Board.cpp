#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::DrawBoard(sf::RenderWindow& window)
{
	//	Draw Blank Chess Board
	sf::RectangleShape rect(sf::Vector2f(80.0f, 80.0f));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tileID = (i + j) % 2 != 0;
			if (tileID == 0)
			{
				rect.setFillColor(sf::Color(113, 148, 170, 255));		//	Dark Squares
			}
			else
			{
				rect.setFillColor(sf::Color(202, 215, 223, 255));		//	Light Squares
			}
			rect.setPosition((float)i * size, (float)j * size);
			window.draw(rect);
		}
	}
}

void Board::DrawPieces(sf::RenderWindow& window)
{
	LoadPieces();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (board[j][i])
			{
				//	Pawn
			case Pawn:
			{
				white.pawn.setSmooth(true);
				white.sPawn.setTexture(white.pawn);
				white.sPawn.setPosition((float)i * size, (float)j * size);
				white.sPawn.setScale(0.32f, 0.32f);
				window.draw(white.sPawn);
				break;
			}
			case -Pawn:
			{
				black.pawn.setSmooth(true);
				black.sPawn.setTexture(black.pawn);
				black.sPawn.setPosition((float)i * size, (float)j * size);
				black.sPawn.setScale(0.32f, 0.32f);
				window.draw(black.sPawn);
				break;
			}

			//	Rook
			case Rook:
			{
				white.rook.setSmooth(true);
				white.sRook.setTexture(white.rook);
				white.sRook.setPosition((float)i * size, (float)j * size);
				white.sRook.setScale(0.32f, 0.32f);
				window.draw(white.sRook);
				break;
			}
			case -Rook:
			{
				black.rook.setSmooth(true);
				black.sRook.setTexture(black.rook);
				black.sRook.setPosition((float)i * size, (float)j * size);
				black.sRook.setScale(0.32f, 0.32f);
				window.draw(black.sRook);
				break;
			}

			//	Knight
			case Knight:
			{
				white.knight.setSmooth(true);
				white.sKnight.setTexture(white.knight);
				white.sKnight.setPosition((float)i * size, (float)j * size);
				white.sKnight.setScale(0.32f, 0.32f);
				window.draw(white.sKnight);
				break;
			}
			case -Knight:
			{
				black.knight.setSmooth(true);
				black.sKnight.setTexture(black.knight);
				black.sKnight.setPosition((float)i * size, (float)j * size);
				black.sKnight.setScale(0.32f, 0.32f);
				window.draw(black.sKnight);
				break;
			}

			//	Bishop
			case Bishop:
			{
				white.bishop.setSmooth(true);
				white.sBishop.setTexture(white.bishop);
				white.sBishop.setPosition((float)i * size, (float)j * size);
				white.sBishop.setScale(0.32f, 0.32f);
				window.draw(white.sBishop);
				break;
			}
			case -Bishop:
			{
				black.bishop.setSmooth(true);
				black.sBishop.setTexture(black.bishop);
				black.sBishop.setPosition((float)i * size, (float)j * size);
				black.sBishop.setScale(0.32f, 0.32f);
				window.draw(black.sBishop);
				break;
			}

			//	Queen
			case Queen:
			{
				white.queen.setSmooth(true);
				white.sQueen.setTexture(white.queen);
				white.sQueen.setPosition((float)i * size, (float)j * size);
				white.sQueen.setScale(0.32f, 0.32f);
				window.draw(white.sQueen);
				break;
			}
			case -Queen:
			{
				black.queen.setSmooth(true);
				black.sQueen.setTexture(black.queen);
				black.sQueen.setPosition((float)i * size, (float)j * size);
				black.sQueen.setScale(0.32f, 0.32f);
				window.draw(black.sQueen);
				break;
			}

			// King
			case King:
			{
				white.king.setSmooth(true);
				white.sKing.setTexture(white.king);
				white.sKing.setPosition((float)i * size, (float)j * size);
				white.sKing.setScale(0.32f, 0.32f);
				window.draw(white.sKing);
				break;
			}
			case -King:
			{
				black.king.setSmooth(true);
				black.sKing.setTexture(black.king);
				black.sKing.setPosition((float)i * size, (float)j * size);
				black.sKing.setScale(0.32f, 0.32f);
				window.draw(black.sKing);
				break;
			}
			default:
				break;
			}

		}
	}
}

void Board::HighlightSelectedSq(sf::RenderWindow& window, std::pair<int, int> Si, std::pair<int, int> Sf)
{
	if (board[Si.second][Si.first] == 0)
	{
		sf::RectangleShape initial(sf::Vector2f(size, size));
		sf::RectangleShape final(sf::Vector2f(size, size));

		initial.setFillColor(sf::Color(137, 187, 254, 100));
		final.setFillColor(sf::Color(137, 187, 254, 100));

		initial.setOutlineThickness(2.5);
		final.setOutlineThickness(2.5);

		initial.setOutlineColor(sf::Color(137, 187, 254));
		final.setOutlineColor(sf::Color(137, 187, 254));

		initial.setPosition(Si.first * size, Si.second * size);
		final.setPosition(Sf.first * size, Sf.second * size);

		window.draw(initial);
		window.draw(final);
	}
}

void Board::DrawCoord(sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	coord.loadFromFile("Assets/OpenSans.ttf");
	Coord.setCharacterSize(16);
	Coord.setFont(coord);

	for (int i = 0; i < 8; i++)
	{
		std::string s[8] = { "a","b","c","d","e","f","g","h" };
		Coord.setPosition((80 * i) + 68, 620);
		Coord.setString(s[i]);
		if (i % 2 == 0)
		{
			Coord.setFillColor(sf::Color(113, 148, 170, 255));
		}
		else
		{
			Coord.setFillColor(sf::Color(202, 215, 223, 255));
		}
		window.draw(Coord);
	}

	for (int j = 0; j < 8; j++)
	{
		std::string s[8] = { "1","2","3","4","5","6","7","8" };
		Coord.setPosition(8, 80 * j);
		Coord.setString(s[j]);
		if (j % 2 != 0)
		{
			Coord.setFillColor(sf::Color(113, 148, 170, 255));
		}
		else
		{
			Coord.setFillColor(sf::Color(202, 215, 223, 255));
		}
		window.draw(Coord);
	}

}

void Board::LoadPieces()
{
	//	Pawn
	white.pawn.loadFromFile("Assets/Pawn-8.png");
	black.pawn.loadFromFile("Assets/Pawn-16.png");

	//	Bishop
	white.bishop.loadFromFile("Assets/Bishop-8.png");
	black.bishop.loadFromFile("Assets/Bishop-16.png");

	//	Knight
	white.knight.loadFromFile("Assets/Knight-8.png");
	black.knight.loadFromFile("Assets/Knight-16.png");

	//	Rook
	white.rook.loadFromFile("Assets/Rook-8.png");
	black.rook.loadFromFile("Assets/Rook-16.png");

	//	Queen
	white.queen.loadFromFile("Assets/Queen-8.png");
	black.queen.loadFromFile("Assets/Queen-16.png");

	//	King
	white.king.loadFromFile("Assets/King-8.png");
	black.king.loadFromFile("Assets/King-16.png");
}
