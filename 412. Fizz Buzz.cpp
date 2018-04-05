//这道题目看起来很简单
//遍历1-n 如果当前的数对于3取余为0就输出Fizz 如果对于5取余为0就输出Buzz
//都为0则FizzBuzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for(int i=1;i<=n;i++) {
        	if(i%3!=0&&i%5!=0)
        		v.push_back(to_string(i));//注意函数的名称
        	else if(i%3==0&&i%5!=0)
        		v.push_back("Fizz");
        	else if(i%5==0&&i%3!=0)
        		v.push_back("Buzz");
        	else
        		v.push_back("FizzBuzz");
        }
        return v;
    }
};



class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> result (n);

        for (int i = 1 ; i <= n ; i++)
        {
            string value;
            bool print_number = true;

            if ( (i % 3) == 0)
            {
                print_number = false;
                value.append("Fizz");
            }
            if ( (i % 5) == 0)
            {
                print_number = false;
                value.append("Buzz");
            }
            if (print_number)
            {
                value = to_string(i);
            }

            result[i-1] = value;
        }

        return result;
    }
};