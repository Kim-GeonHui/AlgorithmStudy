/**
 * @param {number[]} nums
 * @return {number}
 */
 let dominantIndex = function(nums) {
  let arr = [...nums];
  let end = nums.length - 1;
  nums.sort((a, b) => a - b);
  
  if (nums[end] >= nums[end - 1] * 2) return arr.indexOf(nums[end]);
  else return -1;
};