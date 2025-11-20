#include <iostream>
#include <string>
using namespace std;


class TourNode {
public:
    string packageName;
    TourNode* left;
    TourNode* right;

    TourNode(string name) 
    {
        packageName = name;
        left = nullptr;
        right = nullptr;
    }
};


class TourTree {
private:
    TourNode* root;

    TourNode* insert(TourNode* node, string name) 
    {
        if (node == nullptr) 
        {
            return new TourNode(name);
        }

        char choice;
        cout << "Where do you want to insert \"" << name 
             << "\" under \"" << node->packageName 
             << "\"? (L for left, R for right): ";
        cin >> choice;

        if (choice == 'L' || choice == 'l') 
        {
            node->left = insert(node->left, name);
        } 
        else 
        {
            node->right = insert(node->right, name);
        }

        return node;
    }


    void display(TourNode* node, int level) 
    {
        if (node == nullptr) return;

        display(node->right, level + 1);

        for (int i = 0; i < level; i++) 
            cout << "    ";

        cout << node->packageName << endl;

        display(node->left, level + 1);
    }

public:
    TourTree() 
    {
        root = nullptr;
    }

    void addPackage(string name) 
    {
        if (root == nullptr) 
        {
            root = new TourNode(name);
        } 
        else 
        {
            insert(root, name);
        }
    }


    void displayTree() 
    {
        cout << "\n--- TOUR PACKAGE HIERARCHY ---\n";
        display(root, 0);
    }
};


int main() 
{
    TourTree tree;

    int choice;
    string packageName;

    while (true) 
    {
        cout << "\n1. Add New Tour Package\n2. Display Tour Hierarchy\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();  

        if (choice == 1) 
        {
            cout << "Enter package name: ";
            getline(cin, packageName);
            tree.addPackage(packageName);
        }
        else if (choice == 2) 
        {
            tree.displayTree();
        }
        else if (choice == 3) 
        {
            break;
        }
        else 
        {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
