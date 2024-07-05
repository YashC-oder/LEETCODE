class Solution {
public:
    string decodeString(string s) {
        int length = s.size();
        stack<pair<int,string>> st;
        string str = "";
        int count = 0;

        for(int i =0;i<length;i++){
            char current = s[i];
            if(isalpha(current)){
                str += current;
            }else if(isdigit(current)){
                count = count * 10 + current - '0';
            }else if(current == '['){
                st.push({count,str});
                count = 0;
                str = "";
            }else if(current == ']'){
                string prefixStr = st.top().second;
                int counter = st.top().first;
                st.pop();

                while(counter--){
                    prefixStr += str;
                }
                str = prefixStr;
            }
        }

        return str;
    }
};