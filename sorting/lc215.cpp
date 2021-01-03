//215. 数组中的第K个最大元素

/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
*/
//method 1
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1, target = nums.size() - k;
        while(l < r){
            int mid = quickSelection(nums, l, r);
            if(mid == target){
                return nums[mid];
            }
            if(mid < target){
                l = mid + 1;
            } else {
                r = mid - 1;
            }

        }
        return nums[l];
    }

    int quickSelection(vector<int>& nums, int l, int r){
        int i = l + 1, j = r;
        while(true){
            while(i < r && nums[i] <= nums[l]){
                ++i;
            }
            //J停止于 轴值点nums[l] 的左边， 即一个比nums[l]小的点
            while(l < j && nums[j] >= nums[l]){
                --j;
            }
            //搜索完成都满足顺序
            if(i >= j){
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
        
    }
};