#include<bits/stdc++.h>
using namespace std;
class LRUCache {
private:
    int capacity;
    queue<int> history;
    unordered_map<int,int> counter;
    unordered_map<int,int> dict;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(dict.count(key)){
            history.push(key);
            counter[key]++;
            return dict[key];
        }
        return -1;
    }

    void removeHistory(){
        while(!history.empty()){
            int curr = history.front();
            history.pop();
            counter[curr]--;
            if(counter[curr] == 0){
                dict.erase(curr);
                break;
            }
        }
        return;
    }
    void put(int key, int value) {
        history.push(key);
        counter[key]++;
        dict[key] = value;
        if(dict.size() > this->capacity) removeHistory();
        return;
    }
};

int main(){
    LRUCache *l = new LRUCache(2);
    l->put(1,1);
    l->put(2,2);
    cout<<l->get(1)<<endl;
    return 0;
}