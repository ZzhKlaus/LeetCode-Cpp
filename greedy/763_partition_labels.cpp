class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.length();
        int last[26];
        //record the last position of every exist character 
        for (int i = 0; i < len; i++) {
            last[S[i] - 'a'] = i;
        }
        vector<int> ans;
        int start = 0, end = 0;
        for(int i = 0; i < len; ++i){  
            end = max(end, last[S[i] - 'a']);
            if(i == end){
                //partition length
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};
