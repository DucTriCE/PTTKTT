#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main()
{
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    map<int, set<int>> mp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j]
            if(v[i][j]==1)mp[i+1].insert(j+1);
        }
    }
    // for(map<int, set<int>>::iterator it; it!=mp.end(); it++){
    //     cout << it->first << "->" << it->second.b
    // }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)cout<<v[i][j]<<" ";
        cout << "\n";
    }
}

