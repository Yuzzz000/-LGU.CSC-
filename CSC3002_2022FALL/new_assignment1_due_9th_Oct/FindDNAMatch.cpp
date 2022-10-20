/* Q2: 
 * File: FindDNAMatch.cpp
 * ----------------------
 * This file solves the DNA matching exercise from the text.
 */
// header file for OJ system
// #include <iostream>
// #include <string>

// using namespace std;

#include <algorithm>
#include <iostream>
#include <string>
#include "csc300222fall/assignment1/FindDNAMatch.h" //for OJ
using namespace std;


/*
 * Function: findDNAMatch
 * Usage: int pos = findDNAMatch(s1, s2);
 *        int pos = findDNAMatch(s1, s2, start);
 * ---------------------------------------------
 * Returns the first index position at which strand s1 would bind to
 * the strand s2, or -1 if no such position exists.  If the start
 * parameter is supplied, the search begins at that index position.
 */

int findDNAMatch(string s1, string s2, int start) {
   // TODO
   int index = s2.find(s1, start);
   if(index > s2.length()){
      index = -1;
   }
   return index;
}

/*
 * Function: matchingStrand
 * Usage: string match = matchingStrand(strand);
 * ---------------------------------------------
 * Returns a string in which each base has been replaced by its
 * counterpart base (C <-> G and A <-> T).  Any other characters
 * are replaced by an X.
 */

string matchingStrand(string strand) {
   // TODO
   string str = strand;
   replace(str.begin(),str.end(),'A','t');
   replace(str.begin(),str.end(),'T','A');
   replace(str.begin(),str.end(),'t','T');
   replace(str.begin(),str.end(),'G','c');
   replace(str.begin(),str.end(),'C','G');
   replace(str.begin(),str.end(),'c','C');
   for(int i=0; i < strand.length(); i++){
      if(str[i] != 'A' && str[i] != 'T' && str[i] != 'G' && str[i] != 'C'){
         str.replace(i,1,"X");
      }
   }
   return str;
}

/*
 * Function: findAllMatches
 * Usage: findAllMatches(s1, s2);
 * ------------------------------
 * Finds all positions at which s1 can bind to s2.
 */

void findAllMatches(string s1, string s2) {
   // TODO
   string oriS1 = s1;
   s1 = matchingStrand(s1);
   int begin = 0;
   int p;
   string op = "no";
   while(begin <= s2.length()){
      p = findDNAMatch(s1, s2, begin);
      if(p == -1){
         break;
      }
      begin = p + 1;
      op = oriS1 + " matches " + s2 + " at position " + to_string(p);
      cout << op << endl; 
   }
   if(op == "no"){
      op =  oriS1 + " has no matches in " + s2;
      cout << op << endl;
   }
}

// DO NOT modify the main() function
/*
 * sample output:
 * input:  TTGCC TAACGGTACGTC
 * output: TTGCC matches TAACGGTACGTC at position 1
*/
int main(int argc, char* argv[]) {
    string s1, s2;
    cin >> s1 >> s2; 
    findAllMatches(s1, s2);
    return 0;
}
