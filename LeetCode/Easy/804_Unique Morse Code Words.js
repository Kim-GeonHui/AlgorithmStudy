/**
 * @param {string[]} words
 * @return {number}
 */
 let uniqueMorseRepresentations = function(words) {
  let arr = new Array(words.length);
  arr.fill("");
  let alphabet = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
  
  for (let i = 0; i < words.length; i++) {
      for (let j = 0; j < words[i].length; j++) {
          arr[i] += alphabet[words[i][j].charCodeAt() - 97];
      }
  }
  
  arr = [...new Set(arr)];
  return arr.length;
};