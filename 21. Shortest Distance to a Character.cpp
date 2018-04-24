class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        if(!S.size()) return vector<int>();
        int n = S.size(),first = -1;
        vector<int> res(n,-1);

        for(int i=0;i<n;++i) {
            if(S[i]==C) {
                first = i;
                res[i] = 0;
            }
            else {
                if(first!=-1) {
                    int l = abs(i - first),r = INT_MAX;
                    for(int j=i+1;j<n;++j) {
                        if(S[j]==C) {
                            r = j - i;
                            break;
                        }
                    }
                    res[i] = r < l ? r : l;
                }
                else {
                    int r = 0;
                    for(int j=i+1;j<n;++j) {
                        if(S[j]==C) {
                            r = j - i;
                            break;
                        }
                    }
                    first = r;
                    res[i] = abs(first - i);
                }
            }
        }
        return res;
    }
};