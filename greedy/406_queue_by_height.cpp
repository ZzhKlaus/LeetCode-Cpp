class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        //sort according to two conditions: 1. ascending order in first element
        //2. descending in second element when with same first order
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        vector<vector<int>> ans(n);
        for(const vector<int>& person : people){
            int space = person[1] + 1;
            //find the number of empty spaces in ans
            for(int i = 0; i < n; ++i){
                if(ans[i].empty()){
                    --space;
                    if(!space){
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
