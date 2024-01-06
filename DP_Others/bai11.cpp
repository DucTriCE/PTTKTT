#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;
//Reference: https://www.geeksforgeeks.org/subset-sum-problem-dp-25/ 
//(Subset Sum Problem using Dynamic Programming with space optimization to linear)
//Ve y tuong, dau tien ta tao mot mang 2 chieu f voi n*(sum(tong tat ca phan tu))
//Voi moi f[i][j] tuong ung voi khi xet den phan tu thu i trong mang ban dau thi f[i][j]
//se la True neu ton tai tong cua mot trong cac phan tu tu A[0:i] co the bang j va False neu nguoc lai
//Tuc la phuong trinh quy hoach dong:
//Neu A[i-1]>j (Tong j be hon gia tri tai phan tu i dang xet) thi f[i][j] = f[i-1][j]
//tuc la trang thai truoc do
//Neu A[i-1]<j (Tong j lon hon gia tri tai phan tu i dang xet), thi luc nay
//Ta se tinh phep OR giua trang thai truoc do f[i-1][j] va trang thai tong j sau khi da tru di A[i-1] la f[i-1][j-A[i-1]]

//Tuy nhien, doi voi bai nay, ta se toi uu bang viec tao ra 2 mang current va previous
//vi ta nhan thay rang voi moi f[i][j], ta chi can biet duoc dong` truoc do, trong truong hop nay la
//f[i-1][j] va f[i-1][j-A[i-1]]

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    ll n, sum=0, count=0;
    cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v[i]=x; sum+=x;
    }

    vector<bool> f_prev(sum+1, 0);
    vector<bool> f_curr(sum+1, 0);

    //Neu sum la 0 thi trang thai se luon la True, tuc la khong co so nao, ta xet base case:
    f_prev[0] = true;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(v[i-1]>j)f_curr[j] = f_prev[j];
            else f_curr[j]= f_prev[j] || f_prev[j-v[i-1]];
        }
        f_prev = f_curr;   
    }
    for(int i=1; i<=sum; i++){
        if(f_curr[i]==true)count++;
    }
    cout << count << endl;
    for(int i=1; i<=sum; i++){
        if(f_curr[i]==true)cout<<i<<" ";
    }
}