#include <iostream>
using namespace std;

class Node {
public:
    int productID;
    int quantity;
    Node* left;
    Node* right;

    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int id, int qty) {
        if (node == nullptr) return new Node(id, qty);

        if (id < node->productID)
            node->left = insert(node->left, id, qty);
        else if (id > node->productID)
            node->right = insert(node->right, id, qty);
        else
            node->quantity = qty;

        return node;
    }

    Node* search(Node* node, int id) {
        if (!node || node->productID == id) return node;
        if (id < node->productID) return search(node->left, id);
        return search(node->right, id);
    }

    void findMaxQuantity(Node* node, Node* &maxNode) {
        if (!node) return;
        if (!maxNode || node->quantity > maxNode->quantity)
            maxNode = node;
        findMaxQuantity(node->left, maxNode);
        findMaxQuantity(node->right, maxNode);
    }

public:
    BST() {
        root = nullptr;
    }

    void addProduct(int id, int qty) {
        root = insert(root, id, qty);
    }

    void searchProduct(int id) {
        Node* result = search(root, id);
        if (result)
            cout << "Product Found - ID: " << result->productID
                 << ", Quantity: " << result->quantity << endl;
        else
            cout << "Product not found.\n";
    }

    void productWithHighestQuantity() {
        Node* maxNode = nullptr;
        findMaxQuantity(root, maxNode);
        if (maxNode)
            cout << "Product with highest quantity:\nID: "
                 << maxNode->productID << ", Quantity: "
                 << maxNode->quantity << endl;
        else
            cout << "No products available.\n";
    }
};

int main() {
    BST tree;
    int choice, id, qty;

    while (true) {
        cout << "\n1. Add/Update Product\n2. Search Product\n3. Highest Quantity Product\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Quantity: ";
            cin >> qty;
            tree.addProduct(id, qty);
        }
        else if (choice == 2) {
            cout << "Enter Product ID to search: ";
            cin >> id;
            tree.searchProduct(id);
        }
        else if (choice == 3) {
            tree.productWithHighestQuantity();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid option.\n";
        }
    }
    return 0;
}
