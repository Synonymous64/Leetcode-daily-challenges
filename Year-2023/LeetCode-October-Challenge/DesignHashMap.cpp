#include<bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    vector<list<pair<int,int>>> mp;
    int size = 10;
public:
    MyHashMap() {
        mp.resize(size);
    }

    int hash(int key){
        return key % size;
    }

    void put(int key, int value) {
        int i = hash(key);
        for(auto it = mp[i].begin(); it != mp[i].end(); ++it){
            if(it->first == key){
                it->second = value;
                return;
            }
        }
        mp[i].push_back({key, value});
    }

    int get(int key) {
        int i = hash(key);
        for(auto it = mp[i].begin(); it != mp[i].end(); ++it){
            if(it->first == key){
                return it->second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int i = hash(key);
        for(auto it = mp[i].begin(); it != mp[i].end(); ++it){
            if(it->first == key){
                mp[i].erase(it);
                return;
            }
        }
    }
};

int main(){
    MyHashMap *x = new MyHashMap();
    x->put(1, 1);
    x->put(2, 2);
    cout<<x->get(1)<<endl;
    cout<<x->get(3)<<endl;
    x->put(2, 1);
    cout<<x->get(2)<<endl;
    cout<<x->get(2)<<endl;
    x->remove(2);
    return 0;
}
