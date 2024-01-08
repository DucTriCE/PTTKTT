#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

//Reference: https://www.youtube.com/watch?v=cr6Ip0J9izc&t=17s (Weighted Job Scheduling Dynamic Programming)
//Nop kiem nghiem ket qua truoc, khi dung thi se nop lai 1 bang? bao gom giai thich

bool compare(vector<ll> &a, vector<ll> &b) {
    return a[1] < b[1];
}

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n;
    cin >> n;

    vector<vector<ll>> project(n, vector<ll>(3));     //Project la mot vector gom cac vector 3 phan tu tuong ung voi
                                                        //cac project (ngay bat dau, ngay ket thuc, tin chi)
    
    for(int i=0; i<n; i++){
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        project[i][0]=ai; project[i][1]=bi; project[i][2]=ci; 
    }
    sort(project.begin(), project.end(), compare);

    vector<ll> f(n, 0);
    for(int i=0; i<n; i++)f[i] = project[i][2];

    // for(int i=0; i<n; i++)cout << f[i] << " ";
    // for(int i=0; i<n; i++){
    //     cout << project[i][0] << " " << project[i][1] << " " << project[i][2]; 
    //     cout << endl;
    // }

    ll ma = -1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(project[i][0]>project[j][1])f[i]=max(f[i], project[i][2]+f[j]);
            if(f[i]>ma)
                ma=f[i];
        }
    }
    cout << ma;
}