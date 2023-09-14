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
void insert(vector<int> &heap, int size, int x, string M)
{
    bool max, min;
    heap.push_back(x);
    size++;
    if (M == "max")
    {
        insert_max_heap(heap, size);
    }
    if (M == "min")
    {
        insert_min_heap(heap, size);
    }
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
int findkthsmllest(vector<int> heap, int k)
{
    if (k <= 0 or k > heap.size() - 1)
    {
        return 0;
    }
    int count = 0;
    int smallest = INT16_MAX;
    while (count < k)
    {
        smallest = heap[1];
        swap(heap[1], heap[heap.size() - 1]);
        heap.pop_back();
        heapify_min(heap, heap.size() - 1, 1);
        count++;
    }
    return smallest;
}

void merge_two_heap(vector<int> &heap1, vector<int> &heap2)
{
    for (int i = 1; i < heap2.size(); i++)
    {
        heap1.push_back(heap2[i]);
        int size = heap1.size() - 1;
        int curr = size;
        while (curr / 2 > 0 and heap1[curr] > heap1[curr / 2])
        {
            swap(heap1[curr], heap1[curr / 2]);
            curr = curr / 2;
        }
    }
}
int main()
{
    vector<int> heap = {-1,20,8,22,4,12,10,14};
    int k1 = 3+1 , k2 = 6+1;
    int k=k1+1;
    int sum=0;
    cout<<findkthsmllest(heap,5)<<endl;
    cout<<findkthsmllest(heap,6)<<endl;
    while(k<k2){
         sum+=findkthsmllest(heap,k);
         k++;
    }
    cout<<sum;
    return 0;
}
