#include <sstream>
#include <string>
#include <iostream>
using namespace std;

#define LOG(logger, message) { \
  stringstream ss; \
  if(logger.IsFileEnabled() && logger.IsFileLineEnabled()) { \
    ss << __FILE__ << ":" << __LINE__ << " "; \
  } else if (logger.IsFileLineEnabled()) { \
    ss << "Line " << __LINE__ <<  " "; \
  } else if (logger.IsFileEnabled()) { \
    ss << __FILE__ << " "; \
  } \
  ss << message << endl; \
  logger.Log(ss.str()); \
}

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file= value; }
  bool IsFileEnabled() const{return log_file;}
  bool IsFileLineEnabled() const {return log_line;}
  void Log(const string& message) {os << message;}

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};


// int main() {
//   Logger log(std::cout);
//   log.SetLogLine(false);
//   log.SetLogFile(false);
//   LOG(log, "hello world\n");
// }
