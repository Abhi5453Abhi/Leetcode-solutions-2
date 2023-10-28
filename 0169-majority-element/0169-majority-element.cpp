class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int ct = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == element){
                ct++;
            }else{
                ct--;
                if(ct == 0){
                    element = nums[i];
                    ct = 1;
                }
            }
        }
        return element;
    }
};