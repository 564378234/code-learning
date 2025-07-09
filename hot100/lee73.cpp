#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)return;
        int n = matrix[0].size();
        bool Frow = false, Fcol = false;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0)Fcol = true;
        }
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0)Frow = true;
        }
        for(int i = 1; i < m; i++){//从第二行第二列开始搜索，标记到第一行第一列
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){//根据第一行第一列的信息置零第二行第二列往后的信息
            if(matrix[i][0] == 0){
                for(int j = 1; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++){//根据第一行第一列的信息置零第二行第二列往后的信息
            if(matrix[0][i] == 0){
                for(int j = 1; j < m; j++){
                    matrix[j][i] = 0;
                }
            }
        }
        if(Frow){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
        if(Fcol){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};