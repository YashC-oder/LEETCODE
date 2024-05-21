// TIME LIMT EXCEEDED O(n^2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();

        for(int i = 0; i<size; i++){
            int tank = 0;
            bool flag = true;

            for(int j = i,count = 0; count<size ; j = (j+1)%size , count++){
                tank += gas[j];
                if(tank >= cost[j]){
                    tank -= cost[j];
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }

        return -1;
    }
};


/*-----------------------------------------------------------------------------------------------------*/
// O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        int current_gas = 0;
        int start_index = 0;

        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            current_gas += gas[i] - cost[i];

            if (current_gas < 0) {
                start_index = i + 1;
                current_gas = 0;
            }
        }

        if (total_gas < total_cost) {
            return -1;
        } else {
            return start_index;
        }
    }
};
