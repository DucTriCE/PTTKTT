#include <iostream>
using namespace std;

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n=1;
    while(n<=20){
        int gan=0, sosanh=0;
        //Bai11
        /*===================*/
        int i=1, ret=0;
        float s=0.0;
        gan+=3;
        while(i<=n){
            sosanh+=1;
            int j=1;
            s=s+(1/i);
            gan+=2;
            while(j<=s){
                sosanh+=1;
                ret+=(i*j);
                j+=1;
                gan+=2;
            }
            sosanh+=1;
            i+=1;
            gan+=1;
        }
        sosanh+=1;
        /*===================*/
        cout << "Case n=" << n << ": G(n)=" << gan << " SS(n)=" << sosanh << "\n";
        n++;
    }
}

