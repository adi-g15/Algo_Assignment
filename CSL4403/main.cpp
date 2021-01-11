#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.hpp"
#include "util.hpp"

using namespace std;

vector<int> v;
int tmp;

int main(){
    int n, search_num;

    cout << "Enter Number of elements, then elements: ";
    //cin >> n;

    //v.resize(n);
    //for( auto i = 0; i < n; i++ )    cin >> v[i];
    v = { 45, 753, 2, 3, 77, 56 };
    n = 6;

    cout << "\nBefore Sorting: ";
    for( auto i = 0; i < n; i++ )    cout << v[i] << ' ';

    quick_sort(v, 0, n-1);

    cout << "\nAfter Sorting: ";
    for( auto i = 0; i < n; i++ )    cout << v[i] << ' ';

    cout << "\nEnter number to search: ";
    cin >> search_num;
    cout << "\nTo search: " << search_num;

    auto index = binary_search(v, search_num);
    if (index < 0)
        cout << "\nNot Found";
    else  cout << "\nFound at " << index;

    return 0;
}