#include <iostream>
#include <math.h>
using namespace std;

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n=1;
    while(n<=20){
        int gan=0, sosanh=0;
        gan+=(3*n+3);
        sosanh+=(2*n+1);
        int temp=0;
        for(int i=1; i<=n; i++){
            temp+=(log(i)+0.5772156649);
        }
        gan+=(2*temp);
        sosanh+=temp;
        cout << "Case n=" << n << ": G(n)=" << gan << " SS(n)=" << sosanh << "\n";
        n++;
    }
}