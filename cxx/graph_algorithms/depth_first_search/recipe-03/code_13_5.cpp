#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 二部图判定
vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        // 如果相邻顶点的颜色已经确定
        if (color[next_v] != -1) {
            // 如果相邻顶点的颜色相同，那么这不是二部图
            if (color[next_v] == cur) return false;

            // 如果颜色已确定，则不再搜索
            continue;
        }

        // 更改相邻顶点的颜色，然后递归搜索
        // 如果dfs函数返回false，则包含dfs函数的当前函数也返回false
        if (!dfs(G, next_v , 1 - cur)) return false;
    }
    return true;
}

int main() {
    // 顶点数和边数
    int N, M;
    cin >> N >> M;

    // 接收图的输入
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 开始搜索
    color.assign(N, -1);
    bool is_bipartite = true;
    for (int v = 0; v < N; ++v) {
        if (color[v] != -1) continue; // 如果v已经被访问，不进行搜索
        if (!dfs(G, v)) is_bipartite = false;
    }

    if (is_bipartite) cout << "Yes" << endl;
    else cout << "No" << endl;
}
