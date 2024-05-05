class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 100000;
        for(int i=0;i<nums.size()-2;i++){
            int s = i+1;
            int e = nums.size()-1;
            int sum = nums[i];
            while(s < e){
                int diff = abs(sum + nums[e] + nums[s] - target);
                int currDiff = abs(ans - target);
                if(sum + nums[e] + nums[s] == target){
                    return sum + nums[e] + nums[s];
                }else if(sum + nums[e] + nums[s] > target){
                    if(diff < currDiff){
                        ans = sum + nums[e] + nums[s];
                    }
                    e--;
                }else{
                    if(diff < currDiff){
                        ans = sum + nums[e] + nums[s];
                    }
                    s++;
                }
            }
        }
        return ans;
    }
};