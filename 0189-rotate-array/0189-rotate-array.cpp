class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        cout<<k<<endl;
        reverse(nums.begin(),nums.begin()+(nums.size()-k));
        for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        cout<<endl;
        reverse(nums.begin()+(nums.size()-k),nums.end());
        reverse(nums.begin(),nums.end());
    }
};