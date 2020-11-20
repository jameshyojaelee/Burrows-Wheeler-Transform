#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "prim.h"
using namespace std;

/**
 * Implement bwt() correctly
 */
string bwt(const string & s) {
    
    vector<string> transform; //create a vector of string
    transform.push_back(s); //push the input string
    unsigned int len = s.length() - 1; 
    string start; //starting letter
    string word = s; //temporary string. assign it to s for now. 

    for(unsigned int i = 0; i < len; i++){
        start = word[len]; //starting character is the last character of the previous string
        word = start.append(word.substr(0, len)); //update "word" with a new string
        transform.push_back(word); //push the new string into the vector
    }

    vector<string>::iterator itr; //iterator for the vector
    string result; //resulting word

    //sort the vector in alphabetical order
    sort(transform.begin(), transform.end()); 

    //return the last char of each string in the vector.
    for(itr = transform.begin(); itr != transform.end(); itr++){
        string lastChar(1, (*itr)[len]); //create a temporary string of the last char in each word. 
        result.append(lastChar); //append it on the resulting string
    }

    for(int i =0; i < 40; i++){
        cout << 'C';
    }
    return result;
}
