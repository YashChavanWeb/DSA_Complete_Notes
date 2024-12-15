#include <bits/stdc++.h>
using namespace std;


int main()
{
   // Vectors - 
    vector<int> v;   // creates an empty container
    v.push_back(1);  // pushes value in the container
    v.emplace_back(2);  // dynamically increases and adds 2 at the end - faster than push back

    vector<pair<int, int>> v1;
    v1.push_back({1,2}); // you have to put curly braces
    v1.emplace_back(1,2);  // assumes it as a pair and takes input

    vector<int> vec(5);  // container with size 5 is created - even after this we can increase its size
    vector<int> vec(5,100);  // container containing 5 instances of 100 is created

    vector<int> v2(vec);   // v2 will be a copy of vec - another container
    cout<<v2[2]; // accessing 2nd index element - similar like array

    vector<int>::iterator name = v.begin();   // this points to memory location of first element
    cout<<*(name);
    name++;
    cout<<*(name);

    vector<int>:: iterator ex = v.end();  // this points to location after last element, after ex-- points to last element
    cout<<v.back();  // last element


    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout<<*(it)<<" ";
    }

    for(auto it = v.begin(); it!= v.end(); it++){   // auto -> data type is assigned automatically
        cout<<*(it)<<" ";
    }

    for(auto it:v){    // value of v is assigned to it -> so no * is needed
        cout<<(it)<<" ";
    }

    v.erase(v.begin());
    v.erase(v.begin(), v.begin()+4);   // [start, end)   -> end is not included

    v.insert(v.begin() + 1, 100);  // position, element
    v.insert(v.begin() + 1, 2, (100,200));  // position, no.of elements, elements

    vector<int> copy = {1,2,3,4};
    v.insert(v.begin(), copy.begin(), copy.end());

    cout<<v.size();   // gives size of vector
    v.pop_back();   // pops back the last element of vector
    v.swap(copy);    // swaps the two vectors
    v.clear();   // clears the vector
    cout<<v.empty();   // checks if the vector is empty


    return 0;
}
