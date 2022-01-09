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

class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

  Rational();
  Rational(int numerator, int denominator) {
  }

  int Numerator() const {
  }

  int Denominator() const {
  }
};

void TestEmptyConstruct()
{
  Rational empty;
  AssertEqual(1, empty.Denominator(), "empty denominator");
  AssertEqual(0, empty.Numerator(), "empty numerator");
}

void TestDiv()
{
  Rational div(4, 6);
  AssertEqual(2, div.Numerator(), "Numerator after nod");
  AssertEqual(3, div.Denominator(), "Denominator after nod");
}

void TestNegativeCases()
{
  Rational neg1(-2, -3);
  AssertEqual(2, neg1.Numerator(), "Numerator after -");
  AssertEqual(3, neg1.Denominator(), "Denominator after -");

  Rational neg2(-2, 3);
  AssertEqual(-2, neg2.Numerator(), "Numerator after -");
  AssertEqual(3, neg2.Denominator(), "Denominator after -");

  Rational neg3(2, -3);
  AssertEqual(-2, neg3.Numerator(), "Numerator after -");
  AssertEqual(3, neg3.Denominator(), "Denominator after -");
}

void TestZeroNumerator()
{
  Rational zero(0, 1);
  AssertEqual(0, zero.Numerator(), "Numerator after 0");
  AssertEqual(1, zero.Denominator(), "Denominator after 0");

  Rational zero1(0, -150);
  AssertEqual(0, zero1.Numerator(), "Numerator after 0");
  AssertEqual(1, zero1.Denominator(), "Denominator after 0");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmptyConstruct, "TestEmptyConstruct");
  runner.RunTest(TestDiv, "TestDiv");
  runner.RunTest(TestNegativeCases, "TestNegativeCases");
  runner.RunTest(TestZeroNumerator, "TestZeroNumerator");
  // добавьте сюда свои тесты
  return 0;
}
