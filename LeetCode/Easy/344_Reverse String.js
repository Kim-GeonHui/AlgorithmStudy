/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
 let reverseString = function(s) {
  let temp;
  let front = 0;
  let end = s.length - 1;
  
  while (front < end) {
      temp = s[front];
      s[front] = s[end];
      s[end] = temp;
      front++;
      end--;
  }
};