#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n;
    cin >> n;
    map<int, set<int>> mp;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            if(x==1)mp[i+1].insert(j+1);
        }
    }

    for(map<int, set<int>>::iterator it=mp.begin(); it!=mp.end(); it++){
        cout << it->first << "->";
        for(set<int>::iterator st = it->second.begin(); st!=it->second.end(); st++){
            cout << *st;
            if(next(st)!=it->second.end())cout<<" ";
            else cout << "\n";
        }
    }
}

