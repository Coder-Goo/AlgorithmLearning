#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//快速排序：以左节点为锚点，
void quickSort(vector<int>& arr, int l, int r) {
    // 子数组长度为 1 时终止递归
    if (l >= r) return;
    // 哨兵划分操作（以 arr[l] 作为基准数）
    int i = l, j = r;
    while (i < j) {
        while (i < j && arr[i] < arr[l]) i++;
        while (i < j && arr[j] > arr[l]) j--;
        swap(arr[i], arr[j]);
        //i++;j--;                                //*******不能这样写了！！！！
    }
    //交换锚点和位置为i(j)的点; 此时i = j ;
    swap(arr[i], arr[l]);
    
    //递归左（右）子数组执行哨兵划分
    quickSort(arr, l, i - 1);
    quickSort(arr, i + 1, r);
}

int main() {
    //vector<int> vec = {3,2,4,7,3,5,3,5,9,13};
    vector<int> vec = {5,2,3,1};
    quickSort(vec, 0, vec.size()-1);
    for(auto v:vec) cout<<v<<endl;
    return 0;
}