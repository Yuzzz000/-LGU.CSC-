/* assignment1 Q1:
 * File: combinatorics.cpp
 * -----------------------
 * This file implements the combinatorics.h interface.
 */

/*
 * header file for OJ system
 */
// #include <iostream>
// #include <iomanip>
// using namespace std;


/*
 * header file for local test
 */
#include <iostream>
#include "csc300222fall/assignment1/Combinatorics.h" // For OJ
using namespace std;


/* Function prototypes */

int fact(int n);

/*
 * Implementation notes: permutations
 * ----------------------------------
 * This function takes advantage of the property that n! divided by (n - k)!
 * is simply the first k terms in the product
 *
 *     n * (n - 1) * (n - 2) * . . .
 */

int permutations(int n, int k) {
   // TODO
   int p = 1;
   for(int i = n - k + 1; i <= n; i = i + 1)
   {
      p = p * i;
   }
   return p;
}

/*
 * Implementation notes: combinations
 * ----------------------------------
 * This function returns the permutations value divided by k!, which
 * is computed by the function fact.
 */

int combinations(int n, int k) {
   // TODO
   int c;
   c = permutations(n, k) / fact(k);
   return c;
}

/*
 * Function: fact(n)
 * Usage: int result = fact(n);
 * ----------------------------
 * Returns the factorial of n, which is the product of all the
 * integers between 1 and n, inclusive.
 */

int fact(int n) {
   // TODO
   int f = 1;
   for(int i=1; i <= n; i = i + 1)
   {
      f = f * i;
   }
   return f;
}



// DO NOT modify the main() function!
// for the samplt output:
/*
  input:  3 2
  output: 3
 */
 
int main(int argc, char* argv[]) {
  int n,k;
  cin>>n>>k;
  cout <<permutations(n, k) << ' ';
  cout <<combinations(n, k);
  cout << endl;
  return 0;
}
