#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s, Inp;
vector<bool> idxUsed(8, false);
string tmp(8, ' ');
vector<string> v;
int cnt = 0;

bool check(int year, int month, int day) {
    if(year==0)return false;
    if(month==0 || month>12)return false;
    if(day==0 || day>31)return false;
    if(month==4 || month==6 || month==9 || month==11) {
        if(day>30)return false;
    } 
    else if(month==2){ //Thang 2
        if(year%3328==0){
            if(day>30)return false;
        }
        else if((year%4==0 && year%100!=0) || (year%400==0)){
            if(day>29)return false;
        }
        else if(day>28)return false;
    }
    return true;
}

void backtracking(int k){
    for(int i=0; i<8; i++){
        if(idxUsed[i]==false){
            tmp[k] = s[i];
            idxUsed[i] = true;
            if(k==s.size()-1){
                int year = stoi(tmp.substr(0, 4));
                int month = stoi(tmp.substr(4, 2));
                int day = stoi(tmp.substr(6, 2));
                if(check(year, month, day)){
                    // cout << year << " " << month << " " << day << endl;
                    if(find(v.begin(), v.end(), tmp)==v.end()){
                        v.push_back(tmp);
                        cnt++;
                    }
                }
            }
            else backtracking(k+1);
            idxUsed[i] = false;
        }
    }
}

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    string y, m, d;
    // getline(cin, Inp);
    cin >> y >> m >> d;
    // for(int i=0; i<Inp.size(); i++){
    //     if(Inp[i]!=' ')s+=Inp[i];
    // }
    s+=y; s+=m; s+=d;
    sort(s.begin(), s.end());
    // cout << s.size() << endl;
    // cout << s;
    backtracking(0);
    cout << cnt << endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i].substr(0, 4)<<" "<<v[i].substr(4, 2)<<" "<<v[i].substr(6, 2)<<endl;
        // if(i!=v.size()-1)cout<<endl;
    }
}