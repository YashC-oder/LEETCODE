// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
//         unordered_map<int,bool> visited;
//         stack<int> st;

//         st.push(0);

//         while(!st.empty()){
//             int curr = st.top();

//             if(!visited[curr]) visited[curr] = true;
            
//             st.pop();

//             for(const int& i : rooms[curr]) 
//             if(!visited[i]) st.push(i);
//         }

//         int numOfRooms = rooms.size();

//         for(int i = 0 ; i < numOfRooms ; i++){
//             if(!visited[i]) return false;
//         }

//         return true;
//     }
// };


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited = vector<bool>(rooms.size(), false);
        queue<int> roomKeys;
        visited[0] = true;

        for(int room: rooms[0]){
            roomKeys.push(room);
        }

        while(!roomKeys.empty()){
            int key = roomKeys.front();
            roomKeys.pop();

            if(visited[key]) continue;
            
            visited[key] = true;
            for(int room: rooms[key]){
                roomKeys.push(room);
            }
        }

        for(bool visit: visited){
            if(!visit) return false;
        }


        return true;
        
    }
};