class Solution {
public:
    bool palindrome(const std::string& s, int i, int j)
    {
        for ( ; i < j && s[i] == s[j]; ++i, --j);
        return i >= j;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        for ( ; i < j && s[i] == s[j]; ++i, --j); 
        //acts like given a more chance to delete a char      
        return palindrome(s, i, j - 1) || palindrome(s, i + 1, j);
    }
};
