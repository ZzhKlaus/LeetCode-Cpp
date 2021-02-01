class Solution {
public:
    //sliding window + hash
    //1. first moving "right" until there are k+1 different chars 
    //2. then move left to right until there are k diff chars 
    //3. record teh max length and goto 1.
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.empty() || k == 0) return 0;
        unordered_map<char, int> cnt;
        int len = s.size(), max_len = 1;
        for(int left = 0, right = 0; right < len; ++right){
            //counting the number of times of same char
            ++cnt[s[right]];
            while(cnt.size() > k){
                --cnt[s[left]];
                if(cnt[s[left]] == 0){
                    cnt.erase(s[left]);
                }
                ++left;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
