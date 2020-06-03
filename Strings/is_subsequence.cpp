
#include <bits/stdc++.h>

using namespace std;

bool is_subsequence(string str1, string str2) {
    int n = str2.size(), m = str1.size();
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;
    return (j == m);
}
