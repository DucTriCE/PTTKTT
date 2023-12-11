#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> v;
map<string, map<string, int>> G;

void backtracking(int k){
    for()
}

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int e;
    string s;
    cin >> e >> s;
    for(int j=0; j<e; j++){
        string u, i;
        cin >> u >> i;
        int x;
        cin >> x;
        G[u][i] = x;
    }
    v.resize(G.size()+1); //G.size()+1 for the returned vertex at the end
    backtracking(0);
}