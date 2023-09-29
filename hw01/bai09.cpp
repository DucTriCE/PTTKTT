#include <iostream>
using namespace std;

int main(){
    // freopen("../input.txt","r",stdin);
    // freopen("../output.txt","w",stdout);
    int n;
    while(cin>>n){
        int gan=0, sosanh=0, alphai=0;
        //Bai09
        /*===================*/
        int i=1, res=0;
        gan+=2;
        while(i<=n){
            sosanh+=1;
            int j=1, k=1;
            gan+=2;
            while(j<=i){
                sosanh+=1;
                alphai+=1;
                res=res+i*j;
                k+=2;
                j+=k;
                gan+=3;
            }
            sosanh+=1;
            i+=1;
            gan+=1;
        }
        sosanh+=1;
        /*===================*/
        cout << "Case n=" << n << ": G(n)=" << gan << " SS(n)=" << sosanh << " alpha_i= " << alphai << "\n";
    }
}

