//Heap Sort
#include <bits/stdc++.h>
using namespace std;
class Heap
{
    int size = 0, heap[100000];

public:
    void Insert(int a)
    {
        heap[++size] = a;
        int n = size;
        while (n > 1)
        {
            if (heap[n / 2] < heap[n])
            {
                swap(heap[n / 2], heap[n]);
            }
            else
                break;
            n = n / 2;
        }
    }
    void Display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        swap(heap[1], heap[size]);
        size--;
        int i = 1;
        while (2 * i <= size)
        {
            int largest = i;
            if (heap[2 * i] > heap[largest])
            {
                largest = 2 * i;
            }
            if (2 * i + 1 <= size and heap[2 * i + 1] > heap[largest])
            {
                largest = 2 * i + 1;
            }

            if (largest == i)
                break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
    void Sort()
    {
        while (size != 0)
        {
            cout << heap[1] << " ";
            Delete();
        }
        //  cout<<endl;
    }
};
int main()
{
    Heap h;
    for (int i = 0; i < 8; i++)
    {
        int x;
        cin >> x;
        h.Insert(x);
    }
    h.Display();
    h.Sort();
}