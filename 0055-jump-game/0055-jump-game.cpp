class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];
        if(maxJump == 0 && nums.size() != 1)return false;
        if(maxJump == 0 && nums.size() == 1)return true;
        for(int i=1;i<nums.size();i++){
            maxJump = max(maxJump, nums[i]+i);
            if(maxJump >= nums.size()-1)return true;
            if(nums[i] == 0 && maxJump <= i)return false;
            cout<<maxJump<<" ";
        }
        if(maxJump >= nums.size())return true;
        return false;
    }
};