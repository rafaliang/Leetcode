#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <float.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s,p,0,0);
    }
    
    bool match(string s, string p, int idxs, int idxp)
    {
        int tmp;
        if (idxs>=s.length() || idxp>=p.length())
            return 0;
        if (idxs==s.length()-1)
        {
            if (s[idxs]==p[idxp])
                return 1;
            if (p[idxp]=='.')
                return 1;
            if (p[idxp]=='*')
            {
                tmp=idxp;
                while(p[tmp-1]=='*') tmp--;
                if (s[idxs]==p[tmp-1])
                    return 1;
                if (p[tmp-1]=='.' && s[idxs]==s[idxs-1])
                    return 1;
                return match(s,p,idxs,idxp+1);
            }
        }
        if (s[idxs]==p[idxp])
        {
            if (idxs==0)
                return match(s,p,idxs+1,idxp+1) || match(s,p,idxs,idxp+1);
            return match(s,p,idxs+1,idxp+1);
        }
        if (p[idxp]=='*')
        {
            tmp=idxp;
            while(p[tmp-1]=='*') tmp--;
            if (s[idxs]==p[tmp-1])
                return match(s,p,idxs+1,idxp+1) || match(s,p,idxs,idxp+1);
            if (p[tmp-1]=='.')
            {
                if (idxs==0)
                    return match(s,p,idxs+1,idxp+1) || match(s,p,idxs,idxp+1);
                if (s[idxs]==s[idxs-1])
                    return match(s,p,idxs+1,idxp+1) || match(s,p,idxs,idxp+1);
            }
            return match(s,p,idxs,idxp+1);;
        }
        if (p[idxp]=='.')
        {
            if (idxs==0)
                return match(s,p,idxs+1,idxp+1) || match(s,p,idxs,idxp+1);
            return match(s,p,idxs+1,idxp+1);
        }
        if (idxs==0)
        {
            return match(s,p,idxs,idxp+1);
        }
        return 0;
    }
};