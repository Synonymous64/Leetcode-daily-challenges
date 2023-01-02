#include<bits/stdc++.h>
using namespace std;
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        if(mp[key][0].first > timestamp) return "";
        int low = 0, high = mp[key].size() - 1;
        string res = "";
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mp[key][mid].first == timestamp) return mp[key][mid].second;
            else if(mp[key][mid].first < timestamp){
                res = mp[key][mid].second;
                low = mid + 1;
            } else high = mid - 1;
        }
        return res;
    }
};
int main(){
    TimeMap t;
    t.set("foo", "bar", 1);
    cout<<t.get("foo", 1)<<endl;
    cout<<t.get("foo", 3)<<endl;
    t.set("foo", "bar2", 4);
    cout<<t.get("foo", 4)<<endl;
    cout<<t.get("foo", 5)<<endl;
    return 0;
}