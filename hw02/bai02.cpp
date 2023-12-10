#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
vector<int> sol(4);

void output(){
    for(int i=0; i<4; i++){
        cout << sol[i];
        if(i!=3)cout<<".";
    }
    cout << endl;
} 

void backtracking(int k, int begin){
    for(int i=1; i<=3; i++){
        if(begin+i>s.size())break;
        else if(stoi(s.substr(begin, i))>255 || (s.substr(begin, i)[0]=='0' && i>1))break;
        sol[k] = stoi(s.substr(begin, i));
        if(k==3){
            if(begin+i==s.size())output();
       }
        else backtracking(k+1, begin+i);

    }
}

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    cin >> s;
    backtracking(0, 0);
}