class Solution {
public:
    //347变形题
    //击败了66.09%的用户
    string frequencySort(string s) {
        unordered_map<int, int> counts;
        int max_counts = 0;
        for(const char & c : s){
            max_counts = max(max_counts, ++counts[c - 'a']);
        }
        vector<vector<int>> buckets(max_counts + 1);
        for(const auto & p : counts){
            buckets[p.second].push_back(p.first);
        }

        string ans;
        for(int i = max_counts; i >= 0; --i){
            for(const int & num : buckets[i]){
                //repeat i times
                for(int j = 0; j < i; ++j){
                    ans.push_back(char(num + 'a'));
                } 
            }
        }
        return ans;
    }
};
