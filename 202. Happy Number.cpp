//我的方式 找出规律发现凡是不能得到1的都会产生循环出现89.。。。
class Solution {
public:
    bool isHappy(int n) {
        if(!n) return false;
        if(n==1) return true;
        if(n==89) return false;
        int sum = 0;
        while(n) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return isHappy(sum);
    }
};

//将出现的结果保存在map当中当再次出现的时候直接跳出判断是不是1
class Solution {
  public:
      bool isHappy(int n) {
          unordered_map<int, int> m;
          while (true) {
             int sum = 0;
              while (n) {
                  sum += (n % 10) * (n % 10);
                  n /= 10;
             }

             n = sum;
             if (m[sum]++ > 0) {

                 break;
             }
         }

         return n == 1;
     }
 };

//又是龟兔赛跑 出现循环往复 就一个快一个慢 快的追上慢的就停止
 class Solution {
public:
    int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while(slow != fast);
        if (slow == 1) return true;
        else return false;
    }
};