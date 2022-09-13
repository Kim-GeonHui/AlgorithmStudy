/**
 * @param {number[]} nums
 * @return {string[]}
 */
 let summaryRanges = function(nums) {
  let index = 0;
  let pre = 0;
  let result = [];
  let str = "";
  
  while (index < nums.length) {
      if (nums[index] + 1 !== nums[index + 1]) {
          if (pre === index) str = String(nums[pre]);
          else str = nums[pre] + "->" + nums[index];
          result.push(str);
          str = "";
          pre = index + 1;
      }
      
      index++;
  }
  
  return result;
};