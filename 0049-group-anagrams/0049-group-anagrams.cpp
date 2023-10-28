class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > ma;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            ma[strs[i]].push_back(temp);
        }
        for(auto it:ma){
            // cout<<it.first<<" ";
            vector<string> v;
            for(int i=0;i<it.second.size();i++){
                v.push_back(it.second[i]);
                // cout<<it.second[i]<<" ";
            }
            // cout<<endl;
            ans.push_back(v);
        }
        return ans;
    }
};