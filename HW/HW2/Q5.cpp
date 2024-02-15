#include <vector>
#include <iostream>

template<typename T>
struct Node {
    Node<T>* left;
    Node<T>* right;
    T obj;

    Node(T obj, Node<T>* left = nullptr, Node<T>* right = nullptr) : obj(obj), left(left), right(right) {}
};

template<typename T>
int count_filled_nodes(const Node<T>* node) {
    if (node->left != nullptr && node->right != nullptr)
        return 1 + count_filled_nodes(node->left) + count_filled_nodes(node->right);
    if (node->left != nullptr)
        return count_filled_nodes(node->left) + 0;
    if (node->right != nullptr)
        return count_filled_nodes(node->right) + 0;
    return 0;
}

int main() {
    Node<int>* root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);
    root->left->left = new Node<int>(4);
    root->left->right = new Node<int>(5);
    root->right->left = new Node<int>(6);

    std::cout << "Number of nodes with two children: " << count_filled_nodes(root) << std::endl;

}