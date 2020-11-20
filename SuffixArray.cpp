#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "SuffixArray.h"
using namespace std;


/**
 * Implement suffix_array() correctly
 */
vector<unsigned int> suffix_array(const string & s) {
        
    //create a paired vector of string and int
    vector<pair<string, unsigned int>> paired;

    //push the suffices and assign number in order
    for(unsigned int i = 0; i < s.length(); i++){
        paired.push_back(make_pair(s.substr (i, s.length()-i), i));
    }
    
    //sort the vector. sort() function sorts the vector by the first value of the pair unless otherwise stated
    sort(paired.begin(), paired.end());

    //create vector iterator
    vector<pair<string, unsigned int>>::iterator itr;
    //create another vector with int only this time
    vector<unsigned int> result;

    //iterate through the paired vector and push the sorted int values into the new vector.
    for(itr = paired.begin(); itr != paired.end(); itr++){
        result.push_back(itr->second);
    }

    //return the resulting vector
    return result;
}

