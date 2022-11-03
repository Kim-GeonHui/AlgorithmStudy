/**
 * @param {number[]} aliceSizes
 * @param {number[]} bobSizes
 * @return {number[]}
 */
 let fairCandySwap = function(aliceSizes, bobSizes) {
  let answer = [0, 0];
  
  let totalCandy = [0, 0];
  totalCandy[0] = aliceSizes.reduce((a,b) => (a+b));
  totalCandy[1] = bobSizes.reduce((a,b) => (a+b));
  let difference = (Math.abs(totalCandy[0] - totalCandy[1])) / 2;
  
  if (totalCandy[0] < totalCandy[1]) {
      for (let i = 0; i < aliceSizes.length; i++) {
          if (bobSizes.indexOf(aliceSizes[i] + difference) !== -1) {
              answer[0] = aliceSizes[i];
              answer[1] = aliceSizes[i] + difference;
              break;
          }
      }
  }
  else {
      for (let i = 0; i < bobSizes.length; i++) {
          if (aliceSizes.indexOf(bobSizes[i] + difference) !== -1) {
              answer[0] = bobSizes[i] + difference;
              answer[1] = bobSizes[i];
              break;
          }
      }
  }
  
  return answer;
};