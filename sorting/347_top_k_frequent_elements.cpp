class Solution {
public:
    //桶排序， 先用hash记录不同数出现频率，再将 频率-数字 对放入桶中，输出前k高桶
    //击败了98.67%的用户
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int max_count = 0;
        for(const int & num: nums){
            max_count = max(max_count, ++counts[num]);
        }

        vector<vector<int>> buckets(max_count + 1);
        for(const auto & p: counts){
            buckets[p.second].push_back(p.first);
        }

        vector<int> ans;
        for(int i = max_count; i >= 0 && ans.size() < k; --i){
            for(const int & num: buckets[i]){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
