#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int v, e;
    cin >> v >> e;
    vector<string> vertex;
    map<string, set<string>> Graph;
    map<string, int> colors;
    for(int i=0; i<v; i++){
        string x;
        cin >> x;
        vertex.push_back(x);
    }
    for(int j=0; j<e; j++){
        string u, i;
        cin >> u >> i;
        Graph[u].insert(i);
    }
    for(int i=0; i<v; i++){
        for(set<string>::iterator it=Graph[vertex[i]].begin(); it!=Graph[vertex[i]].end(); it++)
            
    }
}