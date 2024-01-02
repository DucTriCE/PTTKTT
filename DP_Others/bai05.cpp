#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MOD = 1e9 + 7; 
string map[1001][1001];
int table [1001][1001];
int n;
int DC(int table[][1001], string map[][1001], int x, int y)
{
    if (map[x][y] == "*")
        return 0;
    if (x==n && y==n)
    {
        return table[x][y] = 1;
    }
    if (table[x][y] != -1)
        return table[x][y];
    if (x == n)
        return table[x][y] = DC(table, map, x, y+1) % MOD;
    else if (y == n)
        return table[x][y] = DC(table, map, x+1, y) % MOD;
    else
        return table[x][y] = (DC(table, map, x, y+1) + DC(table, map, x+1, y)) % MOD;
}

int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 1; j <= n; j++)
            map[i][j] = temp[j-1];
    }
    memset(table, -1, sizeof(table));
    cout<<DC(table, map, 1, 1);
}
