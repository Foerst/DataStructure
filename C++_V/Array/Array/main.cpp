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

class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) {
            return vector<int>{-1, -1};
        }

        int l = 0;
        int r = nums.size()-1;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid]==target){
                int left = mid;
                int right = mid;
                while(left>0&&nums[left-1]==nums[left]) left--;
                while(right+1<nums.size()&&nums[right+1]==nums[right]) right++;
                return vector<int>{left, right};
            } else if(nums[mid]<target){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return vector<int>{-1, -1};
    }
};

int main(int argc, const char * argv[]) {
//    int a[] = {-2,-1};
//    vector<int> arr(a, a+sizeof(a)/sizeof(int));
//    int ret = Solution().maxSubArray(arr);
    vector<int> tmp{5,7,7,8,8,10};
    vector<int> data = Solution1().searchRange(tmp, 8);
    return 0;
}
