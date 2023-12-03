#pragma once
#include "Board.h"
#include <iostream>

class PiecesMoves : public Board
{
public:

	PiecesMoves();
	~PiecesMoves();

	bool PawnMoves(std::pair<int, int>Old, std::pair<int, int>New, int color);

	bool RookMoves(std::pair<int, int>Old, std::pair<int, int>New, int color);

	bool BishopMoves(std::pair<int, int>Old, std::pair<int, int>New, int color);

	bool KnightMoves(std::pair<int, int>Old, std::pair<int, int>New, int color);

	bool QueenMoves(std::pair<int, int>Old, std::pair<int, int>New, int color);

	bool KingMoves(std::pair<int, int>Old, std::pair<int, int>New, int color);

	bool KingCheck(std::pair<int, int> king, int color);	//	Respond to Check

	std::pair<int, int> KingPos(int color);	//	Detect King Position throughout the Board

	bool SimulateMoves(std::pair<int, int>& Pi, std::pair<int, int>& Pf, int color,
		int& movingPiece, sf::Sprite& sprite, int Board[][8]);	//	To Simulate all the moves

	void FindCheck(int movingPiece, std::pair<int, int>Pi, std::pair<int, int>Pf,	// Detect Check
		std::pair<int, int>& kingpos, bool& turn, bool& CheckWhite, bool& CheckBlack);

	bool CheckMate(int color, int Board[][8], bool wcheck, bool bcheck);	//	Detect Checkmate

	std::string ChessNotes(std::pair<int, int>Pos);	//	Conversion to Chess Notations

	std::pair<int, int>Coord(char a, char b);	//	Conversion to Board Coordinations

protected:

	std::vector<std::pair<int, int>> WhiteLegalMoves;
	std::vector<std::pair<int, int>> BlackLegalMoves;

	bool rightWhiteRook = true;
	bool rightBlackRook = true;

	bool wKingfirstMove = true;
	bool bKingfirstMove = true;

	bool leftWhiteRook = true;
	bool leftBlackRook = true;

	bool CheckMateWhite = false;
	bool CheckMateBlack = false;
};

