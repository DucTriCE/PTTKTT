#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> colors, optimalColoring; 
int minColors;                       // So mau it nhat da su dung

void BackTracking(int k, vector<vector<int>> G, int v) {

    for (int color=0; color<v; color++) {

        if (color > minColors) break;   //Truong hop so mau su dung lon hon so mau it nhat da su dung

        colors[k] = color; 
        bool validColor = true;            

        // Check cac dinh ke cua dinh hien tai co trung voi mau dang xet hay khong
        for (int adj : G[k]) {
            if (colors[adj] == colors[k]) {
                validColor = false;
                break;
            }
        }

        if (validColor) {
            if (k == v - 1) {
                //Tim ra value mau lon nhat su dung
                int maxColor = *max_element(colors.begin(), colors.end());
                //Xet voi value min va chi xet neu nho hon
                if (maxColor < minColors) {
                    minColors = maxColor;
                    optimalColoring = colors;
                }
            } 
            else BackTracking(k+1, G, v); // Move to the next vertex
        }
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int v, e;               
    cin >> v >> e;

    colors.resize(v, -1), optimalColoring.resize(v, -1);        //mang so luong mau toi da su dung se bang so dinh

    vector<vector<int>> G(v);     
    map<string, int> vertexIndex;    

    minColors = v - 1;              //Value cua mau duoc to toi da se bang so dinh tru 1 (Tu 0 den v-1)

    for (int i=0; i<v; i++) {
        string x;
        cin >> x;
        vertexIndex[x] = i;
    }

    for (int j=0; j<e; j++) {
        string u, i;
        cin >> u >> i;
        G[vertexIndex[u]].push_back(vertexIndex[i]);
        G[vertexIndex[i]].push_back(vertexIndex[u]);
    }

    // for(int i=0; i<G.size(); i++){
    //     for(int j=0; j<G[i].size(); j++)cout<<G[i][j]<<" ";
    //     cout << endl;
    // }

    int k=0;
    BackTracking(k, G, v);

    for (int i=0; i<optimalColoring.size(); i++) {
        cout << optimalColoring[i] << " ";
    }
}	
