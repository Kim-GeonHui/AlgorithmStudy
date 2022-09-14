/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
 let intersection = function(nums1, nums2) {
  let answer = nums1.filter(item => nums2.includes(item));
  return [...new Set(answer)];
};