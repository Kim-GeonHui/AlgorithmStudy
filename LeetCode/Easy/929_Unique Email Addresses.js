/**
 * @param {string[]} emails
 * @return {number}
 */
 let numUniqueEmails = function(emails) {
  let answer = [];
  let tempStr = "";
  
  for (let i = 0; i < emails.length; i++) {
      tempStr = emails[i].split('@');
      tempStr[0] = tempStr[0].split('+')[0];
      tempStr[0] = tempStr[0].split('.').join('');
      tempStr = tempStr[0] + '@' + tempStr[1];
      
      if (answer.indexOf(tempStr) === -1) answer.push(tempStr);
  }
  
  return answer.length;
};