class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        bool dp[m +1][n+1];//为了便于表示空串，dp数组声明为m+1和n+1;
        //初始条件
        dp[0][0] = true;//空主串空正则
        for(int i = 1;i<= m; i++) dp[i][0] = false;//非空主串空正则
        for(int j = 1 ; j<= n; j++) { //空主串非空正则
            if(j>= 2 && p[j-1] == '*') dp[0][j] =dp[0][j-2];
            else dp[0][j] = false;
        }
        //开始动态规划
        for(int i = 1; i<= m; i++) {
            for(int j = 1; j<= n; j++) {

                if(p[j -1] == '*') {
                    if( j == 1) dp[i][j] = false;//正则字符串第一个就是*，那么肯定是不匹配
                    if(j-2>=0 && p[j-2] == s[i-1] || p[j-2] == '.') dp[i][j] = dp[i-1][j];
                    else dp[i][j] = dp[i][j-2];
                }
                else {
                    if(s[i-1] == p[j-1] || p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};

//解题思路：主串为S，正则串为P，设主串S长度为n,正则串P长度为m；用正则串来匹配主串，关注正则串最后一个元素
//最后一个元素是：字符，*或. 三种之一
//如果正则串P最后一个元素是字符，那么就看两个串的最后一个元素是否相等即S[N-1] ?= P[m-1]
//如果正则串P最后一个元素是.， 那么可以匹配S的任意一个元素；直接看S0~N-1和P0~m-2;
//如果正则串P最后一个元素是*， 那么和p[m-2]=c可以重复0次或多次，它们是一个整体c*,看s：
     // 最后一个元素S[n-1]！= c, 那么p的最后两个元素c*废了，能否匹配只看s0~n-1和P0~m-3;
     // 如果最后一个元素是多个c中的一个（此时s[n-1]=c或c='.', 主串s前移一个，正则串不动；看S0~N-2和P0~n-1


//算法思路：dp[i][j]表示s的前i个和p的前j个是否匹配；
//1. 对于最后一个是字符且相等或最后一个是.的情况下，dp[i][j] = dp[i-1][j-1];
//2. 对于最后一个是*的情况下：对于c*有看和不看两种情况
//       不看 直接砍掉c* 则dp[i][j] = dp[i][j-2]
//        看  正则串不动，主串前移一个 dp[i][j] = dp[i-1][j]


//初始条件：
//空主串和空正则    是可以匹配的dp[0][0] = true;
//非主空串和空正则  是不匹配的dp[i][0] = false;
//空串和非空正则    需要判断是否匹配：如“”和“a*b*”是在j=2和4的时候是匹配的,此时分为有*和无*
       //1.有* ，那么直接去掉*和*前一个字符即a*，即dp[0][j] = dp[0][j-2];
       //2. 没有*，那么肯定不匹配

```cpp 
//递归写法
class solution {
    bool matchcore(int a,int b){
        if(A[a]==0&&B[b]==0)return true;
        if(A[a]!=0&&B[b]==0)return false;
        if(B[b+1]=='*'){
            if(A[a]==B[b]||(B[b]=='.'&&A[a]!=0))
               return matchcore(a+1,b)||matchcore(a+1,b+2)||matchcore(a,b+2);//多个，一个，0个
            else return matchcore(a,b+2);
        }
        else if(A[a]==B[b]||(B[b]=='.'&&A[a]!=0))
            return matchcore(a+1,b+1);//一个
        return false;
    }
    string A;
    string B;

public:
    bool match(string str, string pattern) {
        A=str;
        B=pattern;
       return matchcore(0, 0);
    }

};


//动态规划写法：
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>>dp(m+1, vector<bool>(n+1, false));
        //初始条件
        dp[0][0] = true;

        for(int i = 1; i<= m; i++ ) {
            for(int j = 1; j<= n; j++) {  //i,j表示字符串里的第i和第j个字符，与实际下标相差1
                if(j>1 && p[j-1] == '*') {       //如果有*的情况
                    if( p[j-2] != s[i-1] && p[j-2] != '.') //不匹配 
                        dp[i][j] = dp[i][j-2];
                    else {
                        dp[i][j] = dp[i][j-2]       //匹配0次
                                || dp[i-1][j-2]     //匹配1次
                                || dp[i-1][j]   ;   //匹配多次
                    }

                } else if(p[j-1] == s[i-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};