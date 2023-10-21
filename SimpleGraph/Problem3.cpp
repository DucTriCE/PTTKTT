/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;

//###INSERT CODE HERE -
struct Graph{   
    map<string, set<string>> mp;
    void nhap(int e){
        for(int j=0; j<e; j++){
            string u, i;
            cin >> u >> i;
            mp[u].insert(i);
        }
    }
    void myProcess(int n){
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x==1){
                string a, b;
                cin >> a >> b;
                if(mp[a].find(b)!=mp[a].end())cout<<"TRUE\n";
                else cout << "FALSE\n";
            }
            else{
                string a;
                cin >> a;
                cout << mp[a].size() << "\n";
            }
        }
    }
};


int main()
{
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    Graph G;
    int e, n; 
    cin >> e >> n;
    G.nhap(e);
    G.myProcess(n);
    return 0;
}

