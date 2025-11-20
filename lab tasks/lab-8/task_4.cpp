#include <iostream>
#include <queue>
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

class CompleteBinaryTree {
private:
    Node* root;

    Node* insertComplete(Node* root, int value) 
    {
        Node* newNode = new Node(value);
        if (!root) return newNode;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = newNode;
                return root;
            } else q.push(temp->left);

            if (!temp->right) {
                temp->right = newNode;
                return root;
            } else q.push(temp->right);
        }
        return root;
    }

    void displaySubtree(Node* node)
     {
        if (!node) return;
        cout << node->data << " ";
        displaySubtree(node->left);
        displaySubtree(node->right);
    }

    int findSubtree(Node* node, int target, bool &found, Node* &result) 
    {
        if (!node) return 0;

        int leftSum = findSubtree(node->left, target, found, result);
        int rightSum = findSubtree(node->right, target, found, result);

        int total = node->data + leftSum + rightSum;

        if (total == target && !found) {
            found = true;
            result = node;
        }
        return total;
    }

public:
    CompleteBinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertComplete(root, value);
    }

    void findSubtreeWithSum(int target) {
        bool found = false;
        Node* result = nullptr;

        findSubtree(root, target, found, result);

        if (found) 
        {
            cout << "\nSubtree with sum " << target << " found:\n";
            displaySubtree(result);
            cout << endl;
        } else 
        {
            cout << "\nNo subtree found with sum = " << target << endl;
        }
    }
};

int main() 
{
    CompleteBinaryTree tree;
    int choice, value, target;

    while (true) 
    {
        cout << "\n1. Insert Node\n2. Find Subtree With Given Sum\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
        }
        else if (choice == 2) 
        {
            cout << "Enter target sum: ";
            cin >> target;
            tree.findSubtreeWithSum(target);
        }
        else if (choice == 3) 
        {
            break;
        }
        else
        {
            cout << "Invalid option!\n";
        }
    }
    return 0;
}
