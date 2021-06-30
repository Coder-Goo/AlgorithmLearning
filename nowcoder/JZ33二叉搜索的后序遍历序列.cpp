//空间复杂度太高！！！
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        if(n==0) return true;
        if(n == 1) return true;
        int root = postorder[n-1];
        int index = 0;
        for(;index <n-1 && postorder[index] <root;index++) {
        }
        if(index == n-1) {
            vector<int> left(postorder.begin(), postorder.begin() + index);
            return verifyPostorder(left);
        }
        else if(index == 0 ) {
             vector<int> right(postorder.begin() + index, postorder.end()-1);
             for(auto i: right) if(i<root) return false;
             return verifyPostorder(right);
        } else {
            vector<int> left(postorder.begin(), postorder.begin() + index);
            vector<int> right(postorder.begin() + index, postorder.end()-1);
            for(auto i: right) if(i<root) return false;
            return verifyPostorder(left) && verifyPostorder(right);
        }
        
    } 
};