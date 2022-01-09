#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& str);

void TestPositiveCases()
{
  AssertEqual(true, IsPalindrom("madam"), "madam is ok");
  AssertEqual(true, IsPalindrom("level"), "level is ok");
  AssertEqual(true, IsPalindrom("wasitacaroracatisaw"), "wasitacaroracatisaw is ok");
  AssertEqual(true, IsPalindrom(""), "empty is ok");
  AssertEqual(true, IsPalindrom("v"), "v is ok");
  AssertEqual(true, IsPalindrom(" v ")," v is ok");
}

void TestNegativeCases()
{
  AssertEqual(false, IsPalindrom("Madam"), "Madam is ok");
  AssertEqual(false, IsPalindrom(" level"), " level is ok");
  AssertEqual(false, IsPalindrom("wasitacaroracatisal"), "wasitacaroracatisal is ok");
  AssertEqual(false, IsPalindrom("wasitacaroracatisaw "), "wasitacaroracatisaw  is ok");
  Assert(IsPalindrom(""), "empty string is a palindrome");
  Assert(IsPalindrom("a"), "one letter string is a palindrome");
  Assert(IsPalindrom("abba"), "abba is a palindrome");
  Assert(IsPalindrom("abXba"), "abXba is a palindrome");
  Assert(IsPalindrom("a b X b a"), "`a b X b a` is a palindrome");
  Assert(IsPalindrom("  ABBA  "), "`  ABBA  ` is a palindrome");

  Assert(!IsPalindrom("XabbaY"), "XabbaY is not a palindrome");
  Assert(!IsPalindrom("abXYba"), "abXYba is not a palindrome");
  Assert(!IsPalindrom("Xabba"), "Xabba is not a palindrome");
  Assert(!IsPalindrom("abbaX"), "abbaX is not a palindrome");
  Assert(
    !IsPalindrom("was it a car or a cat i saw"),
    "`was it a car or a cat i saw` is not a palindrome because spaces do not match"
  );
  Assert(!IsPalindrom("ABBA   "), "`ABBA   ` is not a palindrome");
  Assert(!IsPalindrom("  ABBA"), "`  ABBA` is not a palindrome");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestPositiveCases, "TestPositiveCases");
  runner.RunTest(TestNegativeCases, "TestNegativeCases");
  return 0;
}
