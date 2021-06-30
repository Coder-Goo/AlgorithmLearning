#include<iostream>
#include<vector>

using namespace std;

//堆的插入写法：
    void HeapInsert(vector<int> &vec, int index) {
        while(vec[index] > vec[(index-1)/2]) {   //这里的比较是比较了两种情况：
        //1. 孩子大于父亲 2.极端情况，index -1 == -1了，表示index已经等于0了;此时也跳出循环
            swap(vec[index],vec[(index-1)/2]);
            index = (index-1)/2;
        }
    }

//移除index处的节点后堆的重建方法
//index为需要调整的父节点下标，heapsize用来判断孩子是否越界;一开始的时候heapsize等于vec.size();而不是size -1;
    void MaxHeap(vector<int>&vec, int index, int heapsize) {
        //父亲下标
        int dad = index;
        //左孩子的下标； 右孩子下标left_son+1;
        int left_son = 2*dad+1;
        while(left_son < heapsize) {
            //左右孩子决出最大值的下标
            int largest = left_son +1 < heapsize && vec[left_son+1] > vec[left_son] ? left_son + 1: left_son;
            //父亲和最大孩子之间pk得出最大值
            largest = vec[largest] > vec[dad] ? largest:dad;
            //如果比较下来，父亲还是最大的，那么不用比了，因为父亲>孩子，孩子>孩子的孩子；所以不用比了，直接跳出；
            if(largest == dad) return;
            //如果父亲不是最大，那么还需要往下调整
            swap(vec[largest], vec[dad]);
            dad = largest;
            left_son = dad*2 +1;
        }

    }

//排序主函数                                                                                             
    void HeapSort(vector<int>& vec) {
        if(vec.size() < 2) return;
        int heap_size = vec.size();
        //先将元素插入堆中
        for(int i = 0; i< heap_size;i++) {
            HeapInsert(vec, i);
        }

        //交换第一个和最后一个元素，并将堆减小 
        swap(vec[0],vec[--heap_size]);

        while(heap_size > 0) {
            MaxHeap(vec, 0, heap_size);
            swap(vec[0],vec[--heap_size]);
        }
    }   


int main() {
    vector<int>vec = {3,25,6,2,7,35,25,6,36,3,4,7,8,3};
    HeapSort(vec);
    for(int i =0; i< vec.size(); i++) {
        std::cout<<vec[i]<<" ";
    }
    return 0;
}