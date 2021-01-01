class Solution {
public:
    //binary search, pay attention to detials
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int len = nums.size();
        int left = 0, right = len - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                //when "mid" lands within correct range
                right = left = mid;
                //expand "left" to left
                while(left >= 0 && nums[left] == target){
                    --left;
                }
                //expand "right" to right
                while(right < len && nums[right] == target){
                    ++right;
                }
                ++left;
                --right;
                ans[0] = left;
                ans[1] = right;
                break;
            }
        }
        return ans;
    }
};
