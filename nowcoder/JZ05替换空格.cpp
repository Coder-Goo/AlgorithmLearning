class Solution {
public:
    string replaceSpace(string s) {

//第一次写，没考虑到字符增加
        // for(auto &a:s) {
        //     if (a == ' ' ) {
        //         a='%20';
        //     }
        // }

//第二次写，官方另外重新制作一个数组，数组的大小是原来的三倍

        // string s3;
        // s3.resize((s.size()*3));
        // for(int i = 0, j=0; i < s.size(); ++i) {
        //     if (s[i] == ' ') {
        //         s3[j++] = '%';
        //         s3[j++] ='2';
        //         s3[j++] ='0';
        //         continue;
        //     }
        //     s3[j++]=s[i];
        // }
        // return s3;

//第三次写
//用重新定义一个字符串，用双指针,先把字符串的大小变为把空格都替换为%20的大小，即每有一个空格，就扩充两个字符大小
        //先得到空格数
        int count = 0; 
        for(auto a:s) {
            if(a == ' ') count ++;
        }
        int pre = s.size() - 1;
        s.resize(s.size() + count * 2);
        for(int curr = s.size()-1; pre >= 0; --pre) {
            if(s[pre] == ' ') {
                s[curr--] = '0';
                s[curr--] = '2';
                s[curr--] = '%';
                continue;
            }
            s[curr--] = s[pre];
        }
        return s;
    }
};


//如何确定一个字符是空格？
//  if (a == ' ' ) {
//      a='%20';
//   }

//因为要替换成%20，这个数太多，如果换成‘%’是可行的，而替换成%20是增加了三个字符

//string类型不支持string s(3)这种操作，其他容器是支持的，所以第二次写的时候用了resize()函数，resize之后是空串
//resize()函数由两种方式：resize(n,val)和resize（n);