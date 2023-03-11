#include <set>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int res = 0;
  int count = 0;
  set<char> symbols;
  for (size_t i = 0; i < s.size(); ++i) {
    if (symbols.find(s[i]) != symbols.end()) {
      i -= (count - 1);
      if (res < count) res = count;
      count = 0;
      symbols = {};
    }
    symbols.insert(s[i]);
    ++count;
  }
  if (res < count) res = count;
  // for(auto& s: symbols)
  //     cout << s << ' ';
  return res;
}