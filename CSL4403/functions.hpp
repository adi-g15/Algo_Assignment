#include <vector>
#include <algorithm>

using namespace std;    // class ke liye krna padta hai ye :-(
                        // Bahut ganda lagda h ye type krte hue ;(

typedef vector<int> Array;

int partition(vector<int>& v, int start, int end)
{
    int pivot = v[end];
    int p_index = start;
    static int tmp;

    for (int i = start;i < end;i++)
    {
        if (v[i] <= pivot)
        {
            tmp = v[i];
            v[i] = v[p_index];
            v[p_index] = tmp;
            p_index++;
        }
    }
    tmp = v[end];
    v[end] = v[p_index];
    v[p_index] = tmp;

    return p_index;
}

void quick_sort(vector<int>& v, int start, int end)
{
    if (start >= end)  return;

    int index = partition(v, start, end);
    quick_sort(v, start, index - 1);
    quick_sort(v, index + 1, end);
}

template <class Iter>
void quick_sort(Iter first, Iter last) {
    if (first == last) return;
    auto pivot = *std::next(first, std::distance(first, last) / 2);

    auto middle1 = partition(first, last,
        [pivot](auto& em) { return em < pivot; });

    auto middle2 = partition(middle1, last,
        [pivot](auto& em) { return !(pivot < em); });

    quick_sort(first, middle1);
    quick_sort(middle2, last);
}

int binary_search(vector<int>& v, int number) {
    int start = 0;
    int end = v.size() - 1;
    int mid;

    while (start != end)
    {
        mid = start + (end - start) / 2;   // PROBLEM -> Whenever end == start, it will check with equality with v[0] always
        if (number == v[mid])
        {
            return mid;
        }
        else if (number < v[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return number == v[start] ? start : -1;
}

void merge(Array& arr, int l, int m, int r)
{
    Array L(arr.begin() + l, arr.begin() + m+1), 
        R(arr.begin() + m + 1, arr.begin() + r+1);

    r -= (m + 1); // set r to length of R, (ie. be the difference b/w start and end of second range now)
    m -= l;

    auto k = l;
    int l2 = 0;
    l = 0;
    for (; l <= m && l2 <= r; k++)
    {
        if (L[l] < R[l2]) {
            arr[k] = L[l++];
        }
        else {
            arr[k] = R[l2++];
        }
    }

    while (l <= m)
        arr[k++] = L[l++];

    while (l2 <= r)
        arr[k++] = R[l2++];
}

void merge_sort(Array& vec, int l, int r) {
    if (l >= r)    return;   // not l >= r, so that it doesn't ignore last element 

    //auto mid = l + (r - l) / 2;
    auto mid = (l + r) / 2;

    merge_sort(vec, l, mid);
    merge_sort(vec, mid+1, r);

    merge(vec, l, mid, r);
}
