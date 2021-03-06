class Solution {
public:
    //贪心策略：优先选择结尾小且不相交的区间
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        //排序，根据结尾大小
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        int total =0, prev = intervals[0][1];
        for(int i = 1; i < n; ++i){
            if(intervals[i][0] >= prev){
                prev = intervals[i][1];
            } else{
                ++total;
            }
        }
        return total;
    }
};


class Solution {
public:
    //贪心策略：按照起始位置从小到大排序， 两区间有三种情况，1.无重叠，不用移除 2. 包含关系， 移除终点更大的区间，留下更多空间 3.部分重叠，比如 [1, 3] 和 [2,4]， 移除终点更大区间
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        int ans = 0, prev = intervals[0][1];
        for(int i = 1; i < n; ++i){
            //case:3
            if(intervals[i][0] < prev){
                //case:2
                if(intervals[i][1] < prev){
                    prev = intervals[i][1];
                }
                ++ans;
            } else{
                //case:1
                prev = intervals[i][1];
            }
        }
        return ans;
    }
};

class Solution {
public:
    //动态规划, 时间复杂度O（n^2）, 空间复杂度O(n)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        int n = intervals.size();
        vector<int> dp(n, 0);
        //排序
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        
        dp[0] = 1;
        for(int i = 1; i < n; ++i){
            int MAX = 0;
            //i之前所有区间都有可能和i有重叠，一一比较
            for(int j = i-1; j >= 0; --j){
                if(intervals[i][0] >= intervals[j][1]){
                    MAX = max(dp[j], MAX);
                }
            }
            dp[i] = MAX + 1;
        }
        int m = *max_element(dp.begin(), dp.end());
        return n - m;
    }
};
