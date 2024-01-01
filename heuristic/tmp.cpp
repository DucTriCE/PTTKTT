#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

class Graph
{
    vector<vector<int>> matrix; // adjacency matrix
    map<string, int> v_index;    // vertex index
    vector<string> v_names;      // vertex names
    vector<int> h;               // heuristic values

public:
    void init(int v)
    {
        matrix = vector<vector<int>>(v, vector<int>(v, 0));
        v_names = vector<string>(v, " ");
        h = vector<int>(v, 0);
    }

    void inputGraph(int v, int e)
    {
        for (int i = 0; i < v; i++)
        {
            string s;
            cin >> s;
            v_names[i] = s;
            v_index[s] = i;
        }
        for (int i = 0; i < v; i++)
        {
            int heuristic;
            cin >> heuristic;
            h[i] = heuristic; 
        }
        for (int i = 0; i < e; i++)
        {
            string x, y;
            int weight;
            cin >> x >> y >> weight;
            matrix[v_index[x]][v_index[y]] = weight;
        }
    }
    void printGraph()
        {
            cout << "Matrix:" << endl;
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
         
            }
        }
    pair<vector<string>, pair<int, int>> AStar(string start, string goal)
    {
        map<string, string> parent;
        vector<bool> close(matrix.size(), 0);  // close = {}
        int startidx = v_index[start];
        int goalidx = v_index[goal];

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> open;
        vector<int> g(v_names.size(), INT_MAX);
        vector<int> f(v_names.size(), -1);
        float temp=0;
        //B1:
        g[startidx] = 0; //g(s)=0
        f[startidx] = h[startidx]; //f(s)=h(s)
        open.push(make_pair(f[startidx], startidx)); // open = {s}
        //B2:
        while (!open.empty()) // open != {}
        {
            // Print open set
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tempOpen = open;
            //2.1
            int p = open.top().second; //Chọn p thuộc open có f(p) nhỏ nhất
            open.pop();               // xóa ra
            //2.2
            if (p == goalidx) // Nếu p là trạng thái kết thúc thì thoát ra, thông báo kết quả
            {
                vector<string> result;
                int len = 0;
                while (p != startidx)
                {
                    result.push_back(v_names[p]);
                    len += matrix[v_index[parent[v_names[p]]]][p];
                    p = v_index[parent[v_names[p]]];
                }
                temp++;
                for(int j=0;j<v_names.size();j++){
                    if(close[j]==1) temp++;
                }
                result.push_back(v_names[startidx]);
                reverse(result.begin(), result.end());
                return {result, {temp, len}};
            }
            //2.3
            close[p] = 1; // bỏ p vào close
            //2.4
            for (int i = 0; i < v_names.size(); i++)
            {
                int q = v_index[v_names[i]];
                if (matrix[p][q] > 0)
                {
                        int g_new = g[p] + matrix[p][q];
                        if (g_new < g[q])
                        {
                            g[q] = g_new;
                            f[q] = g[q] + h[q];
                            parent[v_names[q]] = v_names[p];
                            open.push(make_pair(f[q], q));
                        }
                }
            }
        }
        temp=0;
        for(int j=0;j<v_names.size();j++){
            if(close[j]==1) temp++;
        }
        return {{}, {temp, 0}};
    }
};

int main()
{
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int v, e;
    string start, end;
    cin >> v >> e;
    cin >> start >> end;

    Graph g;
    g.init(v);
    g.inputGraph(v, e);

    g.printGraph();

    auto result = g.AStar(start, end);

    if (result.first.empty())
    {
        cout << "-unreachable-" << endl;
        cout << result.second.first<< " " << result.second.second;
    }
    else
    {
        for (const auto &vertex : result.first)
        {
            cout << vertex << " ";
        }
        cout << endl;
        cout << result.second.first<< " " << result.second.second;
    }
    return 0;
}