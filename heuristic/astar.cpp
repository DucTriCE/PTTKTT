#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

class Graph{
    vector<vector<int>> matrix;     //adjacent matrix
    map<string, int> v_index;       //vertex
    vector<string> v_names;         //vertex name
    vector<int> h;                  //heuristic value
    public:
        void init(int v){
            matrix = vector<vector<int>>(v, vector<int>(v, 0));
            v_names.resize(v, " ");
            h.resize(v, 0);
        }

        void inputGraph(int v, int e){
            for(int i=0; i<v; i++){
                string x;
                cin >> x;
                v_names[i]=x;
                v_index[x]=i;
            }
            for(int i=0; i<v; i++){
                int x;
                cin >> x;
                h[i] = x;
            }
            for(int i=0; i<e; i++){
                string v, w;
                cin >> v >> w;
                int x;
                cin >> x;
                matrix[v_index[v]][v_index[w]]=x;
            }
        }

        void outputGraph(){
            cout << endl << "============PRINTING============" << endl;
            for(int i=0; i<matrix.size(); i++){
                for(int j=0; j<matrix[i].size(); j++)cout<<matrix[i][j]<<" ";
                cout << endl;
            }
            cout << "================================" << endl;
        }

        pair<vector<string>, pair<int, int>> AStar(string start, string end){
            int s = v_index[start];
            int t = v_index[end];
            map<string, string> parent;         //Parent[A] = B, parent of A is B
            vector<bool> close(matrix.size(), 0);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> open;
            vector<int> g(matrix.size(), 999999999);
            vector<int> f(matrix.size(), -1);
            g[s] = 0;
            f[s] = h[s];
            open.push(make_pair(f[s], s)); 
            bool found = false;
            while(!open.empty()){
                int p = open.top().second;
                open.pop();
                if(p==t){
                    vector<string> path;
                    int num_vertex=1, weight=0;
                    while(p!=s){
                        path.push_back(v_names[p]);
                        weight+=matrix[v_index[parent[v_names[p]]]][p];
                        p=v_index[parent[v_names[p]]];
                    }
                    for(int i=0; i<matrix.size();i++){
                        if(close[i]==1)num_vertex++;
                    }
                    path.push_back(v_names[s]);
                    reverse(path.begin(), path.end());
                    return {path, {num_vertex, weight}};
                }
                close[p] = 1;
                for(int i=0; i<matrix.size(); i++){
                    int q = v_index[v_names[i]];
                    if(matrix[p][q]>0){
                        int g_new = g[p] + matrix[p][q];
                        if(g[q]>g_new){
                            g[q] = g_new;
                            f[q] = g[q] + h[q];
                            parent[v_names[q]] = v_names[p];
                            open.push(make_pair(f[q], q));
                        }
                    }
                }
            }
            if(found==false){
                int num_vertex = 0;
                for(int i=0; i<matrix.size();i++){
                    if(close[i]==1)num_vertex++;
                }
                return {{}, {num_vertex, 0}};    //no path - number of vertex in close - 0 (as theres no path)
            }
        }
};



int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    Graph G;
    int v, e;
    string start, end;
    cin >> v >> e;
    cin >> start >> end;
    G.init(v);
    G.inputGraph(v, e);
    //G.outputGraph();
    auto result = G.AStar(start, end);

    if(result.first.empty()){
        cout << "-unreachable-" << endl;
        cout << result.second.first << " " << result.second.second;
    }
    else{
        for(const auto &vertex : result.first)cout << vertex << " ";
        cout << endl;
        cout << result.second.first<< " " << result.second.second;
    }
}

