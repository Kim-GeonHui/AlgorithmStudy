function solution(nums) {
  var answer = 0;
  var N = nums.length / 2;

  nums.sort();
  var tempArr = [];
  tempArr.push(nums[0])
  for (var i = 1; i < nums.length; i++) {
      if (nums[i - 1] == nums[i])
          continue;
      tempArr.push(nums[i]);
  }

  answer = (N >= tempArr.length) ? tempArr.length : N;

  return answer;
}