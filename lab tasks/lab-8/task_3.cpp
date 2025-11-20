#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        char choice;
        cout << "Insert " << value << " to Left(L) or Right(R) of " << node->data << "? ";
        cin >> choice;

        if (choice == 'L' || choice == 'l')
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    bool isFull(Node* node) {
        if (node == nullptr)
            return true;

        if (node->left == nullptr && node->right == nullptr)
            return true;

        if (node->left != nullptr && node->right != nullptr)
            return isFull(node->left) && isFull(node->right);

        return false;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void addNode(int value) {
        if (root == nullptr)
            root = new Node(value);
        else
            root = insert(root, value);
    }

    void checkFullTree() {
        if (isFull(root))
            cout << "\nThe tree IS a Full Binary Tree.\n";
        else
            cout << "\nThe tree is NOT a Full Binary Tree.\n";
    }
};

int main() {
    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "\n1. Add Node\n2. Check if Full Binary Tree\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            tree.addNode(value);
        }
        else if (choice == 2) {
            tree.checkFullTree();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
