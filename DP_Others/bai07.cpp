#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for(int i=0; i<n; i++)cin>>h[i];    //Gia tri quyen sach
    for(int i=0; i<n; i++)cin>>s[i];    //So trang quyen sach

    //f[i][j] tuong ung voi so trang toi da mua duoc khi xet den quyen sach thu i, voi so tien j
    vector<vector<int>> f(n+1, vector<int>(x+1));
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=x; j++){
            //Dau tien voi cac truong hop quyen sach thu 0 hay voi so tien 0 thi so trang se mac dinh la 0
            if(i==0 || j==0)f[i][j]=0;
            else{
                //Voi moi f[i][j], neu ta thay quyen quyen sach i vuot qua gia tien j, ta chi co 1 su lua chon
                //la lay gia tri tai f[i-1][j]
                //Neu quyen sach co gia tien van be hon tong gia tien j hien tai, ta co 2 su lua chon:
                //1: Chon lay quyen sach i, so trang hien gio se la: sotrang(i) + so trang con lai lon nhat truoc do f[i-1][j-sotrang(i)]
                //2: Neu khong chon, ta cung se tuong ung lay ket qua truoc do
                //Do co 2 lua chon, ta se chon giua lua chon tot nhat bang viec lay max
                //--> Phuong trinh quy hoach dong:
                //Neu gia tien quyen sach i lon hon so tien ta dang co: f[i][j] = f[i-1][j]
                //Nguoc lai: f[i][j] = max(f[i-1][j], s[i-1]+f[i-1][j-h[i-1]])
                if(h[i-1]>j)f[i][j]=f[i-1][j];
                else f[i][j]=max(f[i-1][j], s[i-1]+f[i-1][j-h[i-1]]);
            }   
        }
    }
    cout << f[n][x];
}