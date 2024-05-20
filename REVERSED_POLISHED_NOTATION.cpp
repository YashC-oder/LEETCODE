class Solution {
public:
    bool isnum(string token){
        return !(token=="+"||token=="-"||token=="*"||token=="/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        reverse(tokens.begin(),tokens.end());
        while(!tokens.empty()){
            if(isnum(tokens.back())){
                st.push(stoi(tokens.back()));
            }else{
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                string op = tokens.back();
                if(op=="+") st.push(num1+num2);
                else if(op=="-") st.push(num1-num2);
                else if(op=="*") st.push(num1*num2);
                else if(op=="/") st.push(num1/num2);
            }
            tokens.pop_back();
        }
        return st.top();
    }
};