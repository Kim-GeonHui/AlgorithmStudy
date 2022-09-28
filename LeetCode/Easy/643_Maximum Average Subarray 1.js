/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
 let findMaxAverage = function(nums, k) {
  let arr = new Array(nums.length - k + 1);
  arr.fill(0);
  
  for (let i = 0; i < nums.length - k + 1; i++) {
      for (let j = i; j < i + k; j++) arr[i] += nums[j];
  }

  return Math.max(...arr) / k;
};