#include "common.h"
#include <CommandLineParser.hpp>
#include <leveldb/db.h>

using namespace std;
using namespace ldbchan;

std::vector<ldbchan::Command> commands;

void initCommands(){
  // File path of ldb
  commands.push_back(ldbchan::Command("-", "path", "description", OptionArgType::None, nullptr));
  commands.push_back(ldbchan::Command("c", "test", "description", OptionArgType::None, nullptr));
  commands.push_back(ldbchan::Command("c", "test", "description", OptionArgType::None, nullptr));

  // Command Line mdoe
}

int main(int argc, char* argv[]) {
  ldbchan::CommandOptionChecker test(commands);
  bool ret = test(argc, argv);
  std::cout << "ret : " << ret << "\n";
  
  return 0;
}
