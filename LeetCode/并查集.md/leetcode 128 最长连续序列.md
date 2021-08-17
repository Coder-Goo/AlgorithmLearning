leetcode 128 最长连续序列
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

思路： 肯定是枚举每个数x，然后内层枚举看是否有x+1, x+2,x+3...
可以将这些数放入一个哈希表中，用count来进行内层的枚举，减少循环的次数
另外，在x,x+1,x+2,x+3,,,之后，那么从x+1开始就不用枚举了，因为肯定少于从x开始的

所以剪枝：对x进行判断的时候，存在x-1的直接跳过，

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> my_set;
        for(int n: nums) my_set.insert(n);
        int res= 0;
        for(int n: my_set) {
            int temp_res = 1;
            if(!my_set.count(n -1)) {    //剪枝操作
                int cur = n;
                while(my_set.count(cur+1)) {
                    cur += 1;
                    temp_res ++;
                }
            }
            res = max(res,temp_res );
        }
        return res;
    }
};
```

并查集：  将连续的看做是一个整体：
//并查集解法
//将连续的作为一个集合，并更新集合里的元素
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int n: nums) {
            parent.insert({n, n});     //首先初始化自己为自己的父亲
            set_size.insert({n, 1});   //初始化每个集合的个数为1
        }
        int res = 1;
        for(int n: nums) {
            if(set_size.count(n+1)) {
                res = max(res, merge(n, n+1));
            }
        }
        return res;
    }

private:
    unordered_map<int,int>parent, set_size;

    int find(int x) {
        int p = x;
        while( p != parent[p]){
            p = parent[p];
        }
        return p;
    }

    int merge(int x, int y) {
        int px = find(x), py = find(y);
        if(px != py) {
            parent[px] = py;
            set_size[py] += set_size[px];
        }
        return set_size[py];
    }
};
```






