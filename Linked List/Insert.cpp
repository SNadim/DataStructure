#include <iostream>
#include <vector>
using namespace std;

struct Node{
  int val;
  Node* next;
  Node() : val(0), next(nullptr) {}
  Node(int x) : val(x),next(nullptr) {}
  Node(int x, Node* next): val(x), next(next){}
};

Node* head = NULL;

void insert(int x)
{
    Node* newNode = new Node(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertPos(int x, int pos)
{
    Node* newNode = new Node(x);
    Node* temp = head;
    if(pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    for(int i = 1; i < pos && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    
    Node* temp2 = temp->next;
    temp->next = newNode;
    newNode->next = temp2;
    
}

void print()
{
    Node* temp = head;
    
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << '\n';
}

int main() {
    vector<int> nums = {1,2,3,4};
    for(auto i : nums)
    {
        insert(i);
    }
    
    print();
    insertPos(5, 2);
    print();
    insertPos(7, 5);
    print();
    insertPos(9, 10);
    print();
    return 0;
}


// Time complexity
// Insert O(N)
// Insert begin O(1)