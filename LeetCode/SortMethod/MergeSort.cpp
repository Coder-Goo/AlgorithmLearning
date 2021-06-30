#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<int>temp;
//归并排序;后序遍历
    void MergeSort(vector<int> &vec, int l, int r) {
        if(l >= r) return;
        int mid = l+(r-l)/2; 

        MergeSort(vec, l, mid);   //如何划分区间，即mid属于左半部分还是右半部分？！！！！
        MergeSort(vec, mid +1, r);

        //此时左右两部分都已经分排好序了；将左右两部分合成一部分
        int i= l, j = mid +1;
        int count= l;
        while(i<= mid && j <= r) {
            if(vec[i]<= vec[j]) {
                temp[count++] = vec[i++]; 
            }else {
                temp[count++] = vec[j++];
            }
        }
        while(i<= mid) {
            temp[count++] = vec[i++];
        }
        while(j<=r) {
            temp[count ++] = vec[j++];
        }
        for(int k= l; k<= r; k++) {
            vec[k] = temp[k];
        }
    }

    int main() {
        //vector<int> vec = {3,2,4,7,3,5,3,5,9,13};
        vector<int> vec = {-2,3,-5};
        temp.resize(vec.size());
        MergeSort(vec, 0, vec.size()-1);
        for(auto v:vec) cout<<v<<endl;
        return 0;
    }