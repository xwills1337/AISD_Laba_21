#include<cstdio>
#include<iostream>
#include<conio.h>
#include<vector>

class binary_tree
{
public:

    struct Node
    {
        int key;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(NULL), right(NULL) {}
    };
    
    binary_tree() : root(NULL) {}

    binary_tree(const binary_tree& m) : root(copy(m.root)) {}

    ~binary_tree()
    {
        clear(root);
    }

    binary_tree& operator=(const binary_tree& m) 
    {
        clear(root);
        root = copy(m.root);
        return *this;
    }

    void clear(Node* node) 
    {
        if (node) 
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
    void print()
    {
        print_2(root);
    }
private:

    Node* root;
    Node* copy(Node* node) 
    {
        if (!node) return NULL;
        Node* new_node = new Node(node->key);
        new_node->left = copy(node->left);
        new_node->right = copy(node->right);
        return new_node;
    }

    void print_2(Node* node)
    {
        if (node)
        {
            print_2(node->left);
            print_2(node->right);
            std::cout << node->key << " ";
        }
    }
};



int main()
{

}