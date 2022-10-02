/**
 * @param {number[]} nums
 * @return {number}
 */
 let pivotIndex = function(nums) {
  let arr1 = [];
  let arr2 = [];
  
  for (let i = 0; i < nums.length; i++) {
      arr1 = nums.slice(0, i);
      arr2 = nums.slice(i + 1);
      
      if (i === 0) arr1 = [0];
      if (i === nums.length - 1) arr2 = [0];
      
      if (arr1.reduce((a,b) => (a + b)) === arr2.reduce((a,b) => (a + b))) return i;
  }
  
  return -1;
};