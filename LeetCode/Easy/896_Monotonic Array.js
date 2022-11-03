/**
 * @param {number[]} nums
 * @return {boolean}
 */
 let isMonotonic = function(nums) {
  let arr = [...nums];
  
  arr.sort((a, b) => a - b);
  if (JSON.stringify(arr) === JSON.stringify(nums)) return true;
  
  arr.reverse();
  if (JSON.stringify(arr) === JSON.stringify(nums)) return true;
  
  return false;
};