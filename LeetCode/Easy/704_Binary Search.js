/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 let search = function(nums, target) {
  let pre = 0;
  let end = nums.length - 1;
  let mid;
  
  while(pre <= end) {
      mid = Math.floor((pre + end) / 2);
      
      if (nums[mid] === target) return mid;
      
      if (nums[mid] < target) {
          pre = mid + 1;
          continue;
      }
      
      if (nums[mid] > target) {
          end = mid - 1;
          continue;
      }
  }
  
  return -1;
};