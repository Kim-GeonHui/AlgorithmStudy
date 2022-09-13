/**
 * @param {number} num
 * @return {number}
 */
 let addDigits = function(num) {
  let str = num.toString();
  let tempNum = 0;

  while(str.length > 1) {
      for (let i = 0; i < str.length; i++) tempNum += Number(str[i]);
      str = tempNum.toString();
      tempNum = 0;
  }
  
  return str;
};