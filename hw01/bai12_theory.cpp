#include <iostream>
#include <math.h>
using namespace std;

int sigma(int n){
    int sum=0;
    for(int i=1; i<=n/2; i++)sum+=i;
    return sum;
}
int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n=1;
    while(n<=20){
        int gan=0, sosanh=0;
        gan+=(n+2);
        gan+=2*sigma(n);
        sosanh+=(n+1);
        sosanh+=(sigma(n));
        cout << "Case n=" << n << ": G(n)=" << gan << " SS(n)=" << sosanh << "\n";
        n++;
    }
}