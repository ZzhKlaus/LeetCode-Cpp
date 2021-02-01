class Solution {
public:
    //hash + sliding window
    //"ori" for recorsing characters in t, "cnt" for recording sliding window
    unordered_map <char, int> ori, cnt;
    bool check(){
            for(const auto &p: ori){
                if(cnt[p.first] < p.second){
                    return false;
                }
            }
            return true;
    }

    string minWindow(string s, string t) {    
        for(const auto& c:t){
            ++ori[c]; 
        }
        
        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1;

        while(r < int(s.size())){
            if(ori.find(s[++r]) != ori.end()){
                ++cnt[s[r]];
            }
            while(check() && l <= r){
                //record the minimum length and its position
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if(ori.find(s[l]) != ori.end()){
                    --cnt[s[l]];
                }
                ++l;
            }
        }
        return ansL == -1? string() : s.substr(ansL, len);
    }
};
