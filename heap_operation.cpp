#include <iostream>
#include <vector>
using namespace std;
void insert_min_heap(vector<int> &heap, int size)
{
    int curr = size;
    while (curr / 2 > 0 and heap[curr / 2] > heap[curr])
    {
        swap(heap[curr], heap[curr / 2]);
        curr = curr / 2;
    }
}
void insert_max_heap(vector<int> &heap, int size)
{
    int curr = size;
    while (curr / 2 > 0 and heap[curr / 2] < heap[curr])
    {
        swap(heap[curr], heap[curr / 2]);
        curr = curr / 2;
    }
}
void insert(vector<int> &heap, int size, int x)
{
    heap.push_back(x);
    size++;
    insert_max_heap(heap, size);//if we need to insert in max heap
    insert_max_heap(heap,size);//for min heap
}
void delete_min_heap(vector<int> &heap, int size)
{
    int curr = 1;
    while (2 * curr <= size)
    {
        int leftchild = curr * 2;
        int rightchild = 2 * curr + 1;
        int min = leftchild;
        if (rightchild <= size and heap[min] > heap[rightchild])
        {
            min = rightchild;
        }
        if (heap[min] >= heap[curr])
        {
            return;
        }
        swap(heap[min], heap[curr]);
        curr = min;
    }
}
void delete_max_heap(vector<int> &heap, int size)
{
    int curr = 1;
    while (2 * curr <= size)
    {
        int leftchild = curr * 2;
        int rightchild = 2 * curr + 1;
        int min = leftchild;
        if (rightchild <= size and heap[min] < heap[rightchild])
        {
            min = rightchild;
        }
        if (heap[min] <= heap[curr])
        {
            return;
        }
        swap(heap[min], heap[curr]);
        curr = min;
    }
}
void delt(vector<int> &heap, int size)
{
    swap(heap[1], heap[size]);
    heap.pop_back();
    size--;
    delete_max_heap(heap, size);
}
void heapify_max(vector<int> &heap, int size, int curr)
{

    while (2 * curr <= size)
    {
        int leftchild = 2 * curr;
        int rightchild = 2 * curr + 1;
        int min = curr;
        if (leftchild <= size and heap[min] < heap[leftchild])
        {
            min = leftchild;
        }
        if (rightchild <= size and heap[min] < heap[rightchild])
        {
            min = rightchild;
        }
        if (min == curr)
        {
            return;
        }
        swap(heap[min], heap[curr]);
        curr = min;
    }
    return;
}
void heapify_min(vector<int> &heap, int size, int curr)
{
    while (true)
    {
        int leftchild = 2 * curr;
        int rightchild = 2 * curr + 1;
        int min = curr;

        // Check if left child exists and is greater than the current maximum
        if (leftchild <= size && heap[leftchild] < heap[min])
        {
            min = leftchild;
        }

        // Check if right child exists and is greater than the current maximum
        if (rightchild <= size && heap[rightchild] < heap[min])
        {
            min = rightchild;
        }

        // If the maximum is the current node itself, the heap property is restored
        if (min == curr)
        {
            return;
        }

        // Swap the current node with the maximum child and continue the process
        swap(heap[min], heap[curr]);
        curr = min;
    }
}
void heap_sort_inc(vector<int> &heap, int size)
{
    for (int i = size / 2; i > 0; i--)
    {
        heapify_max(heap, size, i);
    }
    swap(heap[size], heap[1]);
}
void heap_sort_dec(vector<int> &heap, int size)
{
    for (int i = size / 2; i > 0; i--)
    {
        heapify_min(heap, size, i);
    }
    swap(heap[size], heap[1]);
}

int main()
{
    // vector<int> heap = {-1,1,2,3,4,5,6,7};//min
    // vector<int> heap = {-1,7,6,5,4,3,2,1};//max
    vector<int> heap = {-1, 3, 2, 5, 1, 7, 25, 4};
    int size = heap.size() - 1;
    cout << "Original vector        ";
    for (auto next : heap)
    {
        cout << next << " ";
    }
    for (int i = size; i > 1; i--)
    {
        heap_sort_inc(heap, i);
    }

    cout << endl;
    cout << "Sorted in inc order    ";
    // insert(heap,size,332);
    // delt(heap,size);
    for (auto next : heap)
    {
        cout << next << " ";
    }
    for (int i = size; i > 1; i--)
    {
        heap_sort_dec(heap, i);
    }
    
    cout << endl;
    cout << "Sorted in dec order    ";
    for (auto next : heap)
    {
        cout << next << " ";
    }
    return 0;
}
