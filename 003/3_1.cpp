#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                count[s[i] - 'a']++;
            }
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] >= 'a' && t[i] <= 'z'){
                count[t[i] - 'a']--;
            }
        }
        // for(int i = 0; i < 26; i++){
        //     if(count[i] != 0){
        //         return false;
        //     }
        // }
        for(int x : count){
            if(x != 0){
                return false;
            }
        }
        return true;
    }
};