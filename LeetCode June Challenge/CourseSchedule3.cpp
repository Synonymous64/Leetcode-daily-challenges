#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto &a, auto &b){return a[1] < b[1];});
        priority_queue<int> maxheap;
        int time = 0;
        for(auto course : courses){
            if(time + course[0] <= course[1]){
                time += course[0];
                maxheap.push(course[0]);
            }
            else if(maxheap.size() && maxheap.top() > course[0]){
                time += course[0] - maxheap.top();
                maxheap.pop();
                maxheap.push(course[0]);
            }
        }
        return maxheap.size();        
    }
};
int main(){
    vector<vector<int>> courses = {{100,200},{200,1300},{1000,1250},{2000,3200}};
    Solution s;
    cout<<s.scheduleCourse(courses)<<endl;
    return 0;
}