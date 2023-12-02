#include <iostream>
#include <vector>
using namespace std;

//Co tham khao y tuong tu https://blog.luyencode.net/liet-ke-cac-hoan-vi/#huong-dan-giai-bai-toan-liet-ke-hoan-vi-to-hop
vector<int> Check(9,0);
vector<int> Permutations(9);

void output(int n) {
    for (int i=0; i<n; i++)cout << Permutations[i]<< " ";
    cout << endl;
}

void BackTracking(int k, int n){
    for (int i=0; i<n; i++) {
		if (!Check[i]) {
            Permutations[k] = i+1;
            Check[i] = 1;
            if(k==n-1)output(n);
            else BackTracking(k+1, n);
            Check[i]=0;
		}
	}
}

int main() {    
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n;
    cin >> n;
    BackTracking(0, n);
}