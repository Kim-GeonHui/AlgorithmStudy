/**
 * @param {number[]} nums
 * @return {number}
 */
 let singleNumber = function(nums) {
  let count;
  let numArr = [];
  let answer;
  
  for (let i = 0; i < nums.length; i++) {
      if (numArr.indexOf(nums[i]) !== -1) continue;
      
      if (nums.filter(item => nums[i] === item).length === 1) {
          answer = nums[i];
          break;
      }
      
      numArr.push(nums[i]);
  }
  
  return answer;
};