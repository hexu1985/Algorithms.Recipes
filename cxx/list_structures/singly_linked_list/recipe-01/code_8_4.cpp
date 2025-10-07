#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 表示链表中每个节点的结构体
struct Node {
    Node* next; // 下一个节点指向哪个节点
    string name; // 与节点关联的值

    Node(string name_ = "") : next(NULL), name(name_) { }
};

// 将表示哨兵的节点放置在全局范围内
Node* nil;

// 初始化
void init() {
    nil = new Node();
    nil->next = nil; // 在初始状态下，让nil指向自己(nil)
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
// 将节点p的默认参数设置为nil
// 因此，调用insert(v)的操作表示将v插入链表的开头
void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next = v;
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

    // 生成每个节点，并将它们逐个插入链表的开头
    for (int i = 0; i < (int)names.size(); ++i) {
        // 创建节点
        Node* node = new Node(names[i]);

        // 将创建的节点插入链表的开头
        insert(node);

        // 输出每个步骤中链表的状态
        cout << "step " << i << ": ";
        printList();
    }
}
