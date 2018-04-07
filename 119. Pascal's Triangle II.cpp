class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return vector<int> {1};
        if(rowIndex==1) return vector<int> {1,1};
        vector<int> res {1,1};
        while(rowIndex>1) {
            vector<int> temp;
            temp.push_back(1);
            for(int i=1;i<=res.size()-1;++i)
                temp.push_back(res[i-1]+res[i]);
            temp.push_back(1);
            res = temp;
            --rowIndex;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,0);
        res[0] = 1;
        for (int i = 1; i < rowIndex+1; i++)
            for (int j = i; j >= 1; j--)
                res[j] += res[j-1];
        return res;
    }
};