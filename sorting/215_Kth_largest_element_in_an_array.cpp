class Solution {
public:
    //快速选择，基于快速排序算法，最好先打乱数组
    //击败了14.95%的用户
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1, target = nums.size() - k;
        while(l<r){
            int mid = quickSelection(nums, l, r);
            if(mid == target){
                return nums[mid];
            }
            if(mid < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return nums[l];
    }

    int quickSelection(vector<int>& nums, int l, int r){
        int i = 1 + l, j = r;
        while(true){
            while(i < r && nums[i] <= nums[l]){
                ++i;
            }  
            while(j > l && nums[j] >= nums[l]){
                --j;
            } 
            if(i >= j){
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
};
