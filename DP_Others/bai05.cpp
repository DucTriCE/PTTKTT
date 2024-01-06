#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n;
    cin >> n;

    //road[i][j] = toa do (i,j) tren ban do duong di
    //road[i][j] == 1 , (i,j) = '.'
    //road[i][j] == 0, (i,j) == '*'
    //road[i][j] == 1, co the di vao diem (i,j)
    vector<vector<int>> road(n+2, vector<int>(n+2,0));

    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=n; j++){
            if(s[j-1]=='.')road[i][j]=1;
        }
    }
    if(road[n][n]!=1){
        cout << 0;
        return 0;
    }
    // for(int i=0; i<=n+1; i++){
    //     for(int j=0; j<=n+1; j++)
    //         cout<<road[i][j]<<" ";
    //     cout << endl;
    // }

    //f[i][j] = so cach di toi diem (i,j)
    //f[i][j] = f[i-1][j] + f[i][j-1]
    vector<vector<int>> f(n+2, vector<int>(n+2,0));

    //Base case
    f[1][1]=1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(road[i][j]==1){
                if(road[i-1][j]==1)f[i][j]+=f[i-1][j];
                f[i][j]%=MOD;

                if(road[i][j-1]==1)f[i][j]+=f[i][j-1];
                f[i][j]%=MOD;
            }
        }
    }
    cout << f[n][n];
}