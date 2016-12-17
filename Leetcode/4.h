#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <float.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        if ((len1+len2)%2==1)
            return findKSmallest(nums1,nums2,(len1+len2-1)/2);
        return (findKSmallest(nums1,nums2,(len1+len2)/2-1)+findKSmallest(nums1,nums2,0))/2.0;
        
        
    }
    
    double findKSmallest(vector<int>& nums1, vector<int>& nums2, int idx){
        int idx1,idx2;
        double res;
        if (nums1.size()==0)
        {
            res=double(nums2[idx]);
            nums2.erase(nums2.begin(),nums2.begin()+idx+1);
            return res;
        }
        if (nums2.size()==0)
        {
            res=double(nums1[idx]);
            nums1.erase(nums1.begin(),nums1.begin()+idx+1);
            return res;
        }
        if (idx==0)
        {
            //res=double(nums1[0]<nums2[0]?nums1[0]:nums2[0]);
            if (nums1[0]<nums2[0])
            {
                res=nums1[0];
                nums1.erase(nums1.begin());
            }
            else
            {
                res=nums2[0];
                nums2.erase(nums2.begin());
            }
            return res;
        }
        if (idx%2==0)
        {
            idx1=idx/2-1;
            idx2=idx/2;
        }
        else
        {
            idx1=idx/2;
            idx2=idx/2;
        }
        if (idx1>=nums1.size())
            idx1=nums1.size()-1;
        if (idx2>=nums2.size())
            idx2=nums2.size()-1;
        if (nums1[idx1]<nums2[idx2])
        {
            nums1.erase(nums1.begin(),nums1.begin()+idx1+1);
            return findKSmallest(nums1,nums2,idx-idx1-1);
        }
        else if (nums2[idx2]<nums1[idx1])
        {
            nums2.erase(nums2.begin(),nums2.begin()+idx2+1);
            return findKSmallest(nums1,nums2,idx-idx2-1);
        }
        else
        {
            if (idx1+idx2<idx-1)
            {
                nums1.erase(nums1.begin(),nums1.begin()+idx1+1);
                nums2.erase(nums2.begin(),nums2.begin()+idx2+1);
                return findKSmallest(nums1,nums2,idx-idx1-idx2-2);
            }
            res=double(nums2[idx2]);
            nums1.erase(nums1.begin(),nums1.begin()+idx1+1);
            nums2.erase(nums2.begin(),nums2.begin()+idx2+1);
            return res;
        }
        
    }
};