class Solution {
public:
    int candy(vector<int>& ratings) {
        int total = ratings.size();
        if(total < 2){
            return total;
        } 
        vector<int> num(total, 1);
        for(int i = 1; i< total; i++){
            if(ratings[i] > ratings[i-1]) num[i] = num[i-1] + 1;
        }
        for(int i = ratings.size()-1; i>0; i--){
            if(ratings[i-1] > ratings[i]) num[i-1] = max(num[i-1], num[i]+1);
        }
        return accumulate(num.begin(), num.end(), 0);
    }
};
