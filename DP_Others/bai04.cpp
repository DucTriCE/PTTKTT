#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int s;
    cin >> s;
    //f[i] la so cach lac ra tong i
    vector<ll> f(s+1,0);
    //f[0] = 0
    //f[1] = 1 + f[0]
    //f[2] = 1 + f[0] + f[1]
    //f[3] = 1 + f[0] + f[1] + f[2]
    //f[4] = 1 + f[0] + f[1] + f[2] + f[3]
    //f[5] = 1 + f[0] + f[1] + f[2] + f[3] + f[4]
    //f[6] = 1 + f[0] + f[1] + f[2] + f[3] + f[4] + f[5]
    //f[7] = f[1] + f[2] + f[3] + f[4] + f[5] + f[6]
    //f[8] =        f[2] + f[3] + f[4] + f[5] + f[6] + f[7]
    //f[9] =               f[3] + f[4] + f[5] + f[6] + f[7] + f[8]

    //f[1]->f[6]=1
    //f[i] = 0
    //f[i] = f[i-1] + f[i-2] + f[i-3] + f[i-4] + f[i-5] + f[i-6]

    if(s>6)for(int i=1; i<=6; i++)f[i]=1;
    else for(int i=1; i<=s; i++)f[i]=1;

    for(int i=1;i<=s;i++){
        for(int j=1;j<=6;j++){
            if (i-j>=0){
                f[i]+=f[i-j];
                f[i]%=MOD;
            }
        }
    }
    cout<<f[s];
}