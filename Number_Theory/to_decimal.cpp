
#include <bits/stdc++.h>

using namespace std;

int to_decimal(string s){
    /*
     * returns the integer value of a binary string
     */
    int n = 0;
    int len = s.size();
    for(int i = len - 1; i >= 0; --i){
        if(s[i] == '1')
            n += pow(2, len - i - 1);
    }
    return n;
}
