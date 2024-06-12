class Solution {
private:
    bool dfs(int course,vector<int>& order,vector<vector<int>>& adj, vector<int>& visited,vector<int>& recursionStack){
       if(visited[course]) return false; // cycle not present
       if(recursionStack[course]) return true; // cycle present;

       recursionStack[course] = 1;

       for(const int& courses : adj[course]){
          if(dfs(courses,order,adj,visited,recursionStack)) return true;
       }

       order.push_back(course);// reverse later
       //order.insert(order.begin(),course); direct put in order 
       visited[course] = 1;
       recursionStack[course] = 0;

       return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto& course : prerequisites){
            adj[course[1]].push_back(course[0]);
        }

        vector<int> recursionStack(numCourses,0);
        vector<int> visited(numCourses,0);
        vector<int> order;

        for(int i = 0;i<numCourses ;i++){
            if(!visited[i]){
                if(dfs(i,order,adj,visited,recursionStack))
                return {};
            }
        }
        reverse(order.begin(),order.end());// no need if direct insert
        return order;
    }
};