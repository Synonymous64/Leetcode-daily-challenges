#include<bits/stdc++.h>
using namespace std;
// class MyCalendar {
// private:
//     map<int,int> mp;
// public:
//     bool book(int start, int end) {
//         mp[start]++;
//         mp[end]--;
//         int sum = 0;
//         for(auto it = mp.begin(); it != mp.end(); ++it){
//             sum += it->second;
//             if(sum > 1){
//                 mp[start]--;
//                 mp[end]++;
//                 return false;
//             }
//         }
//         return true;
//     }
// };
//* Other Approache ~ 
class MyCalendar {
private:
    vector<pair<int,int>> p;
public:
    bool book(int start, int end) {
        for(auto it : p){
            if(it.first < end && it.second > start) return false;
        }
        p.push_back({start, end});
        return true;
    }
};
int main(){
    // [[], [10, 20], [15, 25], [20, 30]]
    MyCalendar c;
    c.book(10, 20);
    c.book(15, 25);
    cout<<std::boolalpha<<c.book(20, 30)<<endl;
    return 0;
}