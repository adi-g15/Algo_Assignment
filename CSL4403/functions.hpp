#include <vector>
#include <algorithm>

using namespace std;    // class ke liye krna padta hai ye :-(
                        // Bahut ganda lagda h ye type krte hue ;(

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
