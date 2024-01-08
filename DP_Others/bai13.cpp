#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Reference: https://just4once.gitbooks.io/leetcode-notes/content/leetcode/divide-and-conquer/241-different-ways-to-add-parentheses.html

//Y tuong: Dau tien, ta xet toan bo bieu thuc, khi gap mot toan tu, ta se chia bieu thuc thanh 2 phan truoc toan tu do va sau toan tu do.
//O moi phan, ta se xu li de tim tat ca cac ket qua co the tinh toan duoc, sau do ket qua cua ca 2 phan se duoc gop chung lai voi toan tu ban dau.
//Viec goi de quy se giup ta chia nho van de den khi khong con toan tu nao nua thi ta se bat dau thuc hien tinh toan va quy thanh bai toan lon.

//Vi du: 3-4*5
//dau tien ta duyet cac phan tu mang den khi phat hien phep - (1)
//bieu thuc se duoc thanh ra thanh 2 phan: 3 va 4*5
//Doi voi 3, vi khong co toan tu nen se duoc tra ve ket qua 3
//Doi voi 4*5, do co toan tu nen se duoc goi de quy xu li tiep den khi tra ve 2 phan tu la 4 va 5
//Sau do, ta se ket hop tinh toan va thu duoc ket qua 4*5 = 20
//Sau do, 20 se duoc ket hop voi 3 cua phep tinh dau tien: 3-20 = -17
//Tuong tu nhu vay o buoc (1), phan tu mang phat hien phep *, ta tach thanh 2 phan la 3-4 va 5, va dieu tuong tu se duoc thuc hien


vector<int> DC(string s){
    vector<int> result;
    for(int i=0; i<s.size(); i++){
        char tmp = s[i];
        //Duyet qua tung phan tu den khi phat hien toan tu
        if(tmp=='+' || tmp=='-' || tmp=='*'){
            //Chia bieu thuc thanh 2 phan truoc va sau toan tu
            vector<int> left = DC(s.substr(0, i));
            vector<int> right = DC(s.substr(i+1));
            //Khi da tim tat ca cac ket qua co duoc bang viec goi de quy left va right, sau do ta se ket hop cac ket qua tu left va right
            //thong qua toan tu o vi tri no duoc chia ra
            for(auto &j: left){
                for(auto &t: right){
                    if(tmp=='+')result.push_back(j+t);
                    else if(tmp=='-')result.push_back(j-t);
                    else if(tmp=='*')result.push_back(j*t);
                }
            }

        }
    }
    //Neu khong co toan tu nao va khong co ket qua, tuc la bieu thuc chi co so nguyen, ta thuc hien convert tu string sang int va append vao mang ket qua
    if (result.size()==0)
        result.push_back(stoi(s));
    return result;
}

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    string s;
    cin >> s;
    vector<int> v = DC(s);
    sort(v.begin(), v.end(), less<int>());
    for(int i=0; i<v.size(); i++)cout<<v[i]<<endl;
}