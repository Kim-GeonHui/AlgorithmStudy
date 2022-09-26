/**
 * @param {number[]} candyType
 * @return {number}
 */
 let distributeCandies = function(candyType) {
  let n = candyType.length;
  let typeLength = [...new Set(candyType)].length;
  
  if (n / 2 > typeLength) return typeLength;
  else return n / 2;
};