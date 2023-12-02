#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int get_minidx(vector<int> machine_time){
    int mi = 999999999;
    int idx;
    for(int i=0; i<machine_time.size(); i++){
        if(machine_time[i]<mi){
            idx = i;
            mi = machine_time[i];
        }
    }
    return idx;
}

int main() {    
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> x(n);
    vector<pair<int, int>> ans(n);

    vector<int> machine_time(m);
    vector<int> out(n);

    for(int i=0; i<n; i++){
        int tim;
        cin >> tim;
        x[i].first = tim;
        x[i].second = -1;
        ans[i].first = tim;
        ans[i].second = -1;
    }
    sort(x.rbegin(), x.rend()); 
    int min_idx = 0;     

    for(int i=0; i<n; i++){
        machine_time[min_idx]+=x[i].first;
        ans[i].second = 
        int tmp = get_minidx(machine_time);
        if(tmp!=min_idx)min_idx = tmp;
    }

    for(int i=0; i<n; i++){
        cout << x[i].second << " ";
    } 

}