class Solution {
private:
string rle(string str){
    
    string res = "";
    char previous = str[0];
    int count = 1;
    for(int i = 1;i<str.size();i++){
        if(str[i] == previous){
            count++;
        }else{
            res += to_string(count) + previous;
            previous = str[i];
            count = 1;
        }
    }
    return res + to_string(count) + previous;
}
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        return rle(countAndSay(n-1));
    }
};