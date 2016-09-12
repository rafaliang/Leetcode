#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <float.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double tmp;
        if (n<0)
            tmp=1.0/power(x,-n);
        tmp=power(x,n);
        return tmp;
    }
    
    double power(double x, int n) {
        double tmp;
        if (n==0)
            return 1;
        if (n==1)
            return x;
        tmp=power(x,n/2);
        if (n%2==0)
            return tmp*tmp;
        return tmp*tmp*x;

    }
    
};