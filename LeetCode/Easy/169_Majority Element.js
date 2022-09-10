/**
 * @param {number} columnNumber
 * @return {string}
 */
 let convertToTitle = function(columnNumber) {
  let result = "";
  
  while(columnNumber !== 0) {
      result += String.fromCharCode(65 + ((columnNumber - 1) % 26));
      columnNumber = Math.floor((columnNumber - 1) / 26);
  }
  
  return result.split('').reverse().join('');
};