/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -
void inputGraph(vector<vector<int>> &G, int v, int e){
	G.resize(v, vector<int>(v, 0));
	for(int j=0; j<e; j++){
		int u, i;
		cin >> u >> i;
		G[u-1][i-1]=1;
	}
}

void process(vector<vector<int>> &G, int v, int n){
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(x==1){
			int a, b;
			cin >> a >> b;
			if(G[a-1][b-1]==1)cout<<"TRUE\n";
			else cout << "FALSE\n";
		}
		else{
			int a;
			cin >> a;
			bool flag=false;
			for(int i=0 ; i<v; i++){
				if(G[a-1][i]==1){
					cout << i+1 << " ";
					flag=true;
				}
			}
			if(flag==false)cout<<"NONE\n";
			else cout <<"\n";
		}
	}
}


int main()
{
	freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int>> G;

	inputGraph(G,v,e);
	process(G,v,n);

	return 0;
}
