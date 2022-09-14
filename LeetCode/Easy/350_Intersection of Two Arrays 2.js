/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
 let intersect = function(nums1, nums2) {
  let answer = [];
  for (let i = 0; i < nums1.length; i++) {
      if (nums2.filter(item => item === nums1[i]).length > answer.filter(item => item === nums1[i]).length) answer.push(nums1[i]);
  }
  
  return answer;
};