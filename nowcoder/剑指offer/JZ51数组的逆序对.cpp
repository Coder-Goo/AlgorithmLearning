
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        vector<int> copy(n);  //将原数组进行复制，这点需要跟面试官进行确定，能不能修改原始数组
        for(int i = 0; i< n; i++) copy[i] = nums[i];
        vector<int> temp(n);
        return RreversePairsCount(copy,0, n-1,temp);
    }

    //计算在[l, r]之间部分的有序数对
    int RreversePairsCount(vector<int>& _copy, int l , int r, vector<int>& temp) {
        if(l == r) return 0; //l = r; 则闭区间内只有一个元素，不存在逆序对

        int mid = l + (r - l ) /2;
        //左右两个区间的逆序对
        int left_pairs = RreversePairsCount(_copy, l, mid , temp);
        int right_pairs = RreversePairsCount(_copy, mid+ 1, r, temp); //因为取的是闭区间，所以取： mid + 1;
        //合并两个有序区间时产生的逆序对
        int merge_pairs = Merger_Count(_copy, l, mid, r, temp);
        return left_pairs + right_pairs + merge_pairs;

    }

    //统计两个有序区间[l, mid] 和 [mid + 1, r] 合并时的有序对数量
    int Merger_Count(vector<int> & copy, int l, int mid,int r, vector<int>& temp) {
        for(int i = l ; i<= r; i++) temp[i] = copy[i];
        int i = l;
        int j = mid + 1;
        int count = 0;
        for(int k = l ; k <= r; k++) {
            if(i == mid+1) {
                copy[k] = temp[j];
                j++;
            }else if(j == r+1) {
                copy[k] = temp[i];
                i++;
            }else if(temp[i] <= temp [j]) {   //这里一定要是<= 没有等于归并排序就不是稳定排序了
                copy[k] = temp[i];
                i++;
            }else {
                copy[k] = temp[j];
                j++;
                count += (mid - i + 1);
            }
        }
        return count;
    }

};