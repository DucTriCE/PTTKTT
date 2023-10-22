#include <iostream>
#include <map>
#include <set>
using namespace std;

struct Graph{
    map<string, set<string>> mp;
    void nhap(int e){
        for(int j=0; j<e; j++){
            string u, i;
            cin >> u >> i;
            mp[u].insert(i);
        }
    }
    void myProcess(){
        for(map<string, set<string>>::iterator it=mp.begin(); it!=mp.end(); it++){
            if(it->second.size()!=mp.size()-1){
                cout << "FALSE";
                return;
            }
        }
        cout << "TRUE";
    }
};


int main()
{
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    Graph G;
    int e;
    cin >> e;
    G.nhap(e);
    G.myProcess();
    return 0;
}

