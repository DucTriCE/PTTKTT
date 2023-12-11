#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int e;
    string s;
    cin >> e >> s;
    map<string, map<string, int>> G;
    for(int j=0; j<e; j++){
        string u, i;
        cin >> u >> i;
        int x;
        cin >> x;
        G[u][i] = x;
    }
    // cout << G.size();
    vector<string> v;
    v.push_back(s);
    while(v.size()!=G.size()){
        int mi = G[v[v.size()-1]].begin()->second;
        string tmp = G[v[v.size()-1]].begin()->first;
        for(auto it = G[v[v.size()-1]].begin(); it!=G[v[v.size()-1]].end(); it++){
            if(it->second<mi && find(v.begin(), v.end(), it->first) == v.end()){
                mi = it->second;
                tmp = it->first;
            }
        }
        v.push_back(tmp);
    }
    v.push_back(s);
    for(int i=0; i<v.size(); i++)cout<<v[i]<<" ";
}