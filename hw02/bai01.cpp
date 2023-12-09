#include <iostream>
#include <vector>

using namespace std;

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
    int n;
    cin >> n;
    backtracking(0);
    for(int i=0; i<n; i++){
        cout << sol[i] << " ";
    }
}