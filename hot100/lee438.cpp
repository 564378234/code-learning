#include <string>
#include <vector>
#include <algorithm>//有sort
using namespace std;

class Solution {//会超时，时间复杂度是NMlogM，m 是 p 的长度，n 是 s 的长度
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())return {};
        string strs, tmpstrs;
        int x = p.size(), n = s.size();
        vector<int> result;
        sort(p.begin(), p.end());
        for(int i = 0; i < x - 1; i++){
            strs.push_back(s[i]);//现在差一位
        }
        for(int i = 0; i <= n - x; i++){
            strs.push_back(s[i + x - 1]);//补全差的一位，与p相同了
            tmpstrs = strs;
            sort(tmpstrs.begin(), tmpstrs.end());
            if(tmpstrs == p)result.push_back(i);
            strs.erase(0, 1);//删除strs的第0位开始的1个字符，也就是开头的字符
        }
        return result;
    }
};

class Solution {//不会超时
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())return {};
        vector<int> count(26, 0);
        vector<int> pcount(26, 0);
        int x = p.size(), n = s.size();
        vector<int> result;
        for(char c : p)pcount[c - 'a']++;
        for(int i = 0; i < x - 1; i++){
            count[s[i] - 'a']++;//现在差一位
        }
        for(int i = 0; i <= n - x; i++){
            count[s[i + x - 1] - 'a']++;//补全差的一位，与p相同了
            if(count == pcount)result.push_back(i);//两个数组不能相互比较换成vector
            count[s[i] - 'a']--;//删除最先进入的字符
        }
        return result;
    }
};