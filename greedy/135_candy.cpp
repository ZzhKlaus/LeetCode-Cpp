class Solution {
public:
    //两次遍历
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n < 2) return n;
        vector<int> ans(n, 1);
        //从左到右， 若rating大于前一个，在其基础上+1
        for(int i=1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                ans[i] = ans[i-1]+1;
            }
        }
        //从右到左， 若大于右边位， 取右边糖果数+1 和 自身的最大值，因只需比右边大即可
        for(int i = n-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                ans[i] = max(ans[i], ans[i+1]+1);
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};
