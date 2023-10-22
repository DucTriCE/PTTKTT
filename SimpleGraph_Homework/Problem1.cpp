#include <iostream>
#include <vector>
using namespace std;

struct Graph{
    vector<vector<int>> G;   
    void nhap(int v, int e){
        G.resize(v, vector<int>(v,0));
        for(int j=0; j<e; j++){
            int u, i;
            cin >> u >> i;
            G[u-1][i-1]=1;
            G[i-1][u-1]=1;
        }
    }
    void myProcess(int n){
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x==1){
                int u, i;
                cin >> u >> i;
                if(G[u-1][i-1]==1 || G[i-1][u-1]==1)cout<<"TRUE\n";
                else cout << "FALSE\n";
            }
            else{
                int u;
                cin >> u;
                bool flag = false;
                for(int i=0; i<G.size(); i++){
                    if((G[u-1][i]==1 || G[i][u-1]) && i!=u-1){
                        cout << i+1 << " ";
                        flag = true;
                    }
                }
                if(flag==false)cout<<"NONE\n";
                else cout << "\n";
            }
        }
    }
};


int main()
{
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    Graph G;
    int v, e, n;
    cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

