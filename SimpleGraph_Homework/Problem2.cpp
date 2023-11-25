#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct Graph{
    vector<string> vertices;
    map<string, set<string>> mp;
    void nhap(int v, int e){
        vertices.resize(v);
        for(int i=0; i<v; i++){
            cin >> vertices[i];
        }
        for(int j=0; j<e; j++){
            string u, i;
            cin >> u >> i;
            mp[u].insert(i);
            mp[i].insert(u);
        }
    }
    void myProcess(){
        for(int i=0; i<vertices.size(); i++){
            cout<<mp[vertices[i]].size();
            if(i!=vertices.size()-1)cout<<" ";
        }
    }
};


int main()
{
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    Graph G;
    int v, e;
    cin >> v >> e;
    G.nhap(v, e);
    G.myProcess();
    return 0;
}

