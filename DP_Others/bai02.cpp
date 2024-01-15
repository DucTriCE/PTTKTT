#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Reference: https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int v, e;
    cin >> v >> e;

    vector<int> colors(v, -1);
    vector<vector<int>> G(v);     
    map<string, int> vertexIndex; 

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

    colors[0] = 0;          //Mau dau tien luon bat dau la 0
    vector<bool> usedColors(v, false);     //Tao ra mot mang gom v mau (do chi su dung toi da v mau) cua mot dinh dang xet, neu mau chua duoc su dung thi = false

    for (int i = 1; i < v; i++) {

        //Duyet cac dinh ke cua dinh dang xet
        for (int adjacentVertex : G[i]) {
            //Neu dinh ke do da duoc to mau
            if (colors[adjacentVertex] != -1) {
                //Ta set vi tri mau available tai dinh do thanh true (duoc su dung)
                usedColors[colors[adjacentVertex]] = true;
            }
        }

        // Tim ra mau dau tien hop le
        int color;
        for (color = 0; color < v; color++) {
            //Neu mau tai do = false, tuc la mau dau tien chua duoc su dung tai bat ki dinh nao
            if (usedColors[color]==false) break;
        }
        //Khi tim ra duoc value mau color, ta gan no vao mang ket qua
        colors[i] = color;

        //Khi qua mot dinh moi thi ta can reset lai mang usedColors de chuan bi xet dinh moi
        for (int adjacentVertex : G[i]) {
            if (colors[adjacentVertex] != -1) {
                usedColors[colors[adjacentVertex]] = false;
            }
        }
    }

    // Output the colors of the vertices
    for (int i=0; i<colors.size(); i++) {
        cout << colors[i] << " ";
    }
}