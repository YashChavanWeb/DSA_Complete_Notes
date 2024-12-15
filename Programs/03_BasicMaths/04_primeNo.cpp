#include<bits/stdc++.h>
using namespace std;

int main() {

    // Prime Number - a number which has exactly two factors, 1 and itself

    // Met 1 : Brute force approach
    int n;
    cin>>n;

    int count = 0;
    for(int i=1; i<=n; i++) {
        if(n%i == 0) {
            count++;
        }
        else {
            continue;
        }
    }
    if(count==2) {
        cout<<"Prime";
    }
    else {
        cout<<"Not Prime";
    }
    cout<<endl;

    

    

    // Met 2 : Square root of n approach
    n;
    cin>>n;

    count = 0;
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i == 0) {
            count++;
            if(n/i != i) {
                count++;
            }
        }
        else {
            continue;
        }
    }
    if(count==2) {
        cout<<"Prime";
    }
    else {
        cout<<"Not Prime";
    }


    return 0;
}