#include <istream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        bool ishappy(int n){
            int sum = n;
            unordered_set<int> set = {n};
            while(set.find(sum) == set.end()){//while(set.find(sum) != set.end())是如果在集合set中找到sum就进入循环
                //每次先填入sum再把sum归零，然后求和
                set.insert(sum);
                sum = 0;
                while(n > 0){
                    sum = sum + (n % 10) * (n % 10);
                    n = n / 10;
                }
                if(sum == 1){
                    return true;
                }
                n = sum;
            }
            return false;
        }
};