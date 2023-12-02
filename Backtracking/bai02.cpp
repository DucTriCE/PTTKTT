#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Co tham khao y tuong tu https://blog.luyencode.net/liet-ke-cac-hoan-vi/#huong-dan-giai-bai-toan-liet-ke-hoan-vi-to-hop
vector<int> Check(9,0);
vector<int> Permutations(9);

void output(int size) {
    for (int i=0; i<size; i++)cout << Permutations[i];
    cout << endl;
}

void BackTracking(vector<int> v, int size, int k){
    for (int i=0; i<size; i++) {
		if (!Check[i]) {
            Permutations[k] = v[i];
            Check[i] = 1;
            if(k==size-1)output(size);
            else BackTracking(v, size, k+1);
            Check[i]=0;
		}
	}
}

int main() {    
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n;
    cin >> n;
    int size = to_string(n).length();
    vector<int> v(size);
    for(int i=0; i<v.size(); i++){
        v[i] = n%10;
        n/=10;
    }
    BackTracking(v, size, 0);
}