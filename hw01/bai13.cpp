#include <iostream>
using namespace std;

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n=1;
    while(n<=20){
        int gan=0, sosanh=0;
        //Bai13
        /*===================*/
        int i=n, sum=0;
        gan+=2;
        while(i>0){
            sosanh+=1;
            int j=i;
            gan+=1;
            while(j>0){
                sosanh+=1;
                sum+=1;
                j-=1;
                gan+=2;
            }
            sosanh+=1;
            i/=2; 
            gan+=1;
        }
        sosanh+=1;
        /*===================*/
        cout << "Case n=" << n << ": G(n)=" << gan << " SS(n)=" << sosanh << "\n";
        n++;
    }
}

