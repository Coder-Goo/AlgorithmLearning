//快排是以左边的元素为锚点，这样的如果左边是最小值或最大值的情况就不好
//优化方法：随机取锚点

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
void quickSort(vector<int>& arr, int l, int r) {
    // 子数组长度为 1 时终止递归
    if (l >= r) return;
    //随机选取锚点
    int pivot = rand()%(r-l +1) +l;
    swap(arr[pivot],arr[r]);           //将锚点换到后面，保证锚点不会被交换
    int i = l;
    for(int j = l; j<=r-1;j++) {     //遍历数组【l,r】之间的部分
        if(arr[j] < arr[r]) {      //如果小于锚点，将其换到前面去；如果arr[i]也小于锚点，这也不怕，
                                   //因为后面还会被遍历到
            swap(arr[j],arr[i]);  //小于锚点的部分统统换到左边
            i = i + 1;
        }
    }

    //交换锚点和位置为i(j)的点; 此时i = j ;
    swap(arr[i], arr[r]);
    //递归左（右）子数组执行哨兵划分
    quickSort(arr, l, i - 1);
    quickSort(arr, i + 1, r);
}

int main() {
    vector<int> vec = {3,2,4,7,3,5,3,5,9,13};
    //vector<int> vec = {5,3,2,3,1};
    quickSort(vec, 0, vec.size()-1);
    for(auto v:vec) cout<<v<<endl;
    return 0;
}