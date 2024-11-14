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

void deletePos(int pos)
{
    Node* temp = head;
    if(pos == 0)
    {
        head = temp->next;
        return;
    }
    
    for(int i = 1; i < pos && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    
    temp->next = temp->next->next;
    
}
void clear()
{
    head = NULL;
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
    deletePos(0);
    print();
    return 0;
}


// Time Complexity -> O(N)
// begin -> O(1)