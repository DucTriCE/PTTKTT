#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<long double> lst;
vector<int> heso;

void output() {
    for(int x=0; x<lst.size(); x++)cout<<lst[x]<<" ";
    cout << endl;
}

void BackTracking(int n, long double diem, int k){
    for(long double i=0.25; i<=10; i+=0.25){
        long double score=0;
        lst[k] = i;
        if(k==n-1){
            for(int j=0; j<lst.size(); j++)score+=(((long double)heso[j]/100)*lst[j]);
            long double roundedScore = roundf(score*10);
            if(diem*10==roundedScore){
                output();
                // cout << " DTB: " << score << " DIEM: " << diem << endl;
            }
        }
        else BackTracking(n, diem, k+1);
    }
}

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        heso.push_back(x);
    }
    lst.resize(n);
    long double diem;
    cin >> diem;
    BackTracking(n, diem, 0);
}