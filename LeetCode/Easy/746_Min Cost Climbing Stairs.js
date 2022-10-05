/**
 * @param {number[]} cost
 * @return {number}
 */
 let minCostClimbingStairs = function(cost) {
  let arr = new Array(cost.length);
  arr[0] = cost[0];
  arr[1] = cost[1];
  
  for (let i = 2; i < cost.length; i++)
      arr[i] = Math.min(cost[i] + arr[i - 1], cost[i] + arr[i - 2]);
  
  return Math.min(arr[arr.length - 1], arr[arr.length - 2]);
};