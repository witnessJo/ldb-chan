#include <ConsoleModule.hpp>


int ConsoleModuleRun(ldbchan::Command* command) {
	int ret = 0;

	if (command == nullptr) {
		fprintf(stderr, "The command was NULL.\n");
		return -1;
	}
	
	return ret;
}
