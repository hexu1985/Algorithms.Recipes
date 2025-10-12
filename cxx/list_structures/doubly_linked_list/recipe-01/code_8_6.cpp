#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 表示链表中每个节点的结构体
struct Node {
    Node *prev, *next;
    string name; // 与节点关联的值

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) { }
};

// 将表示哨兵的节点放置在全局范围内
Node* nil;

// 初始化
void init() {
    nil = new Node();
    nil->prev = nil; 
    nil->next = nil;
}

// 输出链表的内容
void printList() {
    Node* cur = nil->next; // 从链表的头部开始
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// 在节点p之后插入节点v
void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

// 删除节点
void erase(Node *v) {
    if (v == nil) return; // 如果v是哨兵节点，则不执行任何操作
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v; // 释放内存
}

int main() {
    // 初始化
    init();

    // 想要创建的节点的名称列表
    // 注意，要从最后一个节点("yamamoto")开始逐个输入
    vector<string> names = {"yamamoto",
                            "watanabe",
                            "ito",
                            "takahashi",
                            "suzuki",
                            "sato"};

    // 创建链表：生成每个节点并将其插入链表的开头
    Node *watanabe;
    for (int i = 0; i < (int)names.size(); ++i) {
        // 创建节点
        Node* node = new Node(names[i]);

        // 将创建的节点插入链表的开头
        insert(node);

        // 保留"watanabe"节点
        if (names[i] == "watanabe") watanabe = node;
    }

    // 删除"watanabe"节点
    cout << "before: ";
    printList(); // 输出删除前的状态
    erase(watanabe);
    cout << "after: ";
    printList(); // 输出删除后的状态
}
