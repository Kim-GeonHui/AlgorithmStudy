/**
 * @param {number[]} nums
 * @return {number}
 */
 let thirdMax = function(nums) {
  nums = [...new Set(nums)];
  nums.sort((a,b) => a-b);
  
  if (nums.length <= 2) return nums[nums.length - 1];
  else return nums[nums.length - 3];
};