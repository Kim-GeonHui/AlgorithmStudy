/**
 * @param {string} s
 * @return {boolean}
 */
let checkRecord = function (s) {
  if (s.split('').filter(item => item === 'A').length >= 2) return false;
  if (s.indexOf('LLL') !== -1) return false;
  return true;
};