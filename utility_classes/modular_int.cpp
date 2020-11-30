#include <bits/stdc++.h>

using namespace std;

template <int MOD=998'244'353>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(int64_t v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(int64_t a, int64_t b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (int64_t)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, int64_t e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};


const int MOD = 1e9 + 7; 
using Mint = Modular<MOD>;

int main () {
    Mint res = 1;
    int a = 5;
    int b = 50;
    // finds pow(a, b) % MOD;

    for(int i = 1; i <= b; ++i){
        res = res * a;
    }
    cout << endl << "pow(" << a << ", " << b << ") = " << res << endl;
}
