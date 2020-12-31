class Solution {
public:
    //找拐点问题，当遇到value[i] > value[i+1]时， 要么改变让value[i]=value[i+1], 要么value[i+1] = value[i]， 这是要比较value[i-1] 和 value[i+1]大小
    //i.e, 若 i-1, i， i+1 大小为 4, 5, 3, value[i-1] > value[i+1], 只能让value[i+1]上移变为5
    //若 i-1, i， i+1 大小为 3, 5， 4， value[i+1]可以上移或者下移，但是可能 value[i+2] 为 4, 选择上移无法消除拐点，最好下移
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i){ 
            if(nums[i] > nums[i + 1]){
                ++count;
                if(count > 1){
                    return false;
                }
                if(i - 1 >= 0 && nums[i-1] > nums[i+1]){
                    nums[i+1] = nums[i];
                } else {
                    nums[i] = nums[i+1];
                }
            }
        }
        return true;
    }
};
