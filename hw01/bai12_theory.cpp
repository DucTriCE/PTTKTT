#include <iostream>
#include <math.h>
using namespace std;

int sigma(int n){
    int sum=0;
    for(int i=1; i<=n/2; i++)sum+=(2*i+1);
    cout << sum << " ";
    return sum;
}
int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n=1;
    while(n<=20){
        int gan=(n*n)/2 + n + 2;
        int sosanh= (n*n)/4 + n + 1;
        cout << "Case n=" << n << ": G(n)=" << gan << " SS(n)=" << sosanh << "\n";
        n++;
    }
}