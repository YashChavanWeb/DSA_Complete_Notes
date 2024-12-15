#include<bits/stdc++.h>
using namespace std;

int main(){
    
    queue<int> q;  // FIFO
    q.push(1);
    q.emplace(2);   // add at the back
    
    q.back() += 5;  // 2 + 5 so back element becomes 7
    cout<< q.back();
    cout<<q.front();

    q.pop();

    // size, swap, empty functions same as stack

    // Complexity same as stack - O(1)
    return 0;
}