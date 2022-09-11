/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
 let merge = function(nums1, m, nums2, n) {
  let tempNums1 = nums1.slice(0, m);
  let tempNums2 = nums2.slice(0, n);
  
  let index1 = 0;
  let index2 = 0;
  
  for (let i = 0; i < m + n; i++) {
      if (index1 === m) {
          while(index2 !== n) {
              nums1[i] = tempNums2[index2];
              i++;
              index2++;
          }
          break;
      }
      
      if (index2 === n) {
          while(index1 !== m) {
              nums1[i] = tempNums1[index1];
              i++;
              index1++;
          }
          break;
      }
      
      if (tempNums1[index1] <= tempNums2[index2]) {
          nums1[i] = tempNums1[index1];
          index1++;
      }
      else {
          nums1[i] = tempNums2[index2];
          index2++;
      }
  }
};