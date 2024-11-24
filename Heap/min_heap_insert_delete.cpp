#include <iostream>
using namespace std;

class MinHeap {
    public:
    int arr[100];
    int size;
    
    MinHeap()
    {
        arr[0] = -1;
        size = 0;
    }
    
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;
        
        while(index > 1)
        {
            int parent = index/2;
            if(arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }
    }
    
    void deleteFromMinHeap()
    {
        if(size < 1)
        {
            return;
        }
        
        swap(arr[1], arr[size]);
        size--;
        int i = 1;
        while(i < size)
        {
            int leftChild = i*2;
            int rightChild = i*2+1;
            if(leftChild < size && arr[leftChild] < arr[i])
            {
                swap(arr[leftChild], arr[i]);
                i = leftChild;
            }
            else if(rightChild < size && arr[rightChild] < arr[i])
            {
                swap(arr[rightChild], arr[i]);
                i = rightChild;
            }
            else return;
        }
    }
    
    void print()
    {
        for(int i = 1; i <= size; i++) cout << arr[i] << " ";
        cout << '\n';
    }
};


int main()
{
    MinHeap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromMinHeap();
    h.print();
    return 0;
}