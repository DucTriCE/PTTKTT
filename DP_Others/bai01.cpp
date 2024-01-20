#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//Reference: https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int v, e, n, maxPainted = 0;
    cin >> v >> e >> n;

    vector<int> colors(v, -1);
    vector<vector<int>> G(v);     
    map<string, int> vertexIndex; 
    vector<int> painted(v);

    for(int i=0; i<v; i++){
        string x;
        cin >> x;
        vertexIndex[x]=i;
    }

    for(int j=0; j<e; j++){
        string u, i;
        cin >> u >> i;
        G[vertexIndex[u]].push_back(vertexIndex[i]);
        G[vertexIndex[i]].push_back(vertexIndex[u]);
    }

    for(int i=0; i<v; i++){
        int x;
        cin >> x;
        painted[i]=x;
    }
    
    for(int i=0; i<n; i++){
        string input;
        cin >> input;
        vector<int> filled(maxPainted + 1, -1); 

        for (int j = 0; j < v; ++j) {
            if (G[vertexIndex[input]][j] == 1 && painted[j] != -1)
                filled[painted[j]] = 1;
            else if (painted[j] != -1)
                filled[painted[j]] = max(filled[painted[j]], 0);
        }

        for (int adjacentVertex : G[i]) {
            //Neu dinh ke do da duoc to mau
            if (colors[adjacentVertex] != -1) {
                //Ta set vi tri mau available tai dinh do thanh true (duoc su dung)
                usedColors[colors[adjacentVertex]] = true;
            }
        }

        if (painted[vertexIndex[input]] != -1 && filled[painted[vertexIndex[input]]] != 1)
            cout << "TRUE" << endl;
        else {
            int color = 0;
            while (color <= maxPainted && filled[color] != -1) color++;
            cout << color << endl;
        }
    }
}