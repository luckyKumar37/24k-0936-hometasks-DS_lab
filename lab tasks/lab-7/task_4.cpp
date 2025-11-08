#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


void swap(Node* a, Node* b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd)
{
    Node* pivot = end;
    Node* prev = nullptr;
    Node* curr = head;
    Node* tail = pivot;

    while(curr != pivot)
    {
        if(curr->data < pivot->data)
        {
            if((*newHead) == nullptr)
                (*newHead) = curr;

            prev = curr;
            curr = curr->next;
        }
        else
        {
            if(prev)
                prev->next = curr->next;
            Node* tmp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = tmp;
        }
    }

    if((*newHead) == nullptr)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}


Node* quickSortRec(Node* head, Node* end)
{
    if(!head || head == end)
        return head;

    Node* newHead = nullptr;
    Node* newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if(newHead != pivot)
    {
        Node* tmp = newHead;
        while(tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quickSortRec(newHead, tmp);

        tmp = newHead;
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = pivot;
    }

    pivot->next = quickSortRec(pivot->next, newEnd);

    return newHead;
}


Node* getTail(Node* head)
{
    while(head && head->next)
        head = head->next;
    return head;
}


void push(Node** headRef, int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if(*headRef == nullptr)
    {
        *headRef = newNode;
        return;
    }

    Node* temp = *headRef;
    while(temp->next)
        temp = temp->next;
    temp->next = newNode;
}


void printList(Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr;
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++)
        push(&head, arr[i]);

    cout << "Original List:\n";
    printList(head);

    head = quickSortRec(head, getTail(head));

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}
