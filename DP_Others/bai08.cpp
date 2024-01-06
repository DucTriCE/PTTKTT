#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    //f[i][j] co do dai la (n+1)*(m-1)
    //f[i][j] tuong ung voi so phep bien doi can thiet tai ki tu a[j] de chuoi a[0:j] = b[0:i]
    //boi vi ta can luu ket qua cua tung bai toan con tuong ung voi su thay doi cua cac chuoi con
    //de co the tim duoc so phep bien doi can thiet 
    vector<vector<int>> f(n+1, vector<int>(m+1));   

    //Dau tien ta thay voi cac truong hop f[0][i] voi 1<=i<=n hay f[i][0] voi 1<=i<=m 
    //thi deu bang i (Do chuoi ta dang xet voi mot ki tu rong, thi chi co cach la xoa hoac
    //them ki tu, rieng doi voi truong hop f[0][0] la ki tu rong thi bang 0)
    for(int i=0; i<=n; i++)
        f[i][0] = i;
    for(int i=0; i<=m; i++)
        f[0][i] = i;

    //Tiep theo, voi 2 ki tu ta xet thi se roi vao 2 truong hop:
    //1: Neu 2 ki tu giong nhau thi ta chi viec don gian bien doi n-1 ki tu truoc do cua a
    //ung voi m-1 ki tu cua b --> f[i][j] = f[i-1][j-1]
    //2: Neu 2 ki tu khac nhau, ta lan luot xem xet cac kha nang them, xoa, hay doi ki tu
    //Neu them ki tu de tai cuoi a sao cho chuoi a = b, ta phai bien doi sao cho n ki tu cua a
    //phai ung voi m-1 ki tu cua b --> f[i][j] = f[i][j-1]+1
    //Neu xoa ki tu, ta tuong tu phai bien doi n-1 ki tu cua a sao cho trung voi m ki tu cua b
    //tuong ung voi:               --> f[i][j] = f[i-1][j]+1
    //Con lai, neu ta chi thay doi ki tu a[n-1] va b[m-1], thi sau do ta chi can thay doi n-1 va m-1
    //ki tu con lai tuong ung voi cua a va b --> f[i][j] = f[i-1][j-1]+1
    //Phuong trinh quy hoach dong luc nay se duoc lay so phep bien doi thap nhat trong ca ba truong hop
    //f[i][j] = min(f[i][j-1], f[i-1][j], f[i-1][j-1])+1
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1])f[i][j]=f[i-1][j-1];
            else{
                f[i][j]=min(min(f[i][j-1], f[i-1][j]),f[i-1][j-1])+1;
            }
        }
    }
    cout << f[n][m];
}