/**
 * @param {number} x
 * @return {boolean}
 */
 var isPalindrome = function(x) {
  let tempNum = x.toString();
  let front = 0;
  let end = tempNum.length - 1;
  let result = true;
  
  if (x < 0) return false;
  
  while (end >= front) {
      if (tempNum[front] !== tempNum[end]) {
          result = false;
          break;
      }
      
      front++;
      end--;
  }
  
  return result;
};