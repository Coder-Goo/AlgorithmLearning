
//求一个字符串第一个只出现一次的字符

class Solution {
public:
    char firstUniqChar(string s) {

        unordered_map<char, int>i_map;
        for(char ch : s ) {
            i_map[ch]++;
        }
        for(int i = 0; i< s.size(); i++) {
            if(i_map[s[i]] == 1) return s[i];
        } 
        return ' ';
    }
};