#include "common.h"
#include <CommandLineParser.hpp>
#include <leveldb/db.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

using namespace std;

std::vector<ldbchan::Option> commands;
std::map<std::string, ldbchan::Command> map_cmds;
ldbchan::Command* cmd_selected;

void initCommands() {

	map_cmds.insert(std::make_pair("console", ldbchan::Command("test", "description", {
					ldbchan::Option('p', "path", "run chan ldb with console mode.", ldbchan::ArgOne)
				})));


	map_cmds.insert(std::make_pair("export", ldbchan::Command("test", "description", {
					ldbchan::Option('t', "type", "type (sql, xlsx, text)", ldbchan::ArgNone),
					ldbchan::Option('p', "path", "file or directory", ldbchan::ArgOne),
					ldbchan::Option('o', "output", "output file path", ldbchan::ArgOne)
				})));


	map_cmds.insert(std::make_pair("import", ldbchan::Command("test", "description", {
					ldbchan::Option('t', "test", "description", ldbchan::ArgOne),
					ldbchan::Option('t', "test", "description", ldbchan::ArgOne),
					ldbchan::Option('t', "test", "description", ldbchan::ArgOne)
				})));
}


int main(int argc, char *argv[]) {

	initCommands();
	
	return 0;
}

