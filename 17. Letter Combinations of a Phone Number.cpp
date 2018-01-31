/*
分析：根据输入的数字得到所有可能的字符信息
 */
  class Solution
  {
  public:
      vector<string> letterCombinations(string digits) // 迭代
      {
          if(digits.size()==0)
          	return vector<string>();
          //这里必须给这个vector初始化
          string d[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, s="";
          vector<string> v({""});
        for(int i = 0; i < digits.size(); ++ i)
         {
            vector<string> temp;
             for(int j = 0; j < v.size(); ++ j)
                 for(int k = 0; k < d[digits[i] - '0'].size(); ++ k)
                     temp.push_back(v[j] + d[digits[i] - '0'][k]);
             v = temp;
         }
         return v;
     }
 };