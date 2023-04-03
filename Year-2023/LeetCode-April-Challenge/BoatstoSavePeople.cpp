#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int low = 0, high = people.size() - 1;
        int boatCount = 0;
        while(low <= high){
            if(people[low] + people[high] <= limit) low++;
            high--;
            boatCount++;
        }
        return boatCount;
    }
};

int main(){
    vector<int> people = {1,2}; int limit = 3;
    Solution *s = new Solution();
    cout<<s->numRescueBoats(people, limit)<<endl;
    return 0;
}