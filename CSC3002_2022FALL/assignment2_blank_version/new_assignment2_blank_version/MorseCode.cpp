/* Q3
 * File: MorseCode.cpp
 * -------------------
 * This program translates to and from Morse Code using maps to
 * assist in the translation.
 */

#include <iostream>
#include <string>
#include <map>
#include "csc300222fall/assignment2/lib.h" 
#include "csc300222fall/assignment2/morsecode.h" 
using namespace std;


/*
 * TODO function
 * Function: translateLettersToMorse
 * Usage: string morse = translateLettersToMorse(line);
 * ----------------------------------------------------
 * Translates a string of letters into Morse Code characters separated
 * by spaces.  Characters that don't appear in the table are simply ignored.
 */

string translateLettersToMorse(string line) {
   // TODO
   
   int size = line.size();
   string re = "";
   string str;
   string l;
   for(int i = 0; i < size; i++){
      l = line[i];
      if (line[i] >= 'A' && line[i] <= 'Z'){
         str = LETTERS_TO_MORSE.at(l);
         re = re + str + " ";
      }
   }
   return re;
}

/*
 * TODO function
 * Function: translateMorseToLetters
 * Usage: string letters = translateLettersToMorse(line);
 * ------------------------------------------------------
 * Translates a string in Morse Code into English letters.
 * Because word breaks are not represented in Morse code, the
 * letters in the output will be run together.  The characters
 * of the Morse Code input must be separated by a single space.
 * Any other character in the input is simply ignored.  If there
 * is no English equivalent for the Morse Code character, this
 * function indicates that fact by inserting a question mark (?).
 *
 * Implementation note: To eliminate the special case of the last
 * character in the line, this function begins by adding a space
 * to the end of the input string.
 */

string translateMorseToLetters(string line) {
   // TODO
   string line1 = "";
   for (int i = 0; i < line.size(); i++){
      if (line[i] == '.' || line[i] == '-' || line[i] == ' '){
         line1 = line1 + line[i];
      }
   }

   int size = line1.size();
   string re = "";
   string str;
   string temp = "";
   string l;
   for(int i = 0; i < size; i++){
      if (line1[i] == ' '){
         l = temp;
         temp = "";
         str = MORSE_TO_LETTERS.find(l)->second;
         re = re + str;
      }
      else{
         temp = temp + line[i];
      }
   }
   l = temp;
   str = MORSE_TO_LETTERS.find(l)->second;
   re = re + str;
   return re;

}

/*
 * Function: createMorseCodeMap
 * Usage: map<string> map = createMorseCodeMap();
 * ----------------------------------------------
 * Returns a map in which each uppercase letter is mapped into its
 * Morse code equivalent.
 */

map<string,string> createMorseCodeMap() {
   map<string,string> map;
   map["A"] = ".-";
   map["B"] = "-...";
   map["C"] = "-.-.";
   map["D"] = "-..";
   map["E"] = ".";
   map["F"] = "..-.";
   map["G"] = "--.";
   map["H"] = "....";
   map["I"] = "..";
   map["J"] = ".---";
   map["K"] = "-.-";
   map["L"] = ".-..";
   map["M"] = "--";
   map["N"] = "-.";
   map["O"] = "---";
   map["P"] = ".--.";
   map["Q"] = "--.-";
   map["R"] = ".-.";
   map["S"] = "...";
   map["T"] = "-";
   map["U"] = "..-";
   map["V"] = "...-";
   map["W"] = ".--";
   map["X"] = "-..-";
   map["Y"] = "-.--";
   map["Z"] = "--..";
   return map;
}

/*
 * TODO function
 * Function: invertMap
 * Usage: map<string> inverse = invertMap(map);
 * --------------------------------------------
 * Creates an inverted copy of the specified map in which the values
 * in the original become the keys of the new map and refer back to
 * their associated keys.  Thus, if "abc" is bound to "xyz" in the
 * original map, the inverted map will bind "xyz" to "abc".  If two
 * keys in the original map have the same value, this function will
 * signal an error condition.
 */

map<string,string> invertMap(const map<string,string> & m) {
   // TODO
   map<string, string> n;
   string value, key;
   for (auto it=m.begin(); it!=m.end(); ++it){
      value = it ->first;
      key = it ->second;
      n.insert(map<string,string>::value_type(key,value));
}
   n.insert(map<string,string>::value_type("?","?"));
   return n;
}

int main() {
    /* A sample translator:
     *                     > SOS
     *                     ... --- ...
     *                     > ... --- ...
     *                     SOS
     */
    string line;

    while (getline(cin, line) && line.length() > 0) {
       line = toUpperCase(line);
       if (line[0] == '.' || line[0] == '-') {
           cout << translateMorseToLetters(line) << endl;
       } else {
           cout << translateLettersToMorse(line) << endl;
       }
    }

    return 0;
   
}

