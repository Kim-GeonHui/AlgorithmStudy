/**
 * @param {number[]} score
 * @return {string[]}
 */
 let findRelativeRanks = function(score) {
  let sortScore = [...score];
  sortScore.sort((a, b) => b - a);
  
  let answer = new Array(score.length);
  
  answer[score.indexOf(sortScore[0])] = "Gold Medal";
  answer[score.indexOf(sortScore[1])] = "Silver Medal";
  answer[score.indexOf(sortScore[2])] = "Bronze Medal";
  for (let i = 3; i < score.length; i++) {
      answer[score.indexOf(sortScore[i])] = (i + 1).toString();
  }
  
  return answer;
};