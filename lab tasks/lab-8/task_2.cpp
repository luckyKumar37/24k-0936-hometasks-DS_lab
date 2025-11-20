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


    Node* insert(Node* node, int value) 
    {
        if (node == nullptr) 
        {
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


    int countNodes(Node* node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }


    int countLeafNodes(Node* node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr)
            return 1;
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }


    int height(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
public:
    BinaryTree() 
    {
        root = nullptr;
    }

    void addNode(int value) {
        if (root == nullptr)
            root = new Node(value);
        else
            root = insert(root, value);
    }


    void displayProperties() {
        cout << "\n--- TREE PROPERTIES ---\n";
        cout << "Total Nodes       : " << countNodes(root) << endl;
        cout << "Leaf Nodes        : " << countLeafNodes(root) << endl;
        cout << "Height of Tree    : " << height(root) << endl;
    }
};

int main() 
{
    BinaryTree tree;
    int choice, value;
    while (true) 
    {
        cout << "\n1. Insert Node\n2. Display Tree Properties\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            tree.addNode(value);
        }
        else if (choice == 2) {
            tree.displayProperties();
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
