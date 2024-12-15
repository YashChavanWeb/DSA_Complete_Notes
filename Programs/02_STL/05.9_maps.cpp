#include<bits/stdc++.h>
using namespace std;
int main() {
    
    // It has a key and a value - keys are unique but the values can be same

    map<int, int> mp1;
    map<int , pair<int, int>> mp2;   // key is integer and the value is a pair
    map<pair<int, int>, int> mp3;   // key is a pair and the value is integer

    mp1[1] = 2;  // this means, on key 1 store 2
    mp1.insert({2,4});  // key , value  

    // Note : map stores unique keys in sorted order - alphabetical order

    mp3[{2,3}] = 23;
    mp3.insert({{2,3},3});   // this will override the prior key value

    // iterating through a map
    for(auto it: mp1) {
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<mp1[2];  // gives the value at key 2
    // Note: if element is not present then it returns null / 0

    auto it = mp1.find(1);  // this gives the address to the iterator where the key lies
    cout<<(it)->second;

    auto it = mp1.lower_bound(2);
    auto it = mp1.upper_bound(3);

    // erase, size, swap and empty functions are same as above




    // ---------------- Multi Map ---------------------
    
    // Everything same just you can save duplicate keys also
    // only map[key] cannot be used here



    // ---------------- Unordered Map ---------------------

    // Everything same just the map will not be stored in sorted order


    // Note: Difference - map time complexity - log(n) and unordered map complexity - O(1)
    



    return 0;
}