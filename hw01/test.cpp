#include <iostream>
#include <math.h>
using namespace std;

int main(){
    // freopen("../input.txt","r",stdin);
    // freopen("../output.txt","w",stdout);
    float s = 0.0;
    for(int i=1; i<=5; i++){
        s+=(float)1/i;
        cout<<s<< " ";
    }
}

