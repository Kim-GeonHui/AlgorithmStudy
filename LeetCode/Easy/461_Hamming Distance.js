/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
 let hammingDistance = function(x, y) {
  let answer = 0;
  let tempStr = "";
  
  x = x.toString(2);
  y = y.toString(2);
  
  console.log(x, y);
  
  if (x.length > y.length) {
      tempStr = x.slice(0, x.length - y.length);
      x = x.slice(x.length - y.length);
      answer += tempStr.split(1).length - 1;
      answer += x.split('').filter((item, index) => item !== y[index]).length;
  }
  else if (x.length < y.length) {
      tempStr = y.slice(0, y.length - x.length);
      y = y.slice(y.length - x.length);
      answer += tempStr.split(1).length - 1;
      answer += y.split('').filter((item, index) => item !== x[index]).length;
  }
  else {
      answer += y.split('').filter((item, index) => item !== x[index]).length;
  }

  return answer;
};