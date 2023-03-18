#include<bits/stdc++.h>
using namespace std;
class BrowserHistory {
private:
    int curr = -1;
    vector<string> history;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr++;
    }

    void visit(string url) {
        history.erase(history.begin() + curr + 1, history.end());
        history.push_back(url);
        curr++;
    }

    string back(int steps) {
        curr = max(0, steps - curr);
        return history[curr];
    }

    string forward(int steps) {
        curr = min((int)history.size() - 1, steps + curr);
        return history[curr];
    }
};

