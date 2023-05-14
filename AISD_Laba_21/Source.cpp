#include <cstdio>
#include <iostream>
#include <conio.h>
#include <vector>
#include <time.h>
#include <chrono>

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
        clear();
    }

    binary_tree& operator=(const binary_tree& m) 
    {
        clear();
        root = copy(m.root);
        return *this;
    }

    void clear() 
    {
        clear_2(root);
        root = NULL;
    }

    void print()
    {
        if (root == NULL) std::cout << "Tree empty";
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

    void clear_2(Node* node)
    {
        if (node)
        {
            clear_2(node->left);
            clear_2(node->right);
            delete node;
        }
    }

    void print_2(Node* node)
    {
        if (node)
        {
            if (node->left)
            {
                std::cout << "( ";
                print_2(node->left);
                std::cout << ") ";
            }
            std::cout << node->key << " ";
            if (node->right)
            {
                std::cout << "( ";
                print_2(node->right);
                std::cout << ") ";
            }
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
            Node* temp = node;
            node = node->left;
            delete temp;
            return node;
        }

        if (!node->left) 
        {
            Node* temp = node;
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
                Node* temp_2 = temp->left;
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

size_t lcg() 
{
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

double time_filling(int number)
{
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 100; i++)
    {
        binary_tree Tree;
        for (int j = 0; j < number; j++)
        {
            Tree.insert(lcg());
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> result = end - start;
    return result.count() / 100;
}

double time_search(int number)
{
    binary_tree Tree;
    for (int j = 0; j < number; j++)
    {
        Tree.insert(lcg());
    }
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < 1000; i++)
    {
        if(!Tree.contains(lcg()));
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> result = end - start;
    return result.count()/1000;
}

double time_insert(int number)
{
    binary_tree Tree;
    for (int j = 0; j < number; j++)
    {
        Tree.insert(lcg());
    }
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < 1000; i++)
    {
        if (!Tree.insert(lcg()));
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> result = end - start;
    return result.count() / 1000;
}

double time_erase(int number)
{
    binary_tree Tree;
    for (int j = 0; j < number; j++)
    {
        Tree.insert(lcg());
    }
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < 1000; i++)
    {
        if (!Tree.erase(lcg()));
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> result = end - start;
    return result.count() / 1000;
}

double vec_time_filling(int number) 
{
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 100; i++)
    {
        std::vector<int> V;
        for (int j = 0; j < number; j++)
        {
            V.push_back(lcg());
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> result = end - start;
    return result.count() / 100;
}

double vec_time_search(int number)
{
    std::vector<int> V;
    for (int j = 0; j < number; j++)
    {
        V.push_back(lcg());
    }

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++)
    {
        V.push_back(lcg());
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> result = end - start;
    return result.count() / 1000;
}

double vec_time_insert(int number)
{
    std::vector<int> V;
    for (int j = 0; j < number; j++)
    {
        V.push_back(lcg());
    }

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++)
    {
        find(V.begin(), V.end(), lcg()) != V.end();
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> result = end - start;
    return result.count() / 1000;
}

double vec_time_erase(int number)
{
    std::vector<int> V;
    for (int j = 0; j < number; j++)
    {
        V.push_back(lcg());
    }

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++)
    {
        auto it = std::remove(V.begin(), V.end(), lcg());
        V.erase(it, V.end());
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> result = end - start;
    return result.count() / 1000;
}

std::vector<int> task(std::vector<int> V)
{
    binary_tree Tree;
    int x = V.size();
    for (int i = 0; i < x; i++)
    {
        if (!Tree.contains(V[i])) Tree.insert(V[i]);
        else
        {
            int z = V[i];
            while (find(V.begin(), V.end(), z) != V.end())
            {
                auto it = std::remove(V.begin(), V.end(), z);
                V.erase(it, V.end());
            }
            i = i - 2;
            x = V.size();
        }
    }
    return V;
}

void test_time()
{
    std::cout << "time filling of tree and vector\n";
    std::cout << time_filling(1000) << "   " << vec_time_filling(1000) << std::endl;
    std::cout << time_filling(10000) << "   " << vec_time_filling(10000) << std::endl;
    std::cout << time_filling(100000) << "   " << vec_time_filling(100000) << std::endl;

    std::cout << "time search of tree and vector\n";
    std::cout << time_search(1000) << "   " << vec_time_search(1000) << std::endl;
    std::cout << time_search(10000) << "   " << vec_time_search(10000) << std::endl;
    std::cout << time_search(100000) << "   " << vec_time_search(100000) << std::endl;

    std::cout << "time insert of tree and vector\n";
    std::cout << time_insert(1000) << "   " << vec_time_insert(1000) << std::endl;
    std::cout << time_insert(10000) << "   " << vec_time_insert(10000) << std::endl;
    std::cout << time_insert(100000) << "   " << vec_time_insert(100000) << std::endl;

    std::cout << "time erase of tree and vector\n";
    std::cout << time_erase(1000) << "   " << vec_time_erase(1000) << std::endl;
    std::cout << time_erase(10000) << "   " << vec_time_erase(10000) << std::endl;
    std::cout << time_erase(100000) << "   " << vec_time_erase(100000) << std::endl;
}

bool test_int(char* b)
{
    if (*b == '-') b++;
    if (*b == 0) return false;
    if (*b == '0' && *(b + 1) != 0) return false;
    while (*b)
    {
        if (*b < '0' || *b>'9') return false;
        b++;
    }
    return true;
}

int scan()
{
    while (true)
    {
        char* str = new char[256];
        std::cin.getline(str, 256);
        if (test_int(str))
        {
            int x = atoi(str);
            delete[] str;
            return x;
        }
        else puts("Wrong data");
        delete[]str;
    }
}

int main()
{
    binary_tree Tree;
    while (true)
    {
        system("cls");
        std::cout << "1 - Add element to the tree" << std::endl;
        std::cout << "2 - Delete element from tree" << std::endl;
        std::cout << "3 - Task" << std::endl;
        std::cout << "4 - Element search" << std::endl;
        std::cout << "5 - Print" << std::endl;
        std::cout << "6 - Delete tree" << std::endl;
        std::cout << "7 - Time test" << std::endl;
        std::cout << "8 - Exit" << std::endl;
        int z = getch();
        system("cls");

        if (z == '1')
        {
            std::cout << "Enter value" << std::endl;
            int value = scan();
            if (!Tree.insert(value))
            {
                std::cout << "Error! Cannot add the same values to the tree" << std::endl;
                if (getch()) z = '0';
            }
            system("cls");
        }

        if (z == '2')
        {
            std::cout << "Enter value" << std::endl;
            int value = scan();
            if (!Tree.erase(value))
            {
                std::cout << "Error! The tree does not contain such a value" << std::endl;
                if (getch()) z = '0';
            }
        }

        if (z == '3')
        {
            std::cout << "Enter the number of elements" << std::endl;
            int number = scan();
            std::vector<int> V(number);
            std::cout << "Enter elements" << std::endl;
            for (int i = 0; i < number; i++)
            {
                std::cout <<"V["<<i+1<<"]: ";
                V[i] = scan();
            }
            std::cout << "Start Vector" << std::endl;
            for (int i = 0; i < V.size(); i++)
            {
                std::cout << V[i] <<" ";
            }
            std::cout << "\n";
            V = task(V);

            std::cout << "End Vector" << std::endl;
            for (int i = 0; i < V.size(); i++)
            {
                std::cout << V[i] << " ";
            }
            if (getch()) z = '0';
        }

        if (z == '4')
        {
            std::cout << "Enter value" << std::endl;
            int value = scan();
            if (Tree.contains(value)) std::cout << "The tree contains the given element" << std::endl;
            else std::cout << "The tree does not contain this element" << std::endl;
            if (getch()) z = '0';
        }

        if (z == '5')
        {
            Tree.print();
            if (getch()) z = '0';
        }

        if (z == '6')
        {
            Tree.clear();
        }

        if (z == '7')
        {
            test_time();
            if (getch()) z = '0';
        }
        if (z == '8') return 0;
    }
}