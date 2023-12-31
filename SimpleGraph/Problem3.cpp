/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -

struct Graph{   
    map<string, int> mp;
    vector<string> vertices;
    vector<vector<int>> G;

    void nhap(int v, int e){
        G.resize(v, vector<int>(v,0));
        vertices.resize(v);
        for(int i=0; i<v; i++){
            string a;
            cin >> a;
            vertices[i]=a;
            mp[a]=i; //Save index of vertices
        }
        for(int j=0; j<e; j++){
            string u, i;
            cin >> u >> i;
            G[mp[u]][mp[i]]=1;
        }
    }
    void myProcess(int n){
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x==1){
                string a, b;
                cin >> a >> b;
                if(G[mp[a]][mp[b]]==1)cout<<"TRUE\n";
                else cout << "FALSE\n";
            }
            else{
                string a;
                cin >> a;
                bool flag = false;
                for(int i=0; i<G.size(); i++){
                    if(G[mp[a]][i]==1){
                        cout << vertices[i] << " ";
                        flag = true;
                    }
                }
                if(flag==false)cout<<"NONE\n";
                else cout << "\n";
            }
        }
    }
};

int main()
{
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

