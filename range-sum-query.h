#include <iostream>
using namespace std;
#include <vector>

class NumArray {
public:
    vector<int> Psum;
    NumArray(vector<int>& nums)
    {
        Psum.resize(nums.size());
        Psum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            Psum[i] = Psum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right)
    {
        if(left == 0)
        {
            return Psum[right];
        }
        return Psum[right] - Psum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */