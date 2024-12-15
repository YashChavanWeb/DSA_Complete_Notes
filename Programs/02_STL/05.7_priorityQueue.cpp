#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // Maximum Heap
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    // not a linear data structure -> internally a tree is maintained
    // elements are pushed according to the order automatically

    cout<<pq.top();   // prints 10 -> largest element / string
    pq.pop();  

    // size, swap, empty functions same as others


    // Minimum Heap - priority queue that stores the minimum element at the top
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);


    // Time Complexity
    // push -> log(n)
    // pop -> log(n)
    // top -> O(1)

    return 0;
}