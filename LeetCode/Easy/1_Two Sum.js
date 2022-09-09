/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
 var twoSum = function(nums, target) {
  for (let i = 0; i < nums.length; i++) {
      if (nums.indexOf(target-nums[i])!==-1)
          return [i, nums.indexOf(target-nums[i])];
  }
};