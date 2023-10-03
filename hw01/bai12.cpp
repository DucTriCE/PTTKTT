#include <iostream>
using namespace std;

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n=1;
    while(n<=20){
        int gan=0, sosanh=0;
        //Bai12
        /*===================*/
        int i=1, res=0;
        gan+=2;
        while(i<=n){
            sosanh+=1;
            int j=1;
            gan+=1;
            while(j<=i){
                sosanh+=1;
                res+=(i*j);
                j+=1;
                gan+=2;
            }
            sosanh+=1;
            i+=2; //Nhom 2
            gan+=1;
        }
        sosanh+=1;
        /*===================*/
        cout << "Case n=" << n << ": G(n)=" << gan << " SS(n)=" << sosanh << "\n";
        n++;
    }
}

