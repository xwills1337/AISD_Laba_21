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

        Node& operator=(const Node& m)
        {
            key = m.key;
            left = m.left;
            right = m.right;
            return *this;
        }
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

    bool insert(int key) 
    {
        return insert_2(root, key);
    }

    bool contains(int key) 
    {
        return contains_2(root, key);
    }

    bool erase(int key)
    {
        return erase_2(root, key);
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

    bool insert_2(Node*& node, int key) 
    {
        if (!node) 
        {
            node = new Node(key);
            return true;
        }
        else
        {
            if (key < node->key) return insert_2(node->left, key);
            else
            {
                if (key > node->key) return insert_2(node->right, key);
                else return false;
            }
        }
    }

    bool contains_2(Node* node, int key) 
    {
        if (!node)
        {
            return false;
        }
        else
        {
            if (key < node->key) return contains_2(node->left, key);
            else
            {
                if (key > node->key) return contains_2(node->right, key);
                else return true;
            }
        }
    }

    bool erase_2(Node*& node, int key)
    {
        if (!node)
        {
            return false;
        }
        else
        {
            if (key < node->key) return erase_2(node->left, key);
            else
            {
                if (key > node->key) return erase_2(node->right, key);
                else 
                {
                    node = delete_node(node);
                    return true;
                }
            }
        }
    }

    Node* delete_node(Node*& node)
    {
        if (!node->left && !node->right) 
        {
            delete node;
            node = NULL;
            return node;
        }

        if (!node->right) 
        {
            Node* temp = node->left;
            node = node->left;
            delete temp;
            return node;
        }

        if (!node->left) 
        {
            Node* temp = node->right;
            node = node->right;
            delete temp;
            return node;
        }

        Node* temp = node->right;

        if (temp->left != NULL)
        {
            while (temp->left->left != NULL) temp = temp->left;
            if (!temp->left->right)
            {
                node->key = temp->left->key;
                delete temp->left;
                temp->left = NULL;
            }
            else
            {
                node->key = temp->left->key;
                Node* temp_2 = temp->left->right;
                temp->left = temp->left->right;
                delete temp_2;
            }
        }
        else
        {
            node->key = temp->key;
            node->right = temp->right;
            delete temp;
        }
        
        return node;
    }
};



int main()
{

}