/**
 * @param {string} columnTitle
 * @return {number}
 */
 let titleToNumber = function(columnTitle) {
  let result = 0;
  
  for (let i = columnTitle.length - 1; 0 <= i; i--) {
      result += Math.pow(26, columnTitle.length - 1 - i) * (columnTitle[i].charCodeAt(0) - 64);
  }
  
  return result;
};