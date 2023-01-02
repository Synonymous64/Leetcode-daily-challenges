#include<bits/stdc++.h>
using namespace std;
class MyCalendarThree {
private:
    int maxCount = 0;
    map<int,int> mp;
public:
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int count = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            count += it->second;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
int main(){
    MyCalendarThree m;
    cout<<m.book(10, 20)<<endl;
    cout<<m.book(50, 60)<<endl;
    cout<<m.book(10, 40)<<endl;
    cout<<m.book(5, 15)<<endl;
    cout<<m.book(5, 10)<<endl;
    cout<<m.book(25, 55)<<endl;
    return 0;
}