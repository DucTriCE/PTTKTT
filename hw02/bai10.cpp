#include <iostream>
#include <vector>

using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> machine(m, vector<int>());
    vector<int> machine_time(m);
    vector<int> sol(n);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int time;
            cin >> time;
            machine[i].push_back(time);
        }
    }

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout << machine[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=0; i<n; i++){
        int tmp = 0;
        for(int j=0; j<m; j++){
            if(machine[j][i]<0 && j==0)tmp++;
            else if(machine[j][i]+machine_time[j]<machine[tmp][i]+machine_time[tmp])tmp = j;
            // cout << "tmp: " << tmp << endl;
        }
        sol[i]=tmp; 
        machine_time[tmp]+=machine[tmp][i];
    }

    for(int i=0; i<sol.size(); i++)cout<<sol[i]<<" ";
}