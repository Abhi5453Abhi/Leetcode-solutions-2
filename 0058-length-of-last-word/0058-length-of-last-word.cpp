class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp = "";
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                if(temp.size() == 0)continue;
                ans = temp.size();
                cout<<temp<<endl;
                temp = "";
            }else{
                temp += s[i];
                cout<<s[i]<<" ";
            }
        }
        if(temp.size() == 0)return ans;
        return temp.size();
    }
};