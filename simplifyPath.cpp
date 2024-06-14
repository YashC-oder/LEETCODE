class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr = "";

        path += '/';

        for(char ch : path){
            if(ch == '/'){
                if(curr == ".."){
                    if(!st.empty()) st.pop_back();
                }else if(curr != "" && curr != "."){
                    st.push_back(curr);
                }
                curr = "";
            }else{
                curr += ch;
            }
        }

        path = "";

        for(string str : st){
            path += "/" + str;
        }

        return path == ""? "/":path;
    }
};