
#ifndef CommandLineParser_h
#define CommandLineParser_h

#include <algorithm>
// #include <array>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace ldbchan {
enum OptionArgType { None, One, Multi };
class Command {
public:
  Command(const char shortOpt, const std::string longOpt,
          const std::string description, OptionArgType argType,
          std::function<bool(std::vector<void *>)> func)
      : m_shortOpt(shortOpt), m_longOpt(longOpt), m_argType(argType),
        m_description(description), m_funcModule(func) {}
  // getter
  virtual ~Command() {}
  virtual char ShortOption() { return this->m_shortOpt; }
  virtual std::string LongOption() { return this->m_longOpt; }
  virtual std::string Description() { return this->m_description; }
  virtual ldbchan::OptionArgType ArgType() { return this->m_argType; }
  virtual void RunModule(vector<void *> args) { this->m_funcModule(args); }

private:
  const char m_shortOpt;
  const std::string m_longOpt;
  const ldbchan::OptionArgType m_argType;
  const std::vector<std::string> m_argValues;
  const std::string m_description;
  const std::function<bool(std::vector<void *>)> m_funcModule;
};

class CommandOptionChecker {
public:
  CommandOptionChecker(vector<Command> commands) : m_commands(commands) {}
  bool operator()(int argc, char *argv[]) {
    bool ret = true;

    std::for_each(m_commands.begin(), m_commands.end(),
                  [&ret, &argc, &argv](Command &cmd) {
                    for (int i = 0; i < argc; i++) {
                      // Long option.
                      if (argv[i][0] == '-' && argv[i][0] == argv[i][1]) {
                        printf("log \n");
                      } else if (argv[i][0] == '-') {
                        // Short Option.
                              printf("short log. \n")
                      } else {
                      }
                    }
                  });
    return true;
  }

private:
  vector<Command> m_commands;
};

} // namespace ldbchan

#endif
