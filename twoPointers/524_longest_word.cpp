class Solution {
public:
    //按单词长度降序及字母顺序升序排序单词列表。从头开始check排序列表中的单词，返回第一个是str字符串子序列的单词即可。
    string findLongestWord(string str, vector<string>& dict) {
        auto cmp = [&](const auto& a, const auto& b) {
            return a.size() > b.size() || (a.size() == b.size() && a < b);
        };
        sort(dict.begin(), dict.end(), cmp);

        for (const auto& word : dict) {
            if (isSubSequence(word, str)) {
                return word;
            }
        }

        return "";
    }


    int isSubSequence(string a, string b) {
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i == a.size();
    }

};
