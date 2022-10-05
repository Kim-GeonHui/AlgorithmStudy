/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
 let nextGreatestLetter = function(letters, target) {
  let arr = letters.filter(item => item > target);
  
  if (arr.length === 0) return letters[0];
  else return arr[0];
};