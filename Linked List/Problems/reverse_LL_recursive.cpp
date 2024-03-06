#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *arrtoDLL(vector<int> &arr, int n)
{

    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *reverseRecursiveLL(Node *head)
{
    if (head == NULL || head->next == nullptr)
        return head;
    Node *newHead = reverseRecursiveLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    int n = arr.size();
    Node *head = arrtoDLL(arr, n);

    head = reverseRecursiveLL(head); // TC=O(N) & SC=O(N) (stack space)
    printDLL(head);

    return 0;
}