class Solution{
    private:
    
    bool dfs(int course,vector<vector<int>>& adj,vector<int>& visited,vector<int>& recursionStack){

        if(visited[course]) return false; // cycle not present;

        if(recursionStack[course]) return true; // cycle detected;
        
        recursionStack[course] = 1;

        for(int next : adj[course]){
            if(dfs(next , adj,visited,recursionStack)) return true;
        }

        visited[course] = 1;
        recursionStack[course] = 0; // remove from recursionStack to prepair it for another iteration

        return false;
    }

    public:

    bool canFinish(int numCourses,vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses,0);
        vector<int> recursionStack(numCourses,0);

        for(int i = 0; i<numCourses ; i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,recursionStack)) return false;
            }
        }

        return true;

    }
}