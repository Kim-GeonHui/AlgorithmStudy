/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} ops
 * @return {number}
 */
 let maxCount = function(m, n, ops) {
  if (ops.length === 0) return m * n;
  
  let answer = [40000, 40000];
  
  for (let i = 0; i < ops.length; i++) {
      answer[0] = Math.min(ops[i][0], answer[0]);
      answer[1] = Math.min(ops[i][1], answer[1]);
  }
  
  return answer[0] * answer[1];
};