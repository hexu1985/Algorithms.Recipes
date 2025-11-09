#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

// 执行拓扑排序
vector<bool> seen;
vector<int> order; // 表示拓扑排序的顺序
void rec(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // 如果v已经被访问，不再进行搜粟
        rec(G, next_v);
    }

    // 记录 v-out 的值
    order.push_back(v);
}

int main() {
    int N, M;
    cin >> N >> M; // 顶点数和边数
    Graph G(N); // 包含 N 个顶点的图
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 开始搜索
    seen.assign(N, false); // 初始状态下，所有顶点均未被访问
    order.clear(); // 拓扑排序的顺序
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // 如果已经访问，不再进行搜索
        rec(G, v);
    }
    reverse(order.begin(), order.end()); // 将结果逆序

    // 输出
    for (auto v : order) cout << v << " -> ";
    cout << endl;
}
