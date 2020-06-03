
#include <bits/stdc++.h>

using namespace std;

void to_bin(int n){
    cout << n << "\t=\t";
    for(int i = 31; i >= 0; --i){
        if((n >> i) & 1){
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;
}
