/**
 * @param {string} sentence
 * @return {string}
 */
 let toGoatLatin = function(sentence) {
  let vowel = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
  sentence = sentence.split(' ');
  
  for (let i = 0; i < sentence.length; i++) {
      if (vowel.indexOf(sentence[i][0]) !== -1) {
          sentence[i] += "ma";
      }
      else 
          sentence[i] = sentence[i].slice(1) + sentence[i][0] + "ma";
      
      sentence[i] += "a".repeat(i + 1);
  }
  
  sentence = sentence.join(' ');
  
  return sentence;
};