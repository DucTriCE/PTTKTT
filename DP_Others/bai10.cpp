#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;
//Reference: Tham khao cach toi uu vector thanh 2 vector 1 chieu prev va current tu ban 21522708
//Ve cach lam thi tuong tu voi cach cu~, tuy nhien luc nay vector ta xet khong phai
//la vector 2 chieu, ma la 2 vector 1 chieu luu gia tri lan luot giua hang dang xet
//va gia tri hang truoc do, va se lien tuc cap nhat
int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    ll n, W_;
    cin >> n >> W_;
    vector<int> w(n), v(n);
    for(int i=0; i<n; i++){
        int wi, vi;
        cin >> wi >> vi;
        w[i]=wi; v[i]=vi;
    }

    //f[i][j] tuong ung voi gia tri toi da khi xet mat hang thu i, balo co suc chua j
    vector<ll> f_prev(W_+1, 0);
    vector<ll> f_curr(W_+1, 0);
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=W_; j++){
            //Dau tien voi cac truong hop mat hang 0 (rong) hay suc chua la 0 thi gia tri tai f[i][j]=0
            //Voi moi f[i][j], neu ta thay neu mat hang vuot qua suc chua j, ta chi co 1 su lua chon
            //la lay gia tri tai f[i-1][j]
            //Neu mat hang co trong luong be hon suc chua j cua balo hien tai, ta co 2 su lua chon:
            //1: Chon mat hang i, gia tri hien tai se la:f[i][j] = giatri(i) + gia tri con lai lon nhat truoc do f[i-1][j-giatri(i)]
            //2: Neu khong chon, ta cung se tuong ung lay ket qua truoc do f[i][j] = f[i-1][j]
            //Do co 2 lua chon, ta se chon giua lua chon tot nhat bang viec lay max
            //--> Phuong trinh quy hoach dong:
            //Neu trong luong cua mat hang i lon hon suc chua balo j: f[i][j] = f[i-1][j]
            //Nguoc lai: f[i][j] = max(f[i-1][j], s[i-1]+f[i-1][j-h[i-1]])
            if(w[i-1]>j)f_curr[j]=f_prev[j];
            else f_curr[j]=max(f_prev[j], v[i-1]+f_prev[j-w[i-1]]);
        }
        //Khi xet qua mot item moi cua mot hang moi, ta can luu lai f_curr thong qua
        //update f_prev = f_curr
        f_prev = f_curr;   
    }
    cout << f_curr[W_];
}