#include <fstream>

class Tree {
    public:
        class Node {
            public:
                int key;
                Node *left;
                Node *right;
                Node(int key) : key(key) {
                    left = nullptr;
                    right = nullptr;
                }
        };

        Tree() {this->root = nullptr;}
        void insert(int key) {
            Node **cur = &this->root;
            while(*cur) {
                Node *node = *cur;
                if(key < node->key) {
                    cur = &node->left;
                } else if (key > node->key) {
                    cur = &node->right;
                } else {
                    return;
                }
            }
            *cur = new Node(key);
        }

        void preOrderTraversal(Node *node, std::ofstream& output) {
            if(node) {
                output << node->key << '\n';
                preOrderTraversal(node->left, output);
                preOrderTraversal(node->right, output);
            }
        }
        Node *root;
};



int main() {
    Tree tree;
    std::ifstream input("input.txt");
    int tmp;
    while(input >> tmp) {
        tree.insert(tmp);
    }
    std::ofstream output("output.txt");
    tree.preOrderTraversal(tree.root, output);
    input.close();
    output.close();
}

