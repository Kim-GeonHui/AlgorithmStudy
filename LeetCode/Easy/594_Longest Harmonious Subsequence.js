/**
 * @param {number[]} nums
 * @return {number}
 */
 let findLHS = function(nums) {
  let arr = [...new Set(nums)];
  arr.sort((a, b) => a - b);
  let answer = [0];
  
  for (let i = 0; i < arr.length - 1; i++) {
      if (arr[i] + 1 === arr[i + 1]) answer.push(nums.filter(item => item === arr[i] || item === arr[i + 1]).length);
  }
  
  return Math.max(...answer);
};