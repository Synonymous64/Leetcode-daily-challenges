#include<bits/stdc++.h>
using namespace std;
class MyHashSet {
private:
    int arr[1000001];
public:
    MyHashSet() {
        memset(arr, -1, sizeof(arr));
    }

    void add(int key) {
        arr[key] = 1;
    }

    void remove(int key) {
        arr[key] = -1;
    }

    bool contains(int key) {
        return arr[key] == 1;
    }
};

int main(){
    MyHashSet *s = new MyHashSet();
    s->add(1);
    s->add(2);
    cout<<std::boolalpha<<s->contains(1)<<endl;
    cout<<std::boolalpha<<s->contains(3)<<endl;
    s->add(2);
    cout<<std::boolalpha<<s->contains(2)<<endl;
    s->remove(2);
    cout<<std::boolalpha<<s->contains(2)<<endl;
    return 0;
}