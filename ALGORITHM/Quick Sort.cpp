#include <bits/stdc++.h>
using namespace std;
int Partition(vector<int> &v, int low, int high)
{
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    i++;
    swap(v[i], v[high]);
    return i;
}
void quickSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int pivot_idx = Partition(v, low, high);
        quickSort(v, low, pivot_idx - 1);
        quickSort(v, pivot_idx + 1, high);
    }
}
int main()
{
    vector<int> v;
    for (int i = 0; i < 6; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    quickSort(v, 0, v.size() - 1);
    for (auto u : v)
    {
        cout << u << " ";
    }
}
