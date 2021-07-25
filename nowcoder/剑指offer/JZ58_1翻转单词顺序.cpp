//先去除空格，再用滑动窗口！！！


class Solution {
public:
    //去除空格
     void RemoveSpace(string &s) {
        //去除头部的空格
        int n = s.size();
        int fast= 0;
        while(fast < n && s[fast] == ' ') {
            fast ++;
        }
        int low = 0;
        while(fast < n) {
            if(s[fast] == ' ' && s[fast -1] == ' ') {
                fast ++; 
                continue;
            }
            s[low ++ ] = s[fast ++];
        }
        if(low -1 > 0 && s[low-1] == ' ') s.resize(low -1);
        else s.resize(low);
    }

    string reverseWords(string s) {
        RemoveSpace(s);
        int left =0, right = s.size() -1;
        while(left <right ) {
            swap(s[left],s[right]);
            left ++;
            right --;
        }

        left = 0; 
        right = 0;

        while(right < s.size()) {
            right++;
            if(s[right]==' ' ) { //遇到空格或到达末尾就需要翻转了  
                int l = left , r = right-1;
                while(l<r) {
                    swap(s[l],s[r]);
                    l++;
                    r--;
                }
                left = right+1;
            } else if(right == (s.size() -1)) {
                int l = left , r = right;
                while(l<r) {
                    swap(s[l],s[r]);
                    l++;
                    r--;
                }
            }
        }
        return s;
    }  
};