#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<string, set<string>> Graph;
map<string, int> vertex_index;
vector<int> color;
int v, e, n;

void output() {
    for (int i=0; i< color.size(); i++)cout << color[i]<< " ";
}

bool valid(int k){
    
}

//bien j cua no la bien k cua minh
//bien k la so mau
//bien n la 
void BackTracking(int k){
    if(k==v-1){
        output();
        return;
    }
    for(int i=0; i<16777215; i++){
        color[k]=i;
        if(valid(k))
    }
}

int main() {    
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    cin >> v >> e;
    for(int i=0; i<v; i++){
        string x;
        cin >> x;
        vertex_index[x] = i;
    }
    color.resize(v);
    for(int j=0;j<e; j++){
        string u, i;
        cin >> u >> i;
        Graph[u].insert(i);
        Graph[i].insert(u);
    }
    BackTracking(0);
}