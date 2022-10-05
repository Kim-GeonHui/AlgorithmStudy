/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */

 let isPrime = function(num) {
  if (num < 2) return 0; 
  for (let i = 2; i <= Math.floor(Math.sqrt(num)); i++) {
      if (num % i === 0) return 0;
  }
  return 1;
}

let countPrimeSetBits = function(left, right) {
  let answer = 0;
  let str = "";
  
  for (let i = left; i <= right; i++) {
      str = i.toString(2);
      answer += isPrime(str.split('1').length - 1);
  }
  
  return answer;
};