#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深度优先搜索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // 标记顶点v为已被访问

    // 遍历可达的每个顶点next_v
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // 如果next_v已被访问，则不再搜索
        dfs(G, next_v); // 递归地进行搜索
    }
}

int main() {
    // 顶点数和边数
    int N, M;
    cin >> N >> M;

    // 输入图（这里假定是有向图）
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 开始搜索
    seen.assign(N, false); // 初始状态下，所有顶点都未被访问
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // 如果已经被访问，不再进行搜索
        dfs(G, v);
    }
}
