#include <iostream>
#include <math.h>
using namespace std;

int sigma(int n){
    int sum=0;
    for(int i=0; i<=log2(n); i++)sum+=(n/(pow(2,i)));
    return sum;
}

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n=1;
    while(n<=20){
        int gan=2+2*(log2(n)+1)+2*sigma(n);
        int sosanh=2*log2(n)+3+sigma(n);
        cout << "Case n=" << n << ": G(n)=" << gan << " SS(n)=" << sosanh << "\n";
        n++;
    }
}