#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "functions.hpp"
#include "util.hpp"

using namespace std;

vector<int> v;
int tmp;

std::list<int*> l3;
std::vector<int*> v3;
std::string s3;
int main(){
    int n, search_num;

    std::list<int*> l1;
    std::vector<int*> v1;
    std::string s1;
    std::list<int*> l2;
    std::vector<int*> v2;
    std::string s2;

    std::cout << sizeof(l1) << " " << sizeof(l2) << " " << sizeof(l3) << "\n";  // 24D, 16R
    std::cout << sizeof(v1) << " " << sizeof(v2) << " " << sizeof(v3) << "\n";  // 32D, 24R
    std::cout << sizeof(s1) << " " << sizeof(s2) << " " << sizeof(s3) << "\n";  // 40D, 32R

    cout << "Enter Number of elements, then elements:  6";
    //cin >> n;

    //v.resize(n);
    //for( auto i = 0; i < n; i++ )    cin >> v[i];
    v = { 45, 753, 2, 3, 77, 56 };
    n = 6;

    cout << "\nBefore Sorting: ";
    for( auto i = 0; i < n; i++ )    cout << v[i] << ' ';

    merge_sort(v, 0, n-1);

    cout << "\nAfter Sorting: ";
    for( auto i = 0; i < n; i++ )    cout << v[i] << ' ';
    cout << '\n';

    //cout << "\nEnter number to search: ";
    //cin >> search_num;
    //cout << "\nTo search: " << search_num;

    //auto index = binary_search(v, search_num);
    //if (index < 0)
    //    cout << "\nNot Found";
    //else  cout << "\nFound at " << index;

    return 0;
}