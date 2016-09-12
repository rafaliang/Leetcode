//
//  40.cpp
//  Leetcode
//
//  Created by Rafa Liang on 9/10/16.
//  Copyright © 2016 Rafa Liang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        return combine(candidates,target,-1);
        
    }
    
    vector<vector<int>> combine(vector<int>& candidates, int target, int idx){
        int len=candidates.size();
        vector<int> tmp;
        vector<vector<int>> res,ans;
        for (int i=idx+1;i<len;++i)
        {
            tmp.clear();
            if (i>idx+1 && candidates[i]==candidates[i-1])
            {
                //cout << i << endl;
                continue;
            }
            
            if (candidates[i]==target)
            {
                tmp.push_back(candidates[i]);
                res.push_back(tmp);
                /*else
                 {
                 for (int j=0;j<res.size();++j)
                 (res[j]).push_back(candidates[i]);
                 }*/
                return res;
            }
            
            if (candidates[i]<target)
            {
                ans=combine(candidates,target-candidates[i],i);
                if (ans.size()==0)
                    continue;
                for (int j=0;j<ans.size();++j)
                {
                    tmp=ans[j];
                    tmp.push_back(candidates[i]);
                    res.push_back(tmp);
                }
            }
            
            if (candidates[i]>target)
                break;
        }
        return res;
    }
};
