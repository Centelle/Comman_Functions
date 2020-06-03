
#include <bits/stdc++.h>

using namespace std;

vector<int> get_factors(int n){
    /*
    * returns a sorted vector of all factors of n
    * factors include 1 and n itself
    */
    vector<int> f;
    for(int i = 1; i * i <= n; ++i){
        if(n % i == 0){
            f.push_back(i);
            if(n/i != i){
                f.push_back(n/i);
            }
        }
    }
    sort(f.begin(), f.end());
    return f;
}
