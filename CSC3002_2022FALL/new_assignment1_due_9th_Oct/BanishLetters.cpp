/*
 * File: BanishLetters.cpp
 * -----------------------
 * This program removes all instances of a set of letters from
 * an input file.
 */

#include <iostream>
#include "csc300222fall/assignment1/lib.h" //for local version
using namespace std;

int banishLetters() {
   // TODO
   string str;
   getline(cin, str);
   char c;
   char d;
   char w;
   int flag = 1;
   while(cin.get(w)){
   for(int i=0; i<str.length();i++){
       c = str[i];
       if(c >= 'A' && c <= 'Z'){
              d = c + 32;
       }
       else{
              d = c - 32;
       }
       if(w == c || w == d){
              flag = 1;
              continue;
       }}
       if(flag == 0){
              cout << w;
       }
       flag = 0;
       }
   return 0;
}


/* DO NOT modify this main() part */
/*
 sample output:
 input: S
        this is a testing 1
        this is a testing 2
 output:
        thi i a teting 1
        thi i a teting 2
*/
int main(int argc, char* argv[]) {
    banishLetters();
    return 0;
}
