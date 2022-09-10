/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 let searchInsert = function(nums, target) {
  let tempArr = nums.filter(item => item < target);
  return tempArr.length;
};