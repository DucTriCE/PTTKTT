#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> Graph;
map<string, int> vertex_index;
vector<int> color;
int v, e;


void BackTracking(int k){
    for(int i=0; i<v; i++){
        if(k==v-1){

        }
        else BackTracking(k+1);
    }
}

int main() {    
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    cin >> v >> e;
    for(int i=0; i<v; i++){
        string x;
        cin >> x;
        vertex_index[x] = i;
    }
    BackTracking(0);
}