#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

// 输入：图G和搜索的起点s
// 输出：表示从s到每个顶点的最短路径长度的数组
vector<int> BFS(const Graph &G, int s) {
    int N = (int)G.size(); // 顶点数
    vector<int> dist(N, -1); // 将所有顶点初始化为未被访问
    queue<int> que;

    // 初始条件（将顶点s作为起始顶点）
    dist[s] = 0;
    que.push(s); 

    // 开始BFS （直到队列为空为止）
    while (!que.empty()) {
        int v = que.front(); // 从队列中取出队首顶点
        que.pop();

        // 检查所有从可到达的顶点
        for (int x : G[v]) {
            // 不再搜索已经访问的顶点
            if (dist[x] != -1) continue; 

            // 对于新的未被访问顶点x，更新距离信息并将其插入队列
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main() {
    // 顶点数和边数
    int N, M;
    cin >> N >> M;

    // 输入图（这里假定是无向图）
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 以顶点0为起点的BFS
    vector<int> dist = BFS(G, 0);

    // 输出结果（查看每个顶点到顶点0的距离）
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}
