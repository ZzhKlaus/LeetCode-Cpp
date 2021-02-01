class Solution {
public:
    //binary search
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == nums[mid+1]){
                if((mid-left) % 2 == 0){
                    left = mid + 2;
                }else{
                    right = mid - 1;
                }
            }else if(nums[mid] == nums[mid-1]){
                if((mid - 1 - left) % 2 == 0){
                    left = mid + 1;
                }else{
                    right = mid - 2;
                }
            }else{
                return nums[mid];
            }
        }
        return nums[left];
    }
};

class Solution {
public:
    //Brute-force
    int singleNonDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i += 2){
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return nums.back();
    }
};

class Solution {
public:
    //hash, rute-force, slow
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(const auto & num : nums){
            ++cnt[num];
        }
        int i = 0;
        for(i; cnt[nums[i]] != 1; ++i);
        return nums[i];
    }
};
