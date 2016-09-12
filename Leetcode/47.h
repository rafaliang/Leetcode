//
//  42.h
//  Leetcode
//
//  Created by Rafa Liang on 9/11/16.
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        res.push_back(nums);
        while (nextPermutation(nums))
            res.push_back(nums);
        return res;
    }

    bool nextPermutation(vector<int>& nums) {
        //int lastNum;
        //int firstNum=nums[0];
        int tmp,i,j;
        //int* idx;
        for (i=nums.size()-1;i>0;--i)
        {
            if (nums[i]>nums[i-1])
            {
                for (j=nums.size()-1;j>=i;--j)
                {
                    if (nums[j]>nums[i-1])
                        break;
                }
                tmp=nums[i-1];
                nums[i-1]=nums[j];
                nums[j]=tmp;
                reverse(nums.begin()+i,nums.end());
                return 1;
            }
            
        }
        //reverse(nums.begin(),nums.end());
        return 0;
        
    }
};

