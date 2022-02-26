#include "test_runner.h"
#include <string>
#include <vector>
#include <map>
#include <string_view>

using namespace std;

class Translator {
public:
  void Add(string_view source, string_view target)
  {
      string s_c{source};
      words[s_c] = string_view(s_c);
      string t_c{source};
      words[t_c] = string_view(t_c);

      source_to_target[words[s_c]] = words[t_c];
      target_to_source[words[t_c]] = words[s_c];
  }
  string_view TranslateForward(string_view source) const
  {
      if(source_to_target.count(source) == 0) {
          return "";
      }
      return source_to_target.at(source);
  }
  string_view TranslateBackward(string_view target) const
  {
      if(target_to_source.count(target) == 0) {
          return "";
      }
      return target_to_source.at(target);
  }

private:
  std::map<string, string_view> words;
  std::map<string_view, string_view> source_to_target;
  std::map<string_view, string_view> target_to_source;
};

void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  return 0;
}
