/*
分析：给出一个数组，和一个整数n
只能在两边不是1的位置插入花，不可连续插入
也就是说连续3个0可以插入一朵花
0 0 0 0 0 0 0 0 1
3 1
4 1
5 2
6 2
7 3
8 3
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(!n) return true;
        if(!flowerbed.size()) return false;
        if(flowerbed.size()==1&&flowerbed[0]==0) return true;
        for(int i=0;i<flowerbed.size();++i) {
            int count = 0;
            while(flowerbed[i]==0&&i<flowerbed.size()) {
                if(i==0||i==flowerbed.size()-1)
                    ++count;
                ++count;
                ++i;
            }
            if(count>2) {
                if(count%2)
                    n -= (count-1)>>1;
                else
                    n -= (count-2)>>1;
            }
        }
        return n>0?false:true;
    }
};