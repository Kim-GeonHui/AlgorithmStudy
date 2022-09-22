/**
 * @param {string} word
 * @return {boolean}
 */
 let detectCapitalUse = function(word) {
  let upperWord = word.toUpperCase();
  let lowerWord = word.toLowerCase();
  let sliceLowerWord = word.slice(1).toLowerCase();
  
  if (upperWord === word) return true;
  else if (lowerWord === word) return true;
  else if (word[0] === word[0].toUpperCase() && sliceLowerWord === word.slice(1)) return true;
  else return false;
};