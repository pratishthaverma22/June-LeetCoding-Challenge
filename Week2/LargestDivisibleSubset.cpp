/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:
Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:
Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n < 1)
           return nums;
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; ++i)
           dp[i].push_back(nums[i]);
        vector<int> res;
        res.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i)
        {
           for(int j = 0; j < i; ++j)
           {
               if(nums[i]%nums[j] == 0)
               {
                 if(dp[i].size() < dp[j].size()+1)
                 {
                     dp[i] = dp[j];
                     dp[i].push_back(nums[i]);
                 }
               }
           }
           if(dp[i].size() > res.size())
               res = dp[i];
        }
        return res;
        
    }
};
