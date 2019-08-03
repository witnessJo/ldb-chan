#include "common.h"
#include <leveldb/db.h>
#include <LDBChan.hpp>
#include <CommandLineParser.hpp>



int CommandConsole(ldbchan::Command& cmd){
	int ret = 0;
	if (!cmd.GetCommand().compare(cmdConsole)) {
		fprintf(stderr, "The command was not matched (%s).", cmd.GetCommand().c_str());
	}
	
	return ret;
}


int CommandExport(ldbchan::Command& cmd) {
	int ret = 0;
	if (!cmd.GetCommand().compare(cmdExport)) {
		fprintf(stderr, "The command was not matched (%s).", cmd.GetCommand().c_str());
	}
	
	return ret;
}



int CommandPrint(ldbchan::Command& cmd){
	int ret = 0;
	if (!cmd.GetCommand().compare(cmdPrint)) {
		fprintf(stderr, "The command was not matched (%s).", cmd.GetCommand().c_str());
	}
	
	return ret;
}




