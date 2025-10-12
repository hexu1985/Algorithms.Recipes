#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ��ʾ������ÿ���ڵ�Ľṹ��
struct Node {
    Node *prev, *next;
    string name; // ��ڵ������ֵ

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) { }
};

// ����ʾ�ڱ��Ľڵ������ȫ�ַ�Χ��
Node* nil;

// ��ʼ��
void init() {
    nil = new Node();
    nil->prev = nil; 
    nil->next = nil;
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
void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

// ɾ���ڵ�
void erase(Node *v) {
    if (v == nil) return; // ���v���ڱ��ڵ㣬��ִ���κβ���
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v; // �ͷ��ڴ�
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

    // ������������ÿ���ڵ㲢�����������Ŀ�ͷ
    Node *watanabe;
    for (int i = 0; i < (int)names.size(); ++i) {
        // �����ڵ�
        Node* node = new Node(names[i]);

        // �������Ľڵ��������Ŀ�ͷ
        insert(node);

        // ����"watanabe"�ڵ�
        if (names[i] == "watanabe") watanabe = node;
    }

    // ɾ��"watanabe"�ڵ�
    cout << "before: ";
    printList(); // ���ɾ��ǰ��״̬
    erase(watanabe);
    cout << "after: ";
    printList(); // ���ɾ�����״̬
}
