#include<bits/stdc++.h>
using namespace std;
class UndergroundSystem {
public:
    UndergroundSystem() {

    }
    map<int,pair<string, int>>arrival; 
    map<string,pair<int,int>> routes;
    void checkIn(int id, string stationName, int t) {
        arrival[id] =  {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [stdn, start] = arrival[id];
        arrival.erase(id);
        string route = stdn + "," + stationName;
        routes[route].first++, routes[route].second += t - start;
    }

    double getAverageTime(string startStation, string endStation) {
        auto &[count, sum] = routes[startStation + "," + endStation];
        return (double) sum / count;
    }
};

