/**
 * @param {number[]} nums
 * @return {number[]}
 */
 let sortArrayByParityII = function(nums) {
  let arr1 = [];
  let arr2 = [];
  
  let answer = [];
  
  for (let i = 0; i < nums.length; i++) {
      if (nums[i] % 2 === 0) arr1.push(nums[i]);
      else arr2.push(nums[i]);
  }
  
  for (let i = 0; i < arr1.length; i++) {
      answer.push(arr1[i]);
      answer.push(arr2[i]);
  }
  
  return answer;
};