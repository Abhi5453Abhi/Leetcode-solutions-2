class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        cout<<s<<endl;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                newS += s[i];
            }else if(s[i] >= 'A' && s[i] <= 'Z'){
                newS += tolower(s[i]);
            }else if(s[i] >= '0' && s[i] <= '9') {
                newS += s[i];
            }
        }
        int j=newS.size()-1;
        cout<<newS<<endl;
        for(int i=0;i<newS.size()/2;i++){
            if(newS[i] == newS[j]){
                j--;
            }else{
                return false;
            }
        }
        return true;

    }
};