#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> v_temp, v_final;
map<string, map<string, int>> G;
int mi = 999999999;
string s;

void backtracking(int k, string first_virtex){
    for(auto it=G[first_virtex].begin(); it!=G[first_virtex].end(); it++){
        if(find(v_temp.begin(), v_temp.end(), it->first)==v_temp.end()){
            v_temp[k] = it->first;
            // cout << "k=" << k << endl;
            if(k==G.size()-1){  //Check if its the final vertex of the Graph
                for(auto it1=G[it->first].begin(); it1!=G[it->first].end(); it1++){
                    if(it1->first==s){   //Graph has returned to the initial vertex
                        int weight = 0;
                        v_temp[k+1] = s;
                        for(int i=1; i<v_temp.size(); i++)weight+=G[v_temp[i-1]][v_temp[i]];
                        if(weight<mi){
                            mi = weight;
                            v_final = v_temp;
                        }
                    }
                }
            }
            else backtracking(k+1, it->first);
            v_temp[k] = "";
        }
    }
}

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int e;
    cin >> e >> s;
    for(int j=0; j<e; j++){
        string u, i;
        cin >> u >> i;
        int x;
        cin >> x;
        G[u][i] = x;
    }
    // cout << G.size() << endl;
    v_temp.resize(G.size()+1); //G.size()+1 for the returned vertex at the end
    v_final.resize(G.size()+1); 
    v_temp[0] = s;
    backtracking(1, s);
    // v_final[G.size()]=s;
    // cout << G.size() << endl;
    // cout << v_final[G.size()] << endl;
    for(int i=0; i<v_final.size(); i++)cout<<v_final[i]<<" ";
}