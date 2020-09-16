#include <bits/stdc++.h>
using namespace std;

int n;
vector<set<int> > a;

int maxEnd() {
  int result = 0;
  for (set<int>::iterator it=a.back().begin(); it!= a.back().end(); ++it)
    result = max(result, *it);
  return result;
}

void pushL(int value, int index, vector<int> &l) {
  while ((int)l.size()-1 != index) l.erase(l.end());
  l.back() = value;
}

void solve(int index, vector<int> &l) {
  for (set<int>::iterator it=a[index].begin(); it!=a[index].end(); ++it) {
    int s = 0;
    for (int i = (int)l.size()-1; i >= 0; i--) {
      if (*it <= l[i]) {
        if (s == 0) l.push_back(*it);
        else pushL(*it, i+1, l);
        break;
      }
      s += *it;
    }
  }
}

void test(vector<int> v) {
  for (int i : v)
    cout << i << ' ';
  cout << '\n';
}

int main() {
  freopen("input", "r", stdin);
  cin >> n;
  set<int> sTemp;
  for (int i = 1; i <= n; i++) {
    int s; cin >> s;
    while (s--) {
      int c; cin >> c;
      sTemp.insert(c);
    }
    a.push_back(sTemp);
    sTemp.clear();
  }

  vector<int> l;
  l.push_back(maxEnd());
  for (int i = n-2; i >= 0; i--) {
    solve(i, l); 
  }

  int result = 0;
  for (int i : l)
    result += i;
  cout << result;

  return 0;
}