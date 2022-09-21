/**
 * @param {string[]} words
 * @return {string[]}
 */
 let findWords = function(words) {
  let arr = ["qwertyuiop", "asdfghjkl", "zxcvbnm"];
  let tempWords = [];
  let index;
  let isTrue;
  let answer = [];
  
  for (let i = 0; i < words.length; i++) {
      tempWords.push(words[i].toLowerCase());
      for (let j = 0; j < 3; j++) {
          if (arr[j].indexOf(tempWords[i][0]) !== -1) {
              index = j;
              break;
          }
      }
      
      isTrue = true;
      for (let j = 1; j < tempWords[i].length; j++) {
          if (arr[index].indexOf(tempWords[i][j]) === -1) {
              isTrue = false;
              break;
          }
      }
      
      if (isTrue) answer.push(words[i]);
  }
  
  return answer;
};