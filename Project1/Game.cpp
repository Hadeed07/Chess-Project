#include "Game.h"

Game::Game() : Menu(sf::VideoMode(940, 450), "Menu")//, Chess(sf::VideoMode(640,640),"My SFML")
{
}

Game::~Game()
{
}

void Game::Run()
{
	MainMenu mainmenu((float)Menu.getSize().x, (float)Menu.getSize().y);
	mainmenu.DrawIcon(Menu);
	while (Menu.isOpen())
	{
		sf::Event event;
		while (Menu.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				Menu.close();
				break;
			}
			case sf::Event::KeyReleased:
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainmenu.MoveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainmenu.MoveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Enter)
				{
					sf::RenderWindow Chess(sf::VideoMode(640, 640), "My Chess");
					sf::RenderWindow About(sf::VideoMode(640, 640), "About");
					int x = mainmenu.MainMenuPressed();

					if (x == 0)
					{
						while (Chess.isOpen())
						{
							mainmenu.DrawIcon(Chess);
							inputClock.restart();
							EventHandler(Chess);
							About.close();
							Render(Chess);
							Menu.close();
						}
						//Chess.close();
						break;
					}
					else if (x == 1)
					{
						while (About.isOpen())
						{
							mainmenu.DrawIcon(About);
							sf::Event Aevent;
							while (About.pollEvent(Aevent))
							{
								if (Aevent.type == sf::Event::Closed)
								{
									About.close();
								}
								if (Aevent.type == sf::Event::KeyPressed)
								{
									if (Aevent.key.code == sf::Keyboard::Escape)
									{
										About.close();
									}
								}
							}
						}
						About.clear();
						//Chess.close();
						About.display();
						break;
					}
					else if (x == 2)
					{
						Menu.close();
						break;
					}
				}
			}
			default:
				break;
			}
		}
		Menu.clear();
		mainmenu.LoadBackgrounds(Menu);
		mainmenu.DrawMainMenu(Menu);
		Menu.display();
	}
}

void Game::DrawCheck(sf::RenderWindow& window)
{
	sf::RectangleShape rect(sf::Vector2f(size, size));
	rect.setFillColor(sf::Color(235, 94, 85, 200));
	if (CheckWhite)
	{
		rect.setPosition(kingpos.first * size, kingpos.second * size);
		window.draw(rect);
	}
	else if (CheckBlack)
	{
		rect.setPosition(kingpos.first * size, kingpos.second * size);
		window.draw(rect);
	}
}

void Game::DrawWins(sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(640, 200));
	rect.setFillColor(sf::Color(204, 204, 204, 204));
	rect.setPosition(0, 200);

	sf::Font font;
	font.loadFromFile("Assets/OpenSans.ttf");
	sf::Text win;
	win.setFont(font);
	win.setPosition(100, 200);
	win.setFillColor(sf::Color(109, 111, 122, 255));
	win.setCharacterSize(70);

	if (CheckMateWhite)
	{
		win.setString("CheckMate\nBlack Wins");
		window.draw(rect);
		window.draw(win);
	}
	else if (CheckMateBlack)
	{
		win.setString("CheckMate\nWhite Wins");
		window.draw(rect);
		window.draw(win);
	}
}

void Game::EventHandler(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		mousePos = sf::Mouse::getPosition(window);
		Pf.first = mousePos.x / size;
		Pf.second = mousePos.y / size;

		switch (event.type)
		{
		case sf::Event::Closed:
		{
			window.close();
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (board[Pf.second][Pf.first] != 0)
				{
					dx = mousePos.x - Pf.first * size;
					dy = mousePos.y - Pf.second * size;

					if (board[Pf.second][Pf.first] == Pawn && turn == White)
					{
						mPiece = white.sPawn;
						movingPiece = Pawn;
						board[Pf.second][Pf.first] = 0;
					}
					if (board[Pf.second][Pf.first] == -Pawn && turn == Black)
					{
						mPiece = black.sPawn;
						movingPiece = -Pawn;
						board[Pf.second][Pf.first] = 0;
					}

					if (board[Pf.second][Pf.first] == Rook && turn == White)
					{
						mPiece = white.sRook;
						movingPiece = Rook;
						board[Pf.second][Pf.first] = 0;
					}
					if (board[Pf.second][Pf.first] == -Rook && turn == Black)
					{
						mPiece = black.sRook;
						movingPiece = -Rook;
						board[Pf.second][Pf.first] = 0;
					}

					if (board[Pf.second][Pf.first] == Bishop && turn == White)
					{
						mPiece = white.sBishop;
						movingPiece = Bishop;
						board[Pf.second][Pf.first] = 0;
					}
					if (board[Pf.second][Pf.first] == -Bishop && turn == Black)
					{
						mPiece = black.sBishop;
						movingPiece = -Bishop;
						board[Pf.second][Pf.first] = 0;
					}

					if (board[Pf.second][Pf.first] == Knight && turn == White)
					{
						mPiece = white.sKnight;
						movingPiece = Knight;
						board[Pf.second][Pf.first] = 0;
					}
					if (board[Pf.second][Pf.first] == -Knight && turn == Black)
					{
						mPiece = black.sKnight;
						movingPiece = -Knight;
						board[Pf.second][Pf.first] = 0;
					}

					if (board[Pf.second][Pf.first] == Queen && turn == White)
					{
						mPiece = white.sQueen;
						movingPiece = Queen;
						board[Pf.second][Pf.first] = 0;
					}
					if (board[Pf.second][Pf.first] == -Queen && turn == Black)
					{
						mPiece = black.sQueen;
						movingPiece = -Queen;
						board[Pf.second][Pf.first] = 0;
					}

					if (board[Pf.second][Pf.first] == King && turn == White)
					{
						mPiece = white.sKing;
						movingPiece = King;
						board[Pf.second][Pf.first] = 0;
					}
					if (board[Pf.second][Pf.first] == -King && turn == Black)
					{
						mPiece = black.sKing;
						movingPiece = -King;
						board[Pf.second][Pf.first] = 0;
					}

					if (board[Pf.second][Pf.first] == 0)
					{
						isMove = true;
						Pi.first = Pf.first;
						Pi.second = Pf.second;
					}
				}
			}
			else if (event.mouseButton.button == sf::Mouse::Right)	//	Unselect the Piece
			{
				isMove = false;
				board[Pi.second][Pi.first] = movingPiece;
			}
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				bool ok = false;
				int color = (movingPiece > 0) ? White : Black;
				ok = SimulateMoves(Pi, Pf, color, movingPiece, mPiece, board);

				if (ok and isMove)
				{
					isMove = false;
					FindCheck(movingPiece, Pi, Pf, kingpos, turn, CheckWhite, CheckBlack);
					CheckMate(color, board, CheckWhite, CheckBlack);
					str = ChessNotes(Pi) + ChessNotes(Pf);
					std::cout << str << std::endl;
					if (Pi != Pf)
					{
						pos += str + " ";
					}
				}
			}
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				str = "d5d7";
				std::pair<int, int>Posi, Posf;
				Posi = Coord(str[0], str[1]);
				Posf = Coord(str[2], str[3]);
				sf::Vector2f oldPos, newPos;
				oldPos.x = Posi.first;		newPos.x = Posf.first;
				oldPos.y = Posi.second;		newPos.y = Posf.second;
				std::cout << Posi.first << " " << Posi.second << std::endl;
				std::cout << str << std::endl;
				if (board[Posi.second][Posi.first] == Pawn)
				{
					mPiece = white.sPawn;
					board[Posi.second][Posi.first] = 0;
					movingPiece = Pawn;
				}
				if (board[Posi.second][Posi.first] == -Pawn)
				{
					mPiece = black.sPawn;
					board[Posi.second][Posi.first] = 0;
					movingPiece = -Pawn;
				}

				if (board[Posi.second][Posi.first] == Rook)
				{
					mPiece = white.sRook;
					board[Posi.second][Posi.first] = 0;
					movingPiece = Rook;
				}
				if (board[Posi.second][Posi.first] == -Rook)
				{
					mPiece = black.sRook;
					board[Posi.second][Posi.first] = 0;
					movingPiece = -Rook;
				}

				if (board[Posi.second][Posi.first] == Bishop)
				{
					mPiece = white.sBishop;
					board[Posi.second][Posi.first] = 0;
					movingPiece = Bishop;
				}
				if (board[Posi.second][Posi.first] == -Bishop)
				{
					mPiece = black.sBishop;
					board[Posi.second][Posi.first] = 0;
					movingPiece = -Bishop;
				}

				if (board[Posi.second][Posi.first] == Knight)
				{
					mPiece = white.sKnight;
					board[Posi.second][Posi.first] = 0;
					movingPiece = Knight;
				}
				if (board[Posi.second][Posi.first] == -Knight)
				{
					mPiece = black.sKnight;
					board[Posi.second][Posi.first] = 0;
					movingPiece = -Knight;
				}

				if (board[Posi.second][Posi.first] == Queen)
				{
					mPiece = white.sQueen;
					board[Posi.second][Posi.first] = 0;
					movingPiece = Queen;
				}
				if (board[Posi.second][Posi.first] == -Queen)
				{
					mPiece = black.sQueen;
					board[Posi.second][Posi.first] = 0;
					movingPiece = -Queen;
				}

				if (board[Posi.second][Posi.first] == King)
				{
					mPiece = white.sKing;
					board[Posi.second][Posi.first] = 0;
					movingPiece = King;
				}
				if (board[Posi.second][Posi.first] == -King)
				{
					mPiece = black.sKing;
					board[Posi.second][Posi.first] = 0;
					movingPiece = -King;
				}

				for (int i = 0; i < 50; i++)
				{
					board[Posf.second][Posf.first] = movingPiece;
					sf::Vector2f p = oldPos - newPos;
					if (board[Posi.second][Posi.first] == 0)
					{
						DrawBoard(window);
						DrawPieces(window);
						window.draw(mPiece);
					}
					mPiece.setPosition(p);
				}
				turn = (turn == White) ? Black : White;
			}
			break;
		}
		default:
			break;
		}
	}
}

void Game::Render(sf::RenderWindow& window)
{
	if (frameClock.getElapsedTime() >= frameTime)
	{
		frameClock.restart();
		window.clear();
		DrawBoard(window);
		DrawPieces(window);
		DrawCoord(window);
		if (isMove)
		{
			mPiece.setPosition(mousePos.x - dx, mousePos.y - dy);
			window.draw(mPiece);
			HighlightSelectedSq(window, Pi, Pf);
			DrawCheck(window);
		}
		DrawWins(window);
		window.display();
	}
}
