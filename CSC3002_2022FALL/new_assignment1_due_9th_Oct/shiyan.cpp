#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


int findDNAMatch(string s1, string s2, int start) {
   // TODO
   // s1 = matchingStrand(s1);
   int index = s2.find(s1, start);
   if(index > s2.length()){
      index = -1;
   }
   return index;
}

string matchingStrand(string strand) {
   // TODO
   string str = strand;
   string str1 = "X";
   replace(str.begin(),str.end(),'A','t');
   replace(str.begin(),str.end(),'T','A');
   replace(str.begin(),str.end(),'t','T');
   replace(str.begin(),str.end(),'G','c');
   replace(str.begin(),str.end(),'C','G');
   replace(str.begin(),str.end(),'c','C');
   return str;
}

int main(int argc, char* argv[]) {
    string s1, s2;
    cin >> s1 >> s2; 
    //findAllMatches(s1, s2);

   // cout << matchingStrand(s1);
    cout << findDNAMatch(s1, s2, 0);
    return 0;
}