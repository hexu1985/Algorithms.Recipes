#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深度优先搜索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // 将顶点v标记为已被访问 

    // 从顶点v可到达的每个顶点 
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // 如果next_v已被访问，则不再搜索
        dfs(G, next_v); // 递归地进行搜索
    }
}

int main() {
    // 顶点数和边数
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    // 接收图的输入
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 以顶点s作为起点进行搜索
    seen.assign(N, false); // 初始化所有顶点为未被访问
    dfs(G, s);

    // 判断是否可以到达t
    if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
