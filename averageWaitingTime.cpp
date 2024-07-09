class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int size = customers.size();
        double totalTime = 0;
        int endTime = 0;

        for(auto& customer : customers){
            auto [arrivalTime,prepTime] = tie(customer[0], customer[1]);
            if(arrivalTime > endTime) endTime = arrivalTime;
            endTime += prepTime;
            totalTime += endTime - arrivalTime;
        }

        return (totalTime / size);
    }
};