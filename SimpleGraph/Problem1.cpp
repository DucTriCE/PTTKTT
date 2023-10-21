/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
using namespace std;

void inputGraph(bool*[], int);
void process(bool*[], int, int);



int main()
{
	freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;
	

	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được
    
	//bat dau tu day
    G = new bool *[v];
    for(int i=0; i<v; i++){
        G[i] = new bool [v];
    }

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            G[i][j] = false;
        }
    }
	inputGraph(G, e);
	process(G, n, v);

}

void inputGraph(bool*G[], int e){
	for(int j=0; j<e; j++){
		int u, i;
		cin >> u >> i;
		G[u-1][i-1]=true;
    }
}

void process(bool*G[], int n, int v){
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x==1){
            int a, b;
            cin >> a >> b;
            if(G[a-1][b-1]==true)cout<<"TRUE\n";
            else cout << "FALSE\n";
        }
        else{
			int a;
			cin >> a;
			bool flag=false;
			for(int i=0 ; i<v; i++){
				if(G[a-1][i]==true){
					cout << i+1 << " ";
					flag=true;
				}
			}
			if(flag==false)cout<<"NONE\n";
			else cout <<"\n";
        }
    }
}
//###INSERT CODE HERE -
