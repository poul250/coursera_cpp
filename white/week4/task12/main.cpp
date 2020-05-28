#include <string>
#include <system_error>

std::string AskTimeServer();

class TimeServer {
public:
  std::string GetCurrentTime() {
    try {
      last_fetched_time = AskTimeServer();
    } catch (const std::system_error&) {
      // pass
    }

    return last_fetched_time;
  }
private:
  std::string last_fetched_time = "00:00:00";
};

