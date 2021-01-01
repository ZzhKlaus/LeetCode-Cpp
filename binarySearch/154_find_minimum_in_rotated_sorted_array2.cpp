class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int start = 0, end = len - 1;
        int ans =  min(nums[start], nums[end]);
        while(start < end){
            int mid = (start + end) / 2;
            if(nums[mid] < nums[end]){
                end = mid;
            }else if (nums[mid] > nums[end]){
                start = mid + 1;
            }else{
                end -= 1;
            }
        }
        return nums[start];
    }
};
