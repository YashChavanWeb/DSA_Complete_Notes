#include<bits/stdc++.h>
using namespace std;

int main(){

    // sets -> stores everything in the sorted order & stores only unique elements
    
    set<int> s;
    s.insert(1);
    s.emplace(2);
    s.insert(2);   // this line will have no effect as 2 is already present

    // stores all the elements in the sorted order - tree is maintained

    // It also has same functions like others  
    // begin(), end(), rbegin(), rend(), size(), empty() and swap() 

    auto it = s.find(3);   // if the iterator is not present in the set then it points after the last element
    s.erase(2);
    // another method to erase an element
    auto it = s.find(1);
    s.erase(it);

    int count = s.count(1);

    auto it1 = s.find(1);
    auto it2 = s.find(2);
    s.erase(it1, it2);  // erase data from 2 to 4 values  
    // but here we cannot pass numbers, we need to pass iterators 

    // DSGT Logic
    auto it = s.lower_bound(2);
    auto it = s.upper_bound(2);

    // time complexity - log(n) 




    // -------------- Multi Set ------------------  
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);   // it stores all the occurances of 1

    ms.erase(1); // all occurances of 1 are deleted

    // To erase only a single 1
    ms.erase(ms.find(1));   // as find points to an iterator
    
    // rest all functions same as set



    // -------------- Unordered Set ------------------ 
    unordered_set<int> us;
    // all things same just it is not sorted
    // lower and upper bound functions dont work, rest all the functions work
    // time complexity is O(1)  - for worst case O(N)


    

    
    return 0;
}