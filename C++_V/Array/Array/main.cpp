//
//  main.cpp
//  Array
//
//  Created by edy on 2021/2/23.
//

#include <iostream>
#include <vector>

using namespace std;

//https://leetcode-cn.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(0==nums.size()) return 0;
        if (1==nums.size()) {
            return nums[0];
        }
        int ret = nums[0];
        vector<int> arr(nums.size(), 0);
        arr[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            arr[i] = max(arr[i-1]+nums[i], nums[i]);
            ret = max(ret, arr[i]);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {-2,-1};
    vector<int> arr(a, a+sizeof(a)/sizeof(int));
    int ret = Solution().maxSubArray(arr);
    return 0;
}
