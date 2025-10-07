#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ��ʾ������ÿ���ڵ�Ľṹ��
struct Node {
    Node* next; // ��һ���ڵ�ָ���ĸ��ڵ�
    string name; // ��ڵ������ֵ

    Node(string name_ = "") : next(NULL), name(name_) { }
};

// ����ʾ�ڱ��Ľڵ������ȫ�ַ�Χ��
Node* nil;

// ��ʼ��
void init() {
    nil = new Node();
    nil->next = nil; // �ڳ�ʼ״̬�£���nilָ���Լ�(nil)
}

// ������������
void printList() {
    Node* cur = nil->next; // �������ͷ����ʼ
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// �ڽڵ�p֮�����ڵ�v
// ���ڵ�p��Ĭ�ϲ�������Ϊnil
// ��ˣ�����insert(v)�Ĳ�����ʾ��v��������Ŀ�ͷ
void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next = v;
}

int main() {
    // ��ʼ��
    init();

    // ��Ҫ�����Ľڵ�������б�
    // ע�⣬Ҫ�����һ���ڵ�("yamamoto")��ʼ�������
    vector<string> names = {"yamamoto",
                            "watanabe",
                            "ito",
                            "takahashi",
                            "suzuki",
                            "sato"};

    // ����ÿ���ڵ㣬�������������������Ŀ�ͷ
    for (int i = 0; i < (int)names.size(); ++i) {
        // �����ڵ�
        Node* node = new Node(names[i]);

        // �������Ľڵ��������Ŀ�ͷ
        insert(node);

        // ���ÿ�������������״̬
        cout << "step " << i << ": ";
        printList();
    }
}
