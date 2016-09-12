#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> tmp;
        vector<vector<int>> table;
        vector<int>  lst,lst2;
        string str1,str2;
        int hasmatch=0,idx;
        for (int i=0;i<strs.size();++i)
        {
            hasmatch=0;
            //cout << i << endl;
            str1=strs[i];
            if (res.size()==0)
            {
                tmp.push_back(str1);
                res.push_back(tmp);
                for (int j=0;j<26;++j)
                    lst.push_back(0);
                for (int j=0;j<str1.length();++j)
                    lst[str1[j]-'a']++;
                table.push_back(lst);
                continue;
            }
            for (int j=0;j<res.size();++j)
            {
                tmp=res[j];
                str2=tmp[0];
                if (str1.length()!=str2.length())
                    continue;
                hasmatch=1;
                //cout << str2 << endl;
                lst=table[j];
                for (int k=0;k<str2.length();++k)
                {
                    idx=str1[k]-'a';
                    lst[idx]--;
                    if (lst[idx]<0)
                    {
                        //break;
                        hasmatch=0;
                        continue;
                    }
                }
                //cout << str1 << endl;
                //cout << str2 << endl;
                if (hasmatch)
                {
                    //cout << strs[i] << endl;
                    //hasmatch=1;
                    //cout << i << endl;
                    (res[j]).push_back(strs[i]);
                    break;
                }
            }
            if (!hasmatch)
            {
                tmp.clear();
                tmp.push_back(strs[i]);
                res.push_back(tmp);
                lst.clear();
                for (int j=0;j<26;++j)
                    lst.push_back(0);
                for (int j=0;j<str1.length();++j)
                    lst[str1[j]-'a']++;
                table.push_back(lst);
            }
        }
        return res;
        
    }*/
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        string tmp;
        unordered_map<string,vector<string>> hashmap;
        unordered_map<string,vector<string>>::iterator it;
        for (int i=0;i<strs.size();++i)
        {
            tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            hashmap[tmp].push_back(strs[i]);
        }
        for (it=hashmap.begin();it!=hashmap.end();++it)
        {
            res.push_back(it->second);
        }
        return res;
    }
};