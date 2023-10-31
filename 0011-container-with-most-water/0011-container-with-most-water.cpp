class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maxArea = -1;
        while(i < j){
            int mini = min(height[i],height[j]);
            maxArea = max(
                maxArea,
                (j-i)*mini
            );
            if(height[i] > height[j])j--;
            else i++;
        }
        return maxArea;
    }
};