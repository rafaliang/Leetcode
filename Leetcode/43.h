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
    string multiply(string num1, string num2) {
        int len1=num1.length();
        int len2=num2.length();
        int maxsize=len1+len2;
        int tmp1,tmp2,add=0,sum;
        string res;
        if (num1=="0" || num2=="0")
            return "0";
        for (int i=0;i<=maxsize-2;++i)
        {
            sum=add;
            for (int j=0;j<len1;++j)
            {
                if (i-j>=len2)
                    continue;
                if (i-j<0)
                {
                    //add=sum/10;
                    //res+=(sum%10+'0');
                    break;
                }
                tmp1=num1[len1-1-j]-'0';
                tmp2=num2[len2-1-i+j]-'0';
                sum+=tmp1*tmp2;
            }
            res+=(sum%10+'0');
            add=sum/10;
            
        }
        if (add!=0)
            res+=(add+'0');
        reverse(res.begin(),res.end());
        return res;
        
    }
};