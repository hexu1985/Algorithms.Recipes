#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// �����������
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // ��Ƕ���vΪ�ѱ�����

    // �����ɴ��ÿ������next_v
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // ���next_v�ѱ����ʣ���������
        dfs(G, next_v); // �ݹ�ؽ�������
    }
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
    }

    // ��ʼ����
    seen.assign(N, false); // ��ʼ״̬�£����ж��㶼δ������
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // ����Ѿ������ʣ����ٽ�������
        dfs(G, v);
    }
}
