class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> ma;
        for(int i=0;i<s.size();i++){
            ma[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(ma[t[i]]){
                ma[t[i]]--;
            }else{
                return false;
            }
        }
        for(auto it:ma){
             if(it.second > 0)return false;
        }
        return true;
    }
};