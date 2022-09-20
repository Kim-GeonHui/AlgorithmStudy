/**
 * @param {number[]} nums
 * @return {number[]}
 */
 let findDisappearedNumbers = function(nums) {
  let answer = [];
  let size = nums.length;
  
  nums = [...new Set(nums)];
  for (let i = 1; i <= size; i++) {
      if (nums.indexOf(i) === -1) answer.push(i);
  }
  
  return answer;
};