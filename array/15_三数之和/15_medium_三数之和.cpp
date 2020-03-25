/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.16%)
 * Likes:    1923
 * Dislikes: 0
 * Total Accepted:    182.9K
 * Total Submissions: 699.3K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int > vtemp;
        sort(nums.begin(), nums.end()); // sort

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int leftPoint = i + 1;
            int rightPoint = nums.size() - 1;
            while (leftPoint < rightPoint) {
                int sum = nums[leftPoint] + nums[rightPoint] + nums[i];
                if (sum < 0) {
                    leftPoint++;
                } else if(sum > 0) {
                    rightPoint--;
                } else{
                    vector<int > vtemp{nums[i], nums[leftPoint], nums[rightPoint]};
                    res.push_back(vtemp);
                    vtemp.clear();
                    while (leftPoint < rightPoint && nums[leftPoint] == nums[leftPoint+1]) {
                        leftPoint++;
                    }
                    while (leftPoint < rightPoint && nums[rightPoint] == nums[rightPoint-1]) {
                        rightPoint--;
                    }
                    leftPoint++;
                    rightPoint--;
                }
            }
        }
        return res;
    }   
};
// @lc code=end

