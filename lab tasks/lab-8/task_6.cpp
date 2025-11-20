#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->id)
            node->left = insert(node->left, value);
        else if (value > node->id)
            node->right = insert(node->right, value);
        return node;
    }

    Node* findLCA(Node* node, int a, int b) {
        if (!node) return nullptr;

        if (a < node->id && b < node->id)
            return findLCA(node->left, a, b);

        if (a > node->id && b > node->id)
            return findLCA(node->right, a, b);

        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    void insertEmployee(int value) {
        root = insert(root, value);
    }

    void lowestCommonManager(int a, int b) {
        Node* lca = findLCA(root, a, b);
        if (lca)
            cout << "Lowest Common Manager of " << a << " and " << b 
                 << " is: " << lca->id << endl;
        else
            cout << "Employees not found in hierarchy.\n";
    }
};

int main() {
    BST tree;
    int choice, id, a, b;

    while (true) {
        cout << "\n1. Add Employee\n2. Find Lowest Common Manager\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Employee ID: ";
            cin >> id;
            tree.insertEmployee(id);
        }
        else if (choice == 2) {
            cout << "Enter first Employee ID: ";
            cin >> a;
            cout << "Enter second Employee ID: ";
            cin >> b;
            tree.lowestCommonManager(a, b);
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
