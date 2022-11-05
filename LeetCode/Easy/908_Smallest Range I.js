/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
let smallestRangeI = function (nums, k) {
  nums.sort((a, b) => a - b);

  if (nums[0] + k >= nums[nums.length - 1] - k) return 0;
  else return nums[nums.length - 1] - k - (nums[0] + k);
};