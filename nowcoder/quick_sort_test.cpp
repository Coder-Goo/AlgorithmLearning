
#include<vector>
#include<iostream>  
#include<string>
using namespace std;

void QuickSort( vector<string>& vec, int l, int r) {
    if(l >= r) return;
    int i = l, j = r;
    while (i < j) { 
            //******************************要把j--先放第一，然后再i++, 因为你以左节点l作为锚点，要不就排序不对了*****
        while(i<j && vec[j] + vec[l] >= vec[l] + vec[j]) j --;//虽然是字符串，但是 10+2<2+10 仍然成立
        while(i<j && vec[i] + vec[l] <= vec[l] + vec[i]) i ++;
        swap(vec[i], vec[j]);
    }
    swap(vec[i],vec[l]);
    QuickSort(vec,l, i-1);
    QuickSort(vec, i+1, r);
} 

string minNumber(vector<int>& nums) {
    vector<string> vec;
    for(int i = 0; i< nums.size(); i++) {
        vec.push_back(to_string(nums[i]));
    }
    QuickSort(vec, 0, vec.size()-1);
    string res;
    for(auto v:vec) {
        res+= v;
    }
    return res;
}

int main() {
    vector<int> vec = {2,10};
    std::cout<<minNumber(vec);
    return 0;
}