#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> map;
        int groupnums = 0;
        int n = strs.size();
        for(int i = 0; i < n; i++){
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            if(map.find(cur) != map.end()){
                result[map[cur]].push_back(strs[i]);
            }else{
                result.push_back(vector<string>{});
                map[cur] = groupnums;
                result[groupnums].push_back(strs[i]);
                groupnums += 1;
            }
        }
        return result;
    }
};

// 打印二维字符串向量的辅助函数
void printGroups(const vector<vector<string>>& groups) {
    for (const auto& group : groups) {
        cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << "\"" << group[i] << "\"";
            if (i != group.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution solution;
    
    // 测试用例 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << "Test Case 1:" << endl;
    vector<vector<string>> result1 = solution.groupAnagrams(strs1);
    printGroups(result1);
    cout << endl;

    // 测试用例 2
    vector<string> strs2 = {""};
    cout << "Test Case 2:" << endl;
    vector<vector<string>> result2 = solution.groupAnagrams(strs2);
    printGroups(result2);
    cout << endl;

    // 测试用例 3
    vector<string> strs3 = {"a"};
    cout << "Test Case 3:" << endl;
    vector<vector<string>> result3 = solution.groupAnagrams(strs3);
    printGroups(result3);
    cout << endl;

    return 0;
}