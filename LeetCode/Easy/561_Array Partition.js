/**
 * @param {number[]} nums
 * @return {number}
 */
 let arrayPairSum = function(nums) {
  let answer = 0;
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length / 2; i++) answer += nums[2 * i];
  
  return answer;
};