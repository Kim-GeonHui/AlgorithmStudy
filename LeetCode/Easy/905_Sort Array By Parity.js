/**
 * @param {number[]} nums
 * @return {number[]}
 */
 let sortArrayByParity = function(nums) {
  let arr1 = nums.filter(item => item % 2 === 0);
  let arr2 = nums.filter(item => item % 2 !== 0);
  
  return arr1.concat(arr2);
};