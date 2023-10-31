class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string temp = "";
        string newStr = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ' && temp.size() > 0){
                cout<<temp.size()<<endl;
                reverse(temp.begin(),temp.end());
                if(newStr.size() > 0)newStr += " ";
                newStr += temp;
                temp = "";
            }else if(s[i] != ' '){
                temp += s[i];
            }
        }
        if(temp.size() > 0 && newStr.size() > 0)newStr += " ";
        reverse(temp.begin(),temp.end());
        newStr += temp;
        
        return newStr;
    }
};