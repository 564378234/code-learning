#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tcount(128, 0);
        int fast = 0, slow = 0, nums = 0, min = INT_MAX, start;
        string res = "";
        if(s.size() < t.size())return res;
        for(char x : t){
            tcount[x]++;
            nums++;
        }
        int curnum = nums;
        while(fast < s.size()){
            if(tcount[s[fast]] > 0)curnum--;//直到找到了全部字符curnum才为0
            tcount[s[fast]]--;
            fast++;
            while(curnum == 0){
                if(fast - slow < min){//寻找最小范围
                    min = fast - slow;
                    start = slow;
                }
                tcount[s[slow]]++;
                if(tcount[s[slow]] > 0)curnum++;//先tcount[s[slow]]++;，所以肯定是大于0时t中的字符不全了
                slow++;
            }
        }
        if(min != INT_MAX)res = s.substr(start, min);//substr是截取字符串
        return res;
    }
};