#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//Tham khao lam tron tu ChatGPT o dong 24
//Tham khao cach fix loi~ lam tron o dong 25 tu ban 21522708 (Thay vi chia 10 o dong 24, ta *10 o variable "diem")
//Tham khao cach doi float sang long double tu ban 21522708 (Nham` fix loi lam tron)

vector<long double> lst;
vector<int> heso;

void output() {
    for(int x=0; x<lst.size(); x++)cout<<lst[x]<<" ";
    cout << endl;
}

void BackTracking(int n, long double diem, int k){
    for(long double i=0.25; i<=10; i+=0.25){
        lst[k] = i;
        if(k==n-1){
            long double score=0;
            for(int j=0; j<lst.size(); j++)score+=(((long double)heso[j]/100)*lst[j]);
            score = roundf(score*10);
            if(diem*10==score){
                output();
                // cout << " DTB: " << score << " DIEM: " << diem << endl;
            }
            else if(diem*10<score)break;
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