#include <iostream>
#include <math.h>
using namespace std;

int main(){
    // freopen("../input.txt","r",stdin);
    // freopen("../output.txt","w",stdout);
    int sum=0;
    for(int i =1; i<=100; i++){
        sum+=sqrt(i);
    }
    cout << sum;
}

