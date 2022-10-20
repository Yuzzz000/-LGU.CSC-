/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */
// header file for local test
#include <iostream>
#include <iomanip>
#include "csc300222fall/assignment1/RemoveComments.h" //for OJ
using namespace std;

#pragma GCC diagnostic ignored "-Wcomment"
/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */

void removeComments(istream & is, ostream & os) {
   //TODO
   char c;
   int slash = 0;
   int xing = 0;
   int type1 = 0;
   int type2 = 0;
   while (is.get(c))
   {
    if(type1 == 1){
        if(c == '\n' ){
            type1 = 0;
            os.put('\n');
        }
        continue;
    }
    if(type2 == 1){
        if(xing == 0){
            if(c == '*'){
                xing = 1;
            }
            continue;
        }
        if(xing == 1){
            if(c == '/'){
                type2 = 0;
                xing = 0;
            }
            xing = 0;
            continue;
        }
    }

    if(type1 == 0 && type2 == 0){
    if(slash == 0){
        if( c == '/'){
            slash = 1;
        }
        else{
            os.put(c);
        }
        continue;
        }
    if(slash == 1){
        if(c == '/'){
            type1 = 1;
        }
        if( c == '*'){
            type2 = 1;}
        if(c != '/' && c != '*'){
            os.put('/');
            os.put(c);
        }
        slash = 0;
        continue;
        }
    
    } 
    }
   }


void TestRemoveComments(){
    removeComments(cin, cout);
}

// DO NOT modify the main() function
/*
 * sample output format:
 * input:  test file // this is a comment
           test file /* this is also a comment*/
/* output: test file
           test file
 */
int main(int argc, char* argv[]) {
    TestRemoveComments();
    return 0;
}
