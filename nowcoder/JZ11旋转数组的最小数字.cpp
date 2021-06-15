
//找到旋转数组的最小数字

//暴力
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size() == 0) throw "no elements";
        for(int i = 1; i< numbers.size(); i++) {
            if(numbers[i]- numbers[i-1] < 0) return numbers[i];
        }
        return numbers[0];
    }
};

//二分法：  定义双指针left, right, mid = left + (right - left)/2;   
//          1. 如果mid > right，说明最小值在mid~right之间  
//          2. 如果mid<right，说明在left ~ mid之间
//          3. 如果相等，说明可能在任何一个区间之间，通过right-- 缩小区间范围
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int right = numbers.size() -1;
        int left = 0; 
        while(left <= right) {
            int mid = left + (right - left)/2;
            if((mid -1 >= 0) && numbers[mid] - numbers[mid -1] < 0) return numbers[mid];
            if(numbers[mid] < numbers[right]) right = mid -1;
            else if(numbers[mid] > numbers[right]) left = mid + 1;
            else {
                right --;
            }
        }
        return numbers[left];  
    }
};