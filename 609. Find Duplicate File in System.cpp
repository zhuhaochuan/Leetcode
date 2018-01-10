/*
分析 这道题目就是找到输入到额路径中相同内容的路径
输出的顺序 没有要求
输入的路径和内容都是数字和字母
相同的目录下不会出现同名的文件
输入信息当中 路径和 文件用一个空格隔开

想法：设置一map map<string,vector<string>>
遍历一遍输入的数组 将对应的相同的内容的路径加入到 同一个value的数组当中
最后再次遍历一遍map 将所有的value大于等于2的加入到输出数组当中

第一步 从输入当中得到需要的内容和路径
这道题目的我的想法没问题 采用map比较快 就是对于string的分片和分类讨论的一些问题需要注意
需要好好的总结string的一系列的操作函数的用法
substr,find,nops
 */
 

class Solution {
public:
	void subs(string& temp,string& value,unordered_map<string,vector<string>>& m) {//这个函数主要就是提取传入的temp的key和value并插入map当中
        int posl = temp.find('(');
        string val = (value + '/' + temp.substr(0,posl));
        int posr = temp.find(')');
        string key = temp.substr(posl+1,posr-posl-1);
        m[key].push_back(val);//这里不需要判断map当中有没有 因为[]操作符 如果当前map中没有就插入一个vector<string>> 这个vector是按照这个类型自己的默认构造函数初始化的也就是一个空的vector
	}

    vector<vector<string>> findDuplicate(vector<string>& paths) {
    	unordered_map<string,vector<string>> m;
    	vector<vector<string>> res;
        
        for(auto it : paths) {
    		int pos = it.find(' ');
    		string value = it.substr(0,pos);
    		string temp = it.substr(pos+1,it.size()-pos-1);

            if(temp.find(' ')==std::string::npos) {//判断当前的路径是不是只有一个文件
                subs(temp,value,m);
            }

    		while(temp.find(' ')!=std::string::npos) { //当前路径多个文件的处理
                int p = temp.find(' ');
                string temp2 = temp.substr(p+1,temp.size()-p-1); 
                subs(temp,value,m);
                temp = temp2;
                if(temp.find(' ')==std::string::npos) {//当处理到对个文件的最后一个文件的时候
                    subs(temp,value,m);
                }
    		}
        }
        
        for(auto each : m) {
        	if(each.second.size()>=2) {
        		res.push_back(each.second);
        	}
        }
        
        return res;
    }
};





class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> table;
        vector<vector<string>> res;
        vector<string> cur;

        int n = paths.size();
        for(int i = 0; i < n; i++){
            stringstream ss(paths[i]);
            string root, file;
            getline(ss, root, ' ');
            while (getline(ss, file, ' ')){
                string file_name = file.substr(0, file.find('('));
                string file_content = file.substr(file.find('(')+1, file.find(')')-file.find('(')-1);
                table[file_content].push_back(root + "/" + file_name);
            }
        }
        for(auto &i : table){
            if(i.second.size() >= 2)
                res.push_back(i.second);
        }
        return res;
    }
};