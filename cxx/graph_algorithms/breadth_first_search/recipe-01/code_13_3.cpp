#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

// ���룺ͼG�����������s
// �������ʾ��s��ÿ����������·�����ȵ�����
vector<int> BFS(const Graph &G, int s) {
    int N = (int)G.size(); // ������
    vector<int> dist(N, -1); // �����ж����ʼ��Ϊδ������
    queue<int> que;

    // ��ʼ������������s��Ϊ��ʼ���㣩
    dist[s] = 0;
    que.push(s); 

    // ��ʼBFS ��ֱ������Ϊ��Ϊֹ��
    while (!que.empty()) {
        int v = que.front(); // �Ӷ�����ȡ�����׶���
        que.pop();

        // ������дӿɵ���Ķ���
        for (int x : G[v]) {
            // ���������Ѿ����ʵĶ���
            if (dist[x] != -1) continue; 

            // �����µ�δ�����ʶ���x�����¾�����Ϣ������������
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main() {
    // �������ͱ���
    int N, M;
    cin >> N >> M;

    // ����ͼ������ٶ�������ͼ��
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // �Զ���0Ϊ����BFS
    vector<int> dist = BFS(G, 0);

    // ���������鿴ÿ�����㵽����0�ľ��룩
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}
