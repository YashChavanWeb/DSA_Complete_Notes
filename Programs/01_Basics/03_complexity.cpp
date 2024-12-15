/* ------------------------- Time Complexity ------------------------- */

// What is Time Complexity ?

// Time taken is not equal to time complexity -> windows and mac laptop (system dependent)
// The rate at which the time taken increases w.r.t. the input size
// the theta angle is called the rate of increase

/* ------------------------- Notation for Time Complexity ------------------------- */

// Big Oh Notation -> O()

// Example - for loop

// for(i=1; i<=5; i++){
//     cout<< "Yash";
// }

// Its time complexity will be O(15)  -> (check + print + update) x 5
// Its time complexity will be O(N x 3)  -> (check + print + update) x N

// Rules
// - complexity calculated always for worst case scenario
// - avoid constants
// - avoid lower values of degrees
// - Cases - best , average , worst case

// O (N + 2) = O (N)  - avoid constants

// Some Other Notations
// Big Oh -> Upper Bound Complexity - worse case
// Omega Notation -> lower Bound Complexity - best case
// Theta Notation -> average case

/* ------------------------- Examples ------------------------- */

// Q.1]
// for(goes till n){
//     for(goes till n)
// }
// Time Complexity : O(N^2)

// Q.2]
// for(goes till n){
//     for(goes till i)
// }
// Sol : (1+2+3....N)
// Time Complexity : O(Nx(N+1)/2)  = O(N^2/2 + N/2) = O(N^2/2)  = O(N^2)

/* ------------------------- Space Complexity ------------------------- */

// What is space complexity ?

// It is Auxiliary space (space that you take to solve the problem) + input space (space that you take to store the input)
// Big Oh Notation -> O() here as well

// Eg: int a, b;  int c = a+b;
// a and b is the input space and c is the auxiliary space

// Note : In order to reduce time and space complexity, never do anything to the input - data should not be touched
// Eg: a and b are input then their sum is b = b  + a;

/* ------------------------- Competitive Programming ------------------------- */

// The server takes 1 second to process 10^8 data -> 1s = 10^8
// so for 2 seconds it will be -> 2s = 2x 10^8
