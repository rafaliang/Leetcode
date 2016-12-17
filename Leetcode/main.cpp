//
//  40.cpp
//  Leetcode
//
//  Created by Rafa Liang on 9/10/16.
//
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int listSize=wordList.size();
        int len=0,idx,i;
        int wordStSize, usedStSize;
        string tmp,tmp2;
        //vector<int> used(listSize,0),tmpused;
        vector<string> wordSt;
        //vector<vector<int>> usedSt;
        wordSt.push_back(beginWord);
        wordList.erase(beginWord);
        wordList.erase(endWord);
        //usedSt.push_back(used);
        while (!wordSt.empty())
        {
            
            wordStSize=wordSt.size();
            for (i=0;i<wordStSize;++i)
            {
                //idx=0;
                tmp=wordSt[i];
                if (compare(tmp,endWord)) return len+2;
                //used=usedSt[i];
                if (wordList.empty()) continue;
                unordered_set<string>::iterator it=wordList.begin();
                while (it!=wordList.end())
                {
                    if (compare(tmp,*it))
                    {
                        //cout << *it << endl;
                        tmp2=*it;
                        wordSt.push_back(tmp2);
                        it++;
                        //cout << tmp2 << endl;
                        //tmpused=used;
                        //tmpused[idx]=1;
                        //usedSt.push_back(tmpused);
                        wordList.erase(tmp2);
                    }
                    else it++;
                    //++idx;
                }
            }
            len++;
            wordSt.erase(wordSt.begin(),wordSt.begin()+wordStSize);
            //usedSt.erase(usedSt.begin(),usedSt.begin()+wordStSize);
        }
        return 0;
    }
    
    bool compare(string str1, string str2)
    {
        if (str1.length()!=str2.length()) return 0;
        int len=str1.length(),cnt=0;
        for (int i=0;i<len;++i)
        {
            if (str1[i]!=str2[i])
                cnt++;
            
        }
        if (cnt!=1)
            return 0;
        return 1;
    }
};

int main()
{
    Solution sol;
    string beginWord="hot";
    string endWord="dog";
    unordered_set<string> wordList;
    wordList.insert("hot");
    wordList.insert("tot");
    wordList.insert("dot");
    wordList.insert("dog");
    cout << sol.ladderLength(beginWord, endWord, wordList)<< endl;
    return 0;
}
