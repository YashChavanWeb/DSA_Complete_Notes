#include<bits/stdc++.h>
using namespace std;

int main(){
    
    stack<int> st;   // LIFO
    st.push(3);   // pushes from the top
    st.pop();   // delete the top element

    st.emplace(3);   // adds at the bottom
    cout<< st.top(); // show the top element
    cout<< st.size();
    cout<< st.empty();

    // we cannot access elements with index
    // cout<<st[3];   // this is invalid

    stack<int> st1, st2;
    swap(st1, st2);

    // Complexity is O(1) -> everything happens in constant time

    return 0;
}