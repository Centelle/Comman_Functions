
#include <bits/stdc++.h>

using namespace std;

vector<int> get_factors(int n){
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

int main(){
    int n = 100;
    vector<int> f = get_factors(n);
    for(auto x : f){
        cout << x << ' ';
    }
    cout << endl;
}
