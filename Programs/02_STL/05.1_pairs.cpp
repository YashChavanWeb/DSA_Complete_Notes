// STL - Standard Template Library
// -> it is a compilation of algorithms, containers, functions, etc in a minimized version

#include <bits/stdc++.h>
using namespace std;

// C++ STL is divided into 4 parts
// 1. Algorithms
// 2. Containers
// 3. Functions
// 4. Iterators

int main()
{
    // Pairs - lies in the utility library
    pair<int,int> p = {1,3};
    cout<<p.first<<" "<<p.second<<endl;

    pair<int, pair<int, int>> a = {1,{3,4}};
    cout<<a.first<<" "<<a.second.first<<" "<<a.second.second<<endl;

    pair<int, int> arr[] = {{1,2}, {2,3}, {3,4}};
    cout<<arr[1].second;


    


    return 0;
}
