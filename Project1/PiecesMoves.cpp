#include "PiecesMoves.h"

PiecesMoves::PiecesMoves()
{
}

PiecesMoves::~PiecesMoves()
{
}

bool PiecesMoves::PawnMoves(std::pair<int, int>Old, std::pair<int, int>New, int color)
{
	int direction = color ? -1 : 1;

	//	First Move Rule
	if ((New.second == Old.second + direction && New.first == Old.first && board[Old.second + direction][Old.first] == None) &&
		((Old.second == 6 && color == 1) || (Old.second == 1 && color == 0)) || (New.second == Old.second + 2 * direction &&
			New.first == Old.first && board[Old.second + direction][Old.first] == 0 && board[Old.second + 2 * direction][Old.first] == None &&
			((Old.second == 6 && color == 1) || (Old.second == 1 && color == 0))))
	{
		if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
		else BlackLegalMoves.push_back({ New.second, New.first });
		return true;
	}

	// Regular Move
	else if (New.second == Old.second + direction && New.first == Old.first && board[Old.second + direction][Old.first] == None)
	{
		if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
		else BlackLegalMoves.push_back({ New.second, New.first });
		return true;
	}

	if (board[Old.second + direction][Old.first - 1] * direction > 0) // Left Diagonal Piece Capture
	{
		if (New.second == Old.second + direction && New.first == Old.first - 1)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}


	if (board[Old.second + direction][Old.first + 1] * direction > 0)		// Right Diagnol Piece Capture
	{
		if (New.second == Old.second + direction && New.first == Old.first + 1)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	return false;
}

bool PiecesMoves::RookMoves(std::pair<int, int>Old, std::pair<int, int>New, int color)
{
	int direction = color ? -1 : 1;

	for (int i = Old.first - 1; i >= 0; i--)		//	Left
	{
		if (board[Old.second][i] * direction >= None && (New.first == i && New.second == Old.second))
		{
			return true;
		}
		if (board[Old.second][i] != None)
		{
			break;
		}
	}
	for (int i = Old.second - 1; i >= 0; i--)		//	Up
	{
		if (board[i][Old.first] * direction >= None && (New.second == i && New.first == Old.first))
		{
			return true;
		}
		else if (board[i][Old.first] != None)
		{
			break;
		}
	}
	for (int i = Old.first + 1; i <= 7; i++)		// Right
	{
		if (board[Old.second][i] * direction >= None && (New.second == Old.second && New.first == i))
		{
			return true;
		}
		if (board[Old.second][i] != None)
		{
			break;
		}
	}
	for (int i = Old.second + 1; i <= 7; i++)		// Down
	{
		if (board[i][Old.first] * direction >= None && (New.second == i && New.first == Old.first))
		{
			return true;
		}
		if (board[i][Old.first] != None)
		{
			break;
		}
	}

	return false;
}

bool PiecesMoves::BishopMoves(std::pair<int, int>Old, std::pair<int, int>New, int color)
{
	int direction = color ? -1 : 1;
	int j;
	// Upper Left
	j = Old.first - 1;
	for (int i = Old.second - 1; i >= 0 && j >= 0; i--)
	{
		if ((New.second == i && New.first == j) && (board[i][j] * direction >= None))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		if (board[i][j] != None)
		{
			break;
		}
		j--;
	}

	// Upper Right
	j = Old.first + 1;
	for (int i = Old.second - 1; i >= 0 && j < 8; i--)
	{
		if ((New.second == i && New.first == j) && (board[i][j] * direction >= None))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		if (board[i][j] != None)
		{
			break;
		}
		j++;
	}

	// Lower Left
	j = Old.first - 1;
	for (int i = Old.second + 1; i < 8 && j >= 0; i++)
	{
		if ((New.second == i && New.first == j) && (board[i][j] * direction >= None))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		if (board[i][j] != None)
		{
			break;
		}
		j--;
	}

	// Lower Right
	j = Old.first + 1;
	for (int i = Old.second + 1; i < 8 && j < 8; i++)
	{
		if ((New.second == i && New.first == j) && (board[i][j] * direction >= None))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		if (board[i][j] != None)
		{
			break;
		}
		j++;
	}

	return false;
}

bool PiecesMoves::KnightMoves(std::pair<int, int>Old, std::pair<int, int>New, int color)
{
	int direction = color ? -1 : 1;

	if (Old.second - 2 >= 0)
	{
		//	1 Upper 2 Left
		if (Old.first - 1 >= 0 and New.second == Old.second - 2 and New.first == Old.first - 1 and board[New.second][New.first] * direction >= 0)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		//	1 Lower 2 Left
		if (Old.first + 1 <= 8 and New.second == Old.second - 2 and New.first == Old.first + 1 and board[New.second][New.first] * direction >= 0)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	if (Old.second - 1 >= 0)
	{
		//	2 Lower 1 Left
		if (Old.first + 2 <= 8 and New.second == Old.second - 1 and New.first == Old.first + 2 and board[New.second][New.first] * direction >= 0)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		//	2 Upper 1 Left
		if (Old.first - 2 >= 0 and New.second == Old.second - 1 and New.first == Old.first - 2 and board[New.second][New.first] * direction >= 0)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	if (Old.second + 1 <= 8)
	{
		//	2 Lower 1 Right
		if (Old.first + 2 <= 8 and New.second == Old.second + 1 and New.first == Old.first + 2 and board[New.second][New.first] * direction >= 0)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		//	2 Upper 1 Right
		if (Old.first - 2 >= 0 and New.second == Old.second + 1 and New.first == Old.first - 2 and board[New.second][New.first] * direction >= 0)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	if (Old.second + 2 <= 8)
	{
		//	1 Upper 2 Right
		if (Old.first - 1 >= 0 and New.second == Old.second + 2 and New.first == Old.first - 1 and board[New.second][New.first] * direction >= 0)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		//	1 Lower 2 Right
		if (Old.first + 1 <= 8 and New.second == Old.second + 2 and New.first == Old.first + 1 and board[New.second][New.first] * direction >= 0)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	return false;
}

bool PiecesMoves::QueenMoves(std::pair<int, int>Old, std::pair<int, int>New, int color)
{
	//	Linear Moves
	int direction = color ? -1 : 1;

	for (int i = Old.first - 1; i >= 0; i--)		//	Left
	{
		if (board[Old.second][i] * direction >= 0 && (New.first == i && New.second == Old.second))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		else if (board[Old.second][i] != None)
		{
			break;
		}
	}
	for (int i = Old.second - 1; i >= 0; i--)		//	Up
	{
		if (board[i][Old.first] * direction >= 0 && (New.second == i && New.first == Old.first))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		else if (board[i][Old.first] != None)
		{
			break;
		}
	}
	for (int i = Old.first + 1; i <= 7; i++)		// Right
	{
		if (board[Old.second][i] * direction >= 0 && (New.second == Old.second && New.first == i))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		else if (board[Old.second][i] != None)
		{
			break;
		}
	}
	for (int i = Old.second + 1; i <= 7; i++)		// Down
	{
		if (board[i][Old.first] * direction >= 0 && (New.second == i && New.first == Old.first))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		else if (board[i][Old.first] != None)
		{
			break;
		}
	}

	//	Diagonal Moves
	int j;

	// Upper Left
	j = Old.first - 1;
	for (int i = Old.second - 1; i >= 0 && j >= 0; i--)
	{
		if ((New.second == i && New.first == j) && (board[i][j] == None || board[i][j] * direction > None))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		if (board[i][j] != None)
		{
			if (board[i][j] * direction > 0 && i == New.second && j == New.first)
			{
				if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
				else BlackLegalMoves.push_back({ New.second, New.first });
				return true;
			}
			break;
		}
		j--;
	}

	// Upper Right
	j = Old.first + 1;
	for (int i = Old.second - 1; i >= 0 && j < 8; i--)
	{
		if ((New.second == i && New.first == j) && (board[i][j] == None || board[i][j] * direction > None))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		if (board[i][j] != None)
		{
			if (board[i][j] * direction > 0 && i == New.second && j == New.first)
			{
				if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
				else BlackLegalMoves.push_back({ New.second, New.first });
				return true;
			}
			break;
		}
		j++;
	}

	// Lower Left
	j = Old.first - 1;
	for (int i = Old.second + 1; i < 8 && j >= 0; i++)
	{
		if ((New.second == i && New.first == j) && (board[i][j] == None || board[i][j] * direction > None))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		if (board[i][j] != None)
		{
			if (board[i][j] * direction > 0 && i == New.second && j == New.first)
			{
				if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
				else BlackLegalMoves.push_back({ New.second, New.first });
				return true;
			}
			break;
		}
		j--;
	}

	// Lower Right
	j = Old.first + 1;
	for (int i = Old.second + 1; i < 8 && j < 8; i++)
	{
		if ((New.second == i && New.first == j) && (board[i][j] == None || board[i][j] * direction > None))
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
		if (board[i][j] != None)
		{
			if (board[i][j] * direction > 0 && i == New.second && j == New.first)
			{
				if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
				else BlackLegalMoves.push_back({ New.second, New.first });
				return true;
			}
			break;
		}
		j++;
	}

	return false;
}

bool PiecesMoves::KingMoves(std::pair<int, int>Old, std::pair<int, int>New, int color)
{
	int direction = color ? -1 : 1;

	//	Up
	if (Old.second + direction <= 8 && New.first == Old.first && New.second == Old.second + direction &&
		(board[New.second][New.first] * direction > 0 || board[New.second][New.first] == None))
	{
		int ok = KingCheck(New, color);
		if (ok == 1)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	//	Down
	if (Old.second - direction >= 0 && New.first == Old.first && New.second == Old.second - direction &&
		(board[New.second][New.first] * direction > 0 || board[New.second][New.first] == None))
	{
		int ok = KingCheck(New, color);		// Check the threat on King
		if (ok == 1)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	//	Right
	if (Old.first + 1 <= 8 && New.first == Old.first + 1 && New.second == Old.second &&
		(board[New.second][New.first] * direction > 0 || board[New.second][New.first] == None))
	{
		int ok = KingCheck(New, color);		// Check the threat on King
		if (ok == 1)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	//	Left
	if (Old.first - 1 >= 0 && New.first == Old.first - 1 && New.second == Old.second &&
		(board[New.second][New.first] * direction > 0 || board[New.second][New.first] == None))
	{
		int ok = KingCheck(New, color);		// Check the threat on King
		if (ok == 1)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	//	Lower Left
	if (Old.first - 1 >= 0 && Old.second - direction >= 0 && New.first == Old.first - 1 && New.second == Old.second - direction
		&& (board[New.second][New.first] * direction > 0 || board[New.second][New.first] == None))
	{
		int ok = KingCheck(New, color);		// Check the threat on King
		if (ok == 1)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	//	Upper Right
	if (Old.first + 1 <= 8 && Old.second + direction <= 8 && New.first == Old.first + 1 && New.second == Old.second + direction
		&& (board[New.second][New.first] * direction > 0 || board[New.second][New.first] == None))
	{
		int ok = KingCheck(New, color);		// Check the threat on King
		if (ok == 1)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	//	Upper Left
	if (Old.first - 1 >= 0 && Old.second + direction <= 8 && New.first == Old.first - 1 && New.second == Old.second + direction
		&& (board[New.second][New.first] * direction > 0 || board[New.second][New.first] == None))
	{
		int ok = KingCheck(New, color);		// Check the threat on King
		if (ok == 1)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}

	//	Lower Right
	if (Old.first + 1 <= 8 && Old.second - direction >= 0 && New.first == Old.first + 1 && New.second == Old.second - direction
		&& (board[New.second][New.first] * direction > 0 || board[New.second][New.first] == None))
	{
		int ok = KingCheck(New, color);		// Check the threat on King
		if (ok == 1)
		{
			if (color == White)WhiteLegalMoves.push_back({ New.second, New.first });
			else BlackLegalMoves.push_back({ New.second, New.first });
			return true;
		}
	}


	//	Right Castle
	int index = color ? 7 : 0;
	if (color == White)		//	For White
	{
		if (rightWhiteRook == true && wKingfirstMove == true && board[index][5] == None
			&& board[index][6] == None && New.second == Old.second && New.first == Old.first + 2)
		{
			int ok = KingCheck({ 4, index }, White);
			if (ok)
			{
				ok = KingCheck({ 5, index }, White);
				if (ok)
				{
					ok = KingCheck({ 6, index }, White);
					if (ok)
					{
						board[index][7] = None;
						board[index][5] = Rook;
						wKingfirstMove = false;
						rightWhiteRook = false;
						return true;
					}
				}
			}
		}
	}
	else	//	For Black
	{
		if (rightBlackRook == true && bKingfirstMove == true && board[index][5] == None
			&& board[index][6] == None && New.second == Old.second && New.first == Old.first + 2)
		{
			int ok = KingCheck({ 4, index }, Black);
			if (ok)
			{
				ok = KingCheck({ 5, index }, Black);
				if (ok)
				{
					ok = KingCheck({ 6, index }, Black);
					if (ok)
					{
						board[index][7] = None;
						board[index][5] = -Rook;
						bKingfirstMove = false;
						rightBlackRook = false;
						return true;
					}
				}
			}
		}
	}

	//	Left Castle
	if (color == White)	//	For White
	{
		if (leftWhiteRook == true && wKingfirstMove == true && board[index][3] == None
			&& board[index][2] == None && board[index][1] == None && New.second == Old.second && New.first == Old.first - 2)
		{
			int ok = KingCheck({ 4, index }, White);
			if (ok)
			{
				ok = KingCheck({ 3, index }, White);
				if (ok)
				{
					ok = KingCheck({ 2, index }, White);
					if (ok)
					{
						ok = KingCheck({ 1, index }, White);
						if (ok)
						{
							board[index][0] = None;
							board[index][3] = Rook;
							wKingfirstMove = false;
							leftWhiteRook = false;
							return true;
						}
					}
				}
			}
		}
	}
	else	//	For Black
	{
		if (leftBlackRook == true && bKingfirstMove == true && board[index][3] == None
			&& board[index][2] == None && board[index][1] == None && New.second == Old.second && New.first == Old.first - 2)
		{
			int ok = KingCheck({ 4, index }, Black);
			if (ok == 1)
			{
				ok = KingCheck({ 3, index }, Black);
				if (ok == 1)
				{
					ok = KingCheck({ 2, index }, Black);
					if (ok == 1)
					{
						ok = KingCheck({ 1, index }, Black);
						if (ok == 1)
						{
							board[index][0] = None;
							board[index][3] = -Rook;
							bKingfirstMove = false;
							leftBlackRook = false;
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}

bool PiecesMoves::KingCheck(std::pair<int, int> king, int color)
{
	int direction = color ? -1 : 1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != None && board[i][j] * direction > 0)
			{
				int ok = 0;
				// Detect Check from opponent's Pawn
				if (board[i][j] == Pawn && color == Black)
				{
					ok = PawnMoves({ j, i }, king, White);
				}
				if (board[i][j] == -Pawn && color == White)
				{
					ok = PawnMoves({ j, i }, king, Black);
				}

				// Detect Check from opponent's Rook
				if (board[i][j] == Rook && color == Black)
				{
					ok = RookMoves({ j, i }, king, White);
				}
				if (board[i][j] == -Rook && color == White)
				{
					ok = RookMoves({ j, i }, king, Black);
				}

				// Detect Check from opponent's Knight
				if (board[i][j] == Knight && color == Black)
				{
					ok = KnightMoves({ j, i }, king, White);
				}
				if (board[i][j] == -Knight && color == White)
				{
					ok = KnightMoves({ j, i }, king, Black);
				}

				// Detect Check from opponent's Bishop
				if (board[i][j] == Bishop && color == Black)
				{
					ok = BishopMoves({ j, i }, king, White);
				}
				if (board[i][j] == -Bishop && color == White)
				{
					ok = BishopMoves({ j, i }, king, Black);
				}

				// Detect Check from opponent's Queen
				if (board[i][j] == Queen && color == Black)
				{
					ok = QueenMoves({ j, i }, king, White);
				}
				if (board[i][j] == -Queen && color == White)
				{
					ok = QueenMoves({ j, i }, king, Black);
				}

				// Detect Check from opponent's King
				if (board[i][j] == King && color == Black)
				{
					ok = KingMoves({ j, i }, king, White);
				}
				if (board[i][j] == -King && color == White)
				{
					ok = KingMoves({ j, i }, king, Black);
				}


				if (ok == 1)
				{
					return false;
				}
			}
		}
	}
	return true;
}

std::pair<int, int> PiecesMoves::KingPos(int color)
{
	int position = color ? -1 : 1;
	std::pair<int, int>kingpos;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == -King * position)
			{
				kingpos.first = j;
				kingpos.second = i;
				break;
			}
		}
	}
	return kingpos;
}

bool PiecesMoves::SimulateMoves(std::pair<int, int>& Pi, std::pair<int, int>& Pf, int color,
	int& movingPiece, sf::Sprite& sprite, int Board[][8])
{
	bool ok = false;
	switch (abs(movingPiece))
	{
	case Pawn:
	{
		if (PawnMoves(Pi, Pf, color))
		{
			if ((color == White && Pf.second == 0) || (color == Black && Pf.second == 7))
			{
				// Pawn promotion to queen i.e Queening
				movingPiece = (color == White) ? Queen : -Queen;
				sprite = (color == White) ? white.sQueen : black.sQueen;
			}
			return true;
		}
		break;
	}

	case Rook:
	{
		if (RookMoves(Pi, Pf, color))
		{
			if (color == White && ((rightWhiteRook && Pi.first == 7 && Pi.second == 7) ||
				(leftWhiteRook && Pi.first == 7 && Pi.second == 0)))
			{
				rightWhiteRook = false;
				leftWhiteRook = false;
			}
			else if (color == Black && ((leftBlackRook && Pi.first == 0 && Pi.second == 0) ||
				(rightBlackRook && Pi.first == 7 && Pi.second == 0)))
			{
				leftBlackRook = false;
				rightBlackRook = false;
			}
			return true;
		}
		break;
	}

	case Bishop:
	{
		if (BishopMoves(Pi, Pf, color))
		{
			return true;
		}
		break;
	}
	case Knight:
	{
		if (KnightMoves(Pi, Pf, color))
		{
			return true;
		}
		break;
	}
	case Queen:
	{
		if (QueenMoves(Pi, Pf, color))
		{
			return true;
		}
		break;
	}
	case King:
	{
		if (KingMoves(Pi, Pf, color))
		{
			//wKingfirstMove = bKingfirstMove = true;
			if ((color == White && wKingfirstMove) || (color == Black && bKingfirstMove))
			{
				// Mark the king's first move
				if (color == White) wKingfirstMove = false;
				else bKingfirstMove = false;
			}
			return true;
		}
		break;
	}
	default:
		break;
	}

	return false;
}

void PiecesMoves::FindCheck(int movingPiece, std::pair<int, int> Pi, std::pair<int, int> Pf,
	std::pair<int, int>& kingpos, bool& turn, bool& CheckWhite, bool& CheckBlack)
{
	int originalPiece = board[Pi.second][Pi.first];
	board[Pf.second][Pf.first] = movingPiece;

	if (turn == White)	// Alternate the Turns
	{
		if (CheckWhite == true)
		{
			//	If white move still results in its check, Piece moves back
			kingpos = KingPos(White);
			int s = KingCheck(kingpos, White);
			if (s == 0)
			{
				board[Pi.second][Pi.first] = movingPiece;
				board[Pf.second][Pf.first] = originalPiece;
				for (auto it = WhiteLegalMoves.begin(); it != WhiteLegalMoves.end(); ++it)
				{
					if (*it == std::make_pair(Pf.second, Pi.first))
					{
						WhiteLegalMoves.erase(it);
						break; // Exit the loop after erasing the element
					}
				}
			}
			else
			{
				//	White move results in Black Check
				CheckWhite = false;
				kingpos = KingPos(Black);
				int check = KingCheck(kingpos, Black);
				if (check == 0)
				{
					CheckBlack = true;
					printf(" Black Check\n");
				}
				turn = Black;
			}
		}
		else
		{
			//	If white moves results in its check, piece moves back
			kingpos = KingPos(White);
			int sa = KingCheck(kingpos, White);
			if (sa == 0)
			{
				board[Pi.second][Pi.first] = movingPiece;
				board[Pf.second][Pf.first] = originalPiece;
				for (auto it = WhiteLegalMoves.begin(); it != WhiteLegalMoves.end(); ++it)
				{
					if (*it == std::make_pair(Pf.second, Pi.first))
					{
						WhiteLegalMoves.erase(it);
						break; // Exit the loop after erasing the element
					}
				}
			}
			else
			{
				//	White move results in Black Check
				kingpos = KingPos(Black);
				int check = KingCheck(kingpos, Black);
				if (check == 0)
				{
					CheckBlack = true;
					printf(" Black Check\n");
				}
				turn = Black;
			}
		}
	}

	else
	{
		if (CheckBlack == true)
		{
			//	If black move still results in its Check, Piece moves back
			kingpos = KingPos(Black);
			int s = KingCheck(kingpos, Black);
			if (s == 0)
			{
				board[Pi.second][Pi.first] = movingPiece;
				board[Pf.second][Pf.first] = originalPiece;
				for (auto it = BlackLegalMoves.begin(); it != BlackLegalMoves.end(); ++it)
				{
					if (*it == std::make_pair(Pf.second, Pi.first))
					{
						BlackLegalMoves.erase(it);
						break; // Exit the loop after erasing the element
					}
				}
			}
			else
			{
				//	Black moves results in White Check
				CheckBlack = false;
				kingpos = KingPos(White);
				int check = KingCheck(kingpos, White);
				if (check == 0)
				{
					CheckWhite = true;
					printf(" White Check\n");
				}
				turn = White;
			}
		}
		else
		{
			//	If black move results in its Check, Piece moves back to initial Position
			kingpos = KingPos(Black);
			int sa = KingCheck(kingpos, Black);
			if (sa == 0)
			{
				board[Pi.second][Pi.first] = movingPiece;
				board[Pf.second][Pf.first] = originalPiece;
				for (auto it = BlackLegalMoves.begin(); it != BlackLegalMoves.end(); ++it)
				{
					if (*it == std::make_pair(Pf.second, Pi.first))
					{
						BlackLegalMoves.erase(it);
						break; // Exit the loop after erasing the element
					}
				}
			}
			else
			{
				//	Black Move results in White Check
				kingpos = KingPos(White);
				int check = KingCheck(kingpos, White);
				if (check == 0)
				{
					CheckWhite = true;
					printf(" White Check\n");
				}
				turn = White;
			}
		}
	}
}

bool PiecesMoves::CheckMate(int color, int Board[][8], bool wcheck, bool bcheck)
{
	int check = 0;

	int piececolor = (color == White) ? Black : White;
	int tempboard[8][8];

	std::pair<int, int> king;
	if (wcheck) king = KingPos(White);
	else if (bcheck) king = KingPos(Black);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tempboard[i][j] = Board[i][j];
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::pair<int, int>src(j, i);
			if (tempboard[j][i] == None) continue;

			int piece = tempboard[j][i];

			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					std::pair<int, int>dest(y, x);
					sf::Sprite sprite;

					if (wcheck && piece > 0)
					{
						if (SimulateMoves(src, dest, White, piece, sprite, tempboard))
						{
							tempboard[src.second][src.first] = 0;
							tempboard[dest.second][dest.first] = piece;

							std::pair<int, int>kingcopy = king;
							bool inCheck = KingCheck(kingcopy, White);
							if (!inCheck)
							{
								check++;
								tempboard[dest.second][dest.first] = 0;
								piece = tempboard[src.second][src.first];
								return true;
							}
						}
					}
					else if (bcheck && piece < 0)
					{
						if (SimulateMoves(src, dest, Black, piece, sprite, tempboard))
						{
							int srcPiece = tempboard[src.second][src.first];
							int destPiece = tempboard[dest.second][dest.first];

							tempboard[src.second][src.first] = None;
							tempboard[dest.second][dest.first] = piece;

							check++;

							std::pair<int, int>kingcopy = king;
							bool inCheck = KingCheck(kingcopy, Black);

							tempboard[src.second][src.first] = srcPiece;
							tempboard[dest.second][dest.first] = destPiece;

							if (!inCheck)
							{
								tempboard[src.second][src.first] = piece;
								tempboard[dest.second][dest.first] = None;
								return true;
							}
						}
					}
				}
			}

		}
	}
	return false;
}

std::string PiecesMoves::ChessNotes(std::pair<int, int> Pos)
{
	std::string s = " ";
	s += char(Pos.first + 'a');
	s += char(7 - Pos.second + '1');
	return s;
}

std::pair<int, int> PiecesMoves::Coord(char a, char b)
{
	int x = static_cast<int>(a) - 97;
	int y = 7 - (static_cast<int>(b) - 49);

	return std::pair<int, int>(x, y);
}

