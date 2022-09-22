/**
 * @param {number} n
 * @return {number}
 */
 let fib = function(n) {
  let arr = new Array(n + 1);
  arr[0] = 0;
  if (n >= 1) arr[1] = 1;
  for (let i = 2; i <= n; i++) arr[i] = arr[i - 1] + arr[i - 2];
  
  return arr[n];
};