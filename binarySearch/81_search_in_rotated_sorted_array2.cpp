class Solution {
public:
    //binary search
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] == target) return true;
            if(nums[start] == nums[mid]){
                ++start;
            //"start" <= "mid": left half zone is monotonously increasing
            }else if(nums[start] <= nums[mid]){
                if(nums[mid] > target && target >= nums[start]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            // else, right half zone is monotonously increasing
            }else{
                if(nums[mid] < target && nums[end] >= target){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
