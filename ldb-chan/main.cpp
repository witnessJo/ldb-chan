#include "common.h"
#include <LDBChan.hpp>
#include <CommandLineParser.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

using namespace std;

ldbchan::Command* cmd_choosen = nullptr;


int main(int argc, char *argv[]) {
	printf("*************\n");
	printf("LDBChan\n");
	printf("*************\n");
	
	ldbchan::LDBChan* ldbchan = new ldbchan::LDBChan();
	ldbchan->Run(argc, argv);
	
	return 0;
}
