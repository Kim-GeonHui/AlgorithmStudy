/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
 let nextGreatestLetter = function(letters, target) {
  let arr = [];
  for (let i = 0; i < letters.length; i++) arr.push(letters[i].charCodeAt());
  target = target.charCodeAt();
  arr = arr.filter(item => item > target);
  
  if (arr.length === 0) return letters[0];
  else return String.fromCharCode(arr[0]);
};