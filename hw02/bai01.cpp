#include <iostream>
#include <vector>

using namespace std;

vector<char> sol;
char bracket[2] = {'(',')'};

void output(vector<char> sol, int n){
    for(int i=0; i<n*2; i++){
        cout << sol[i];
    }
    cout << endl;
}
void backtracking(int k, int n, int isValid){
    for(int i=0; i<2; i++){
        sol[k] = bracket[i];
        if(bracket[i]==')')isValid-=1;
        else isValid+=1;
        if(isValid<0)continue;
        if(k==n*2-1){
            // cout << isValid << " ";
            if(isValid!=1)continue;
            else output(sol, n);
        }
        else backtracking(k+1, n, isValid);

        if(bracket[i]==')')isValid+=1;
        else isValid-=1;
    }
}

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("../input.txt","r",stdin);
    // freopen("../output.txt","w",stdout);
    int n;
    cin >> n;
    sol.resize(n*2);
    backtracking(0, n, 0);
}