function solution(sizes) {
  var answer = 0;
  
  var w = 0;
  var h = 0;
  
  for (var i = 0; i<sizes.length; i++) {
      w = (sizes[i][0] > w) ? sizes[i][0] : w;
      h = (sizes[i][1] > h) ? sizes[i][1] : h;
  }
  
  if (w > h) {
      h = 0;
      for (var i = 0; i < sizes.length; i++) {
          if (sizes[i][0] > sizes[i][1])
              h = (h < sizes[i][1]) ? sizes[i][1] : h;
          else
              h = (h < sizes[i][0]) ? sizes[i][0] : h;
      }
  }
  else {
      w = 0;
      for (var i = 0; i < sizes.length; i++) {
          if (sizes[i][0] < sizes[i][1])
              w = (w < sizes[i][0]) ? sizes[i][0] : w;
          else
              w = (w < sizes[i][1]) ? sizes[i][1] : w;
      }
  }
  
  answer = w * h;
  
  return answer;
}