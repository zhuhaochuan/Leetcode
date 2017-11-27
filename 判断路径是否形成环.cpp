/**
判断一个机器人的行走路线是否构成一个圆
也就是是否回到原点。
 */

//如果 L的个数等于R的个数 U的个数等于D的个数
//就表示这个机器人回到了原点

//19ms
class Solution {
public:
    bool judgeCircle(string moves) {
    	int tag1 = 0;
    	int tag2 = 0;
    	for(int i = 0;i<moves.size();i++) {
    		if(moves[i] == 'L') tag1++;
    		else if(moves[i] == 'R') tag1--;
    		else if(moves[i] == 'U') tag2++;
    		else if(moves[i] == 'D') tag2--;
     	}
        if(tag1||tag2) return false;
        else return true;
    }
};


//6ms
static string moves =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return "";
}();

class Solution {
public:
    bool judgeCircle(string moves) {
        
        int verticalDisplacement = 0;
        int horizontalDisplacement = 0;
        
        for(int i = 0; i < moves.size(); ++i)
        {
            switch(moves[i])
            {
                case 'U': verticalDisplacement += 1; break;
                case 'D': verticalDisplacement -= 1; break;
                case 'R': horizontalDisplacement += 1; break;
                case 'L': horizontalDisplacement -= 1; break;
            }
        }
        
        return (verticalDisplacement == 0 && horizontalDisplacement == 0);
    }
};