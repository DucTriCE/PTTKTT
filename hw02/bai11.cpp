#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> x;
vector<int> machine_time;
vector<int> tmp_sol;
vector<int> sol;
int mi = 999999999;

int findMaxtime(){
    int ma = machine_time[0];
    for(int i=1; i<machine_time.size(); i++){
        if(machine_time[i]>ma)ma = machine_time[i];
    }
    return ma;
}

void backtracking(int k){
    for(int i=0; i<m; i++){
        tmp_sol[k] = i;
        machine_time[i]+=x[k];
        if(k==n-1){
            int tmp = findMaxtime();
            if (tmp < mi){
                sol = tmp_sol;
                mi = tmp;
            }
        }
        else backtracking(k+1);
        machine_time[i]-=x[k];
    }
}

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    cin >> n >> m;
    machine_time.resize(m); tmp_sol.resize(n); sol.resize(n);
    for(int i=0; i<n; i++){
        int time;
        cin >> time;
        x.push_back(time);
    }
    // for(int i=0; i<n; i++){
    //     cout << x[i] << " ";
    // }
    // cout << endl;
    backtracking(0);
    for(int i=0; i<n; i++){
        cout << sol[i] << " ";
    }
}