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
};



int main()
{

}