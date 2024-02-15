#include <iostream>

template<typename T>
struct Node {
    Node* next;
    T obj;

    Node(T obj, Node* next = nullptr)
        : obj(obj), next(next)
    { }
};

template<typename T>
int count_nodes(Node<T>* node) {
    if (node == nullptr)
        return 0;
    return 1 + count_nodes(node->next);    
}

int main() {
    Node<int>* head = nullptr;
    std::cout << "Number of nodes: " << count_nodes(head) << std::endl;

}