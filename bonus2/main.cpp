#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> KnightMoveCoordinates{{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};


int board[8][8];

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
            board[Knight_x+KnightMoveCoordinates[j].first][Knight_y+KnightMoveCoordinates[j].second] = i;
            if (i == 63)
            {
                Done = true;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                        cout<<setw(2)<<board[i][j]<<" ";
                    cout<<endl;
                }
            }
            else
                Solution(i+1, Knight_x+KnightMoveCoordinates[j].first, Knight_y+KnightMoveCoordinates[j].second);
            board[Knight_x+KnightMoveCoordinates[j].first][Knight_y+KnightMoveCoordinates[j].second] = -1;
        }
    }
}

int main()
{
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = -1;
    board[x][y] = 0;
    Solution(1, x, y);
}