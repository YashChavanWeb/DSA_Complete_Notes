#include<bits/stdc++.h>
using namespace std;

int main() {

    int n = 5;
    int a[n] = {1,4,3,2,5};
    sort(a, a+n);

    // For vectors
    // sort(v.begin(), v.end()); 

    // sorting a particular portion
    sort(a+2, a+n);

    // sort in descending order
    sort(a, a+n, greater<int>());

    // Question
    // sort the given pair array according to increasing order of second element
    // and if second element is same then sort according to the first element

    pair<int , int> p[] = {{1,2}, {3,7}, {4,1}, {6,5}, {2,2}};
    sort(p, p+n, checker); // checker is a self written comparator - and it is a boolean function



    // Binary
    int num = 7;
    int count = __builtin_popcount(num);   // how many 1s  / set bits are there

    long long num1 = 123445677855421;   // if the number is long long
    int count = __builtin_popcount(num1);   

    
    // All possible permutations of a string
    string s = "12345";   

    // to get all the permutation, you should always start from a sorted string
    sort(s.begin(), s.end());

    do {
        cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end()));   // if no more permutations then it returns a false


    // Maximum element
    int max = *max_element(a, a+n);




    

    return 0;
}

bool checker(pair<int , int> p1, pair<int , int> p2) {
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;


    // if they are same
    if(p1.first > p2.first) return true;
    else return false;
    
}