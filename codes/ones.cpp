#include <iostream>

#define ll long long

const ll p = 1E9 + 7;

ll powmod(ll a, ll b) {
  a %= p;
  if (!a)
    return 0;
  ll product = 1;
  while (b > 0) {
    if (b & 1) {
      product = (product * a) % p;
      b--;
    }
    a = (a * a) % p;
    b >>= 1;
  }
  return product;
}

ll factmod(ll n) {
  if (n >= p)
    return 0;

  ll factorial = 1;
  for (ll i = 1; i <= n; i++)
    factorial = (factorial * i) % p;
  return factorial % p;
}

ll inv(ll a) { return powmod(a, p - 2); }

ll Cnk(ll n, ll k) {
  return (factmod(n) * inv(factmod(k)) % p) * inv(factmod(n - k)) % p;
}

int main() { std::cout << Cnk(20, 10); }
