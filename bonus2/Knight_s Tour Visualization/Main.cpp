#include "SFML/Graphics.hpp"
#include <iostream>
#include<vector>
#include<iomanip>
using namespace std;

#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1080

pair<int, int> board_move[8][8];
vector<pair<int, int>> KnightMoveCoordinates{ {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
int board[8][8];
int board_checkpoint[8][8];
pair<int, int> move_order[64];
bool Done = false;

bool legalMove(int x, int y)
{
	return (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == -1);
}

void Solution(int i, int Knight_x, int Knight_y)
{
	for (int j = 0; j < 8; j++)
	{
		if (Done) break;
		if (legalMove(Knight_x + KnightMoveCoordinates[j].first, Knight_y + KnightMoveCoordinates[j].second))
		{
			board[Knight_x + KnightMoveCoordinates[j].first][Knight_y + KnightMoveCoordinates[j].second] = i;
			move_order[i] = { Knight_x + KnightMoveCoordinates[j].first, Knight_y + KnightMoveCoordinates[j].second };
			if (i == 63)
			{
				Done = true;
			}
			else
				Solution(i + 1, Knight_x + KnightMoveCoordinates[j].first, Knight_y + KnightMoveCoordinates[j].second);
			board[Knight_x + KnightMoveCoordinates[j].first][Knight_y + KnightMoveCoordinates[j].second] = -1;
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Knight Tour");
	sf::Vector2i pos(0, 0);
	window.setPosition(pos);

	//Load texture and sprite for board
	sf::Texture boardtex;
	boardtex.loadFromFile("images/Board.png");
	sf::Sprite boardsprite(boardtex);
	float board_scale = (float)WINDOW_HEIGHT / boardtex.getSize().x;
	boardsprite.setScale(board_scale, board_scale);
	boardsprite.setPosition(0, 0);
	
	//Load texture and sprite for knight
	sf::Texture knighttex;
	knighttex.loadFromFile("images/Knight.png");
	sf::Sprite knightsprite(knighttex);
	float knight_scale = (float)((boardtex.getSize().x * board_scale)/8) / knighttex.getSize().x;
	knightsprite.setScale(knight_scale, knight_scale);

	//Load texture and sprite for X mark
	sf::Texture Xtex;
	Xtex.loadFromFile("images/X.png");
	sf::Sprite Xsprite(Xtex);
	float X_scale = (float)((boardtex.getSize().x * board_scale) / 8) / Xtex.getSize().x;
	Xsprite.setScale(X_scale, X_scale);

	// Initialize the coordinates of each squares in chess board
	float move_pixels = (float)(boardtex.getSize().x * board_scale) / 8;
	float move_x = 0;
	float move_y = 0;
	for (int i = 0; i < 8; i++)
	{
		move_x = 0;
		for (int j = 0; j < 8; j++)
		{
			board_move[i][j] = {move_x, move_y};
			move_x += move_pixels;
		}
		move_y += move_pixels;
	}

	int i;
	sf::Clock clock;
	float time_interval;
	bool wait = true;

	while (window.isOpen())
	{	
		time_interval = clock.getElapsedTime().asSeconds();
		if (!wait)
		{
			if (time_interval > 0.1)
			{
				window.clear();
				//cout << move_order[i].first << " " << move_order[i].second << endl;
				knightsprite.setPosition(board_move[move_order[i].first][move_order[i].second].first, board_move[move_order[i].first][move_order[i].second].second);
				window.draw(boardsprite);
				if (i != 0)
				{
					board_checkpoint[move_order[i - 1].first][move_order[i - 1].second] = 1;
					for (int k = 0; k < 8; k++)
						for (int l = 0; l < 8; l++)
							if (board_checkpoint[k][l] == 1)
							{
								Xsprite.setPosition(board_move[k][l].first, board_move[k][l].second);
								window.draw(Xsprite);
							}
				}
				window.draw(knightsprite);
				if (i < 64)
					i++;
				else
				{
					char check;
					cout << "Thu lai vi tri ban dau khac cho con ma [Y/n]: ";
					cin >> check;
					if (check == 'n')
						window.close();
					else if (check == 'Y')
						wait = true;
				}
				window.display();
				clock.restart();
			}
		}
		if (wait)
		{
			window.clear();
			window.draw(boardsprite);
			window.display();
			cout << "Nhap vi tri cua con ma ban dau: ";
			int x, y;
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					board[i][j] = -1;
			cin >> x >> y;
			board[x][y] = 0;
			i = 0;
			move_order[0] = { x, y };
			Done = false;
			memset(board_checkpoint, -1, sizeof(board_checkpoint[0][0]) * 64);
			Solution(1, x, y);
			cout << "Da tim duoc duong di ngan nhat!" << endl;
			wait = false;
		}
	}
	return 0;
}