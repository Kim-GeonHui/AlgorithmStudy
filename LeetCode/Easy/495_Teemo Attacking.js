/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
 let findPoisonedDuration = function(timeSeries, duration) {
  let answer = 0;
  
  for (let i = 0; i < timeSeries.length - 1; i++) {
      if (timeSeries[i + 1] - timeSeries[i] < duration) answer += timeSeries[i + 1] - timeSeries[i];
      else answer += duration;
  } 
  answer += duration;
  
  return answer;
};