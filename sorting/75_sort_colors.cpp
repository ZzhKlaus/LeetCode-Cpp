class Solution {
public:
    //using quickSort
    //击败了100.00%的用户
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len;
        quick_sort(nums, l, r);
    }

    void quick_sort(vector<int> & nums, int l, int r){
        if(l+1 >= r){
            return;
        }
        int first = l, last = r - 1, key = nums[first];
        while(first < last){
            while(first < last && nums[last] >= key){
                --last;
            }
            nums[first] = nums[last];
            while(first < last && nums[first] <= key){
                ++first;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        quick_sort(nums, l, first);
        quick_sort(nums, first+1, r);
    }
};
