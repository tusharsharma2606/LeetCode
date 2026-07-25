class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkInMap;
    unordered_map<string,pair<int, int>> travelData;

public:
    UndergroundSystem() {     
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t){
        auto checkInInfo = checkInMap[id];

        string startStation = checkInInfo.first;
        int startTime = checkInInfo.second;

        string route = startStation + "->" + stationName;

        travelData[route].first += (t - startTime);
        travelData[route].second ++;

        checkInMap.erase(id);
    }

    double getAverageTime(string startStation, string endStation){
        string route = startStation + "->" + endStation;
        auto data = travelData[route];
        return (double)data.first / data.second;
    }  
};

