#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(int row = 0; row < matrix.size(); ++row){
            for(int col = 0; col < matrix[0].size(); ++col){
                pq.push(matrix[row][col]);
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};
int main(){
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 8;
    Solution s;
    cout<<s.kthSmallest(matrix, k)<<endl;
    return 0;
}