#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
vector<long long> v(35);    //35 so nen co the co 35 chu so khac nhau
bool output = false;

void backtracking(int k, int begin){
    for(int i=1; i<s.size()/2; i++){
        if(s.substr(begin, i)[0]=='0' && i!=1)break;
        if(begin+i>s.size())break;
        v[k]=stoll(s.substr(begin, i));
        // cout << v[k] << endl;
        if(k>1){
            if(v[k]!=v[k-1]+v[k-2])continue;
        }
        if(begin+i==s.size()){
            if(v[k]==v[k-1]+v[k-2]){
                // cout << "true";
                // return;
                output=true;
            }
        }
        else backtracking(k+1, begin+i);
        v[k]=NULL; 
    }
}

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    cin >> s;
    backtracking(0, 0);
    if(!output)cout << "false";
    else cout << "true";
}