#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> project(n);
        for(int i = 0; i < n; ++i)
            project[i] = {profits[i], capital[i]};
        sort(project.begin(), project.end(), [](auto &a, auto &b){ return a.second != b.second ? a.second < b.second: a.first < b.first;});

        int i = 0;
        priority_queue<int> pq;
        while(k--){
            while(i < n && w >= project[i].second){
                pq.push(project[i].first);
                i++;
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};
int main(){
    int k = 2, w = 0;
    vector<int> profits = {1,2,3}, capital = {0,1,1};
    Solution *s = new Solution();
    cout<<s->findMaximizedCapital(k, w, profits, capital)<<endl;
    return 0;
}