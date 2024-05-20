class Solution {
public:
    vector<int> prevMIN(vector<int>& heights){
        int size = heights.size();
        vector<int> prevmin(size,-1);
        stack<int> st;
        for(int i = size-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                prevmin[st.top()] = i;
                st.pop();
            }
            st.push(i);  
        }
        return prevmin;
    }
    vector<int> nextMIN(vector<int>& heights){
        int size = heights.size();
        vector<int> nextmin(size,size);
        stack<int> st;
        for(int i = 0;i<size;i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                nextmin[st.top()] = i;
                st.pop();
            }
            st.push(i);  
        }
        return nextmin;
    }
    int largestRectangleArea(vector<int>& heights) {

        if(heights.size()) return 0;

        int max_area = INT_MIN;

        vector<int> nextmin = nextMIN(heights);
        vector<int> prevmin = prevMIN(heights);

        for(int i=0;i<heights.size();i++){
            max_area = max(max_area,heights[i]*(nextmin[i]-prevmin[i]-1));
        }
        return max_area;
    }
};


/* <--- better solution with time complexity 62ms ---> */


// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int res = 0;
//         heights.insert(heights.begin(), 0);
//         heights.push_back(0);
//         vector<int> st;
//         st.push_back(0);
//         const int n = heights.size();
//         for (int i = 1; i < n; ++ i)
//         {
//             int& index = st.back();
//             if (heights[i] > heights[index])
//                 st.push_back(i);
//             else if (heights[i] == heights[index])
//                 index = i;
//             else if (heights[i] < heights[index]) 
//             {
//                 while (!st.empty() && heights[i] < heights[st.back()])
//                 {
//                     const int mid = heights[st.back()];
//                     st.pop_back();
//                     if (!st.empty())
//                     {
//                         const int d = i - st.back() - 1;
//                         res = max(res, d * mid);
//                     }        
//                 }
//                 st.push_back(i);
//             }
//         }
//         return res;
//     }
// };