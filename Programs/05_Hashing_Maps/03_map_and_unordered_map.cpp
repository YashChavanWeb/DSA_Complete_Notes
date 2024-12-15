// ### Hash Maps
// map<key, value> - here key means the number and value means the frequency of the number
// it basically stores the array in the form of a hash map
// map stores all the values in the sorted order

// pre computation can also be done while taking the input

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // pre correction
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] += 1;
    }

    // iterating in the map
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int number;
        cin >> number;

        cout << mpp[number] << endl;
    }
    /*


    */
    // ### Use of hashmap in string
    // we can simply do map<char, int> mpp
    // and to add the frequencies -> mpp[arr[i]] = value
    // but here the hash[] will not take only int, it can take any, and so its stores like : map<a,2> - frequency of a is 2
    // so we have to declare map<char, int> and then store in the same way
    // so in the pre computation stage we will do mpp[s[i]]

    // ### Time complexity of map
    // in storing and fetching both combined the map takes - log(n) time where n is the the no. of elements in the map
    // in all cases - best, worst and average same complexity -> O(log(n))
    /*



    */
    // ### Unordered maps
    //  here there is no order for storing the elements in the map

    // This is useful because:
    // storing and fetching in unordered map takes best and average time of -> O(1) -> constant time
    // but worst case time complexity is -> O(n) -> linear time (n is the no. of elements in the map)

    // so we should always consider unordered map
    // as it will give max of n^2 overall complexity -> loop till n{map till n{}} -> n*n -> n^2
    // and if we use ordered map then it will give max of nlogn overall complexity

    // Note: the worst case happens only due to internal collisions
    /*




    */
    // ### Hashing methods
    // 1. Division Method
    /*
        - so here basically we trim the number by doing % 10
        -  if the array is of larger size then we can use division -> eg: max size 10 (0 to 9)
        - and if we get 139 in the array - then 139%10 - 9 and store 1 in the 9th index in array

        - so now what if we have the same modulo after divison - in that we will use chaining
        - it can be maintained using a linked list
        - Eg: 8 -> 28 -> 38 -> 48 , so on the same index we have 3 elements chained
        - if we get the same element again then we will change it after its first occurrence
        - so it will now become 28 -> 28 -> 38 -> 48
        - and if it is asked that how many times does 28 occur then as they are chained in sorted order so we can do a binary search and find the occurrence in minimal time
    */
    // 2. Folding Method
    // 3. Mid Square Method
    /*





    */

    // ### Collisions
    // eg: if in the array all the elements end with 8 then all will chain at the same index of the hash
    // and due to this it will be time taking to find the values
    // so this is called as collision

    // Note:
    // in a map a key can be any data type: int, char, pair of any, etc
    // in unordered map - we have to have individual datatypes - we cannot have pair, vector, etc
    /*



    */
    // Find the highest / lowest frequency element
    int n = 6;
    int new_arr[n] = {1, 2, 1, 2, 3, 1};
    unordered_map<int, int> mppa;

    for (int i = 0; i < n; i++)
        mppa[new_arr[i]]++;

    int maxFreq = 0, minFreq = n; // here I took all 0 so that was my mistake
    int maxEle = 0, minEle = 0;
    // Traverse through map to find the elements.
    for (auto it : mppa)
    {
        int count = it.second;
        int element = it.first;

        if (count > maxFreq)
        {
            maxEle = element;
            maxFreq = count;
        }
        if (count < minFreq)
        {
            minEle = element;
            minFreq = count;
        }
    }

    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";

    int q2 = 2;
    while (q2--)
    {
        int number;
        cin >> number;
        cout << "The frequency of " << number << " is " << mppa[number] << endl;
    }

    return 0;
}