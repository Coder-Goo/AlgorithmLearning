输入字符串，返回它的排列数组
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]

思路：回溯算法：
class Solution {
public:
    vector<string> permutation(string s) {
        length = s.size();
        BackTacking(s);
        return result;
    }
private:
    int length;
    string path;
    vector<string> result;

    void BackTacking(const string &s) {
        if(path.size() == length ) {
            result.push_back(path);
            return;
        }
        for(int i= 0; i< length; i++) {
            if(find(path.begin(), path.end(), s[i]) != path.end()) continue; //排除重复！！但是这样写会导致如果输入
            //的字符串有重复的字符，将导致失败
            else {
                path.push_back(s[i]);
                BackTacking(s);
                path.pop_back();
            }  
        }
    }
};

//后面说添加标志位，将使用过的标志位true； 本例子中使用flags数组来进行标志
//但是如果输入为“aab”会输出["aab","aba","aab","aba","baa","baa"]，包含重复的
class Solution {
public:
    vector<string> permutation(string s) {
        length = s.size();
        flags.resize(s.size(), false);
        BackTacking(s);
        return result;
    }

private:
    int length;
    string path;
    vector<string> result;
    vector<bool> flags;

    void BackTacking(const string &s) {
        if(path.size() == length ) {
            result.push_back(path);
            return;
        }
        for(int i= 0; i< length; i++) {
            if(flags[i]) continue;
            else {
                path.push_back(s[i]);
                flags[i] = true;
                BackTacking(s);
                path.pop_back();
                flags[i] = false;
            }
            
        }
    }
};

//这一题需要用到回溯算法的剪枝操作！！！！
//使用flags还不够，需要对数组进行排序，
class Solution {
public:
    vector<string> permutation(string s) {
        length = s.size();
        sort(s.begin(), s.end());
        flags.resize(s.size(), false);
        BackTacking(s);
        return result;
    }

private:
    int length;
    string path;
    vector<string> result;
    vector<bool> flags;

    void BackTacking(const string &s) {
        if(path.size() == length ) {
            result.push_back(path);
            return;
        }
        for(int i= 0; i< length; i++) {
            if(i>=1 && s[i] == s[i-1] && flags[i-1]) continue; //输入字符中有重复的字符时剪枝专用
            else if(flags[i] == false){                        //这里是去除重复选择的，
                path.push_back(s[i]);
                flags[i] = true;
                BackTacking(s);
                path.pop_back();
                flags[i] = false;
            }
            
        }
    }
};