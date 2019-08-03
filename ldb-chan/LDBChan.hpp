#ifndef  LDBChan_hpp
#define  LDBChan_hpp

#include "common.h"
#include <CommandLineParser.hpp>
#include <boost/atomic.hpp>
#include <PrintModule.hpp>
#include <ExportModule.hpp>
#include <ConsoleModule.hpp>

using namespace std;

constexpr char cmdConsole[] = "console";
constexpr char cmdExport[] = "export";
constexpr char cmdPrint[] = "print";

namespace  ldbchan {
	class LDBChan {
	public:
		LDBChan() {
			std::cout << "LDBChan ctor" << "\n";
			initCommands();
		}

		virtual ~LDBChan(){
			std::cout << "LDBChan dtor" << "\n";
		}

		virtual void Run(int argc, char** argv) {
			int ret = 0;
			std::cout << "LDBChan run project." << "\n";
			if (parseArgument(argc, argv) == false) {
				exit(EXIT_FAILURE);
			}

			string tgtCmd = this->m_cmdChoosen->GetCommand();

			if (tgtCmd.compare(cmdConsole) == 0) {
				ret = ConsoleModuleRun(m_cmdChoosen);
				
			} else if (tgtCmd.compare(cmdExport) == 0) {
				ret = ExportModuleRun(m_cmdChoosen);
				
			} else if (tgtCmd.compare(cmdPrint) == 0){
				ret = PrintModuleRun(m_cmdChoosen);
				
			} else {
				
			}
		}
		
	protected:
		void initCommands() {
			// Initialize commands.
			m_mapCmds.insert(std::make_pair(cmdConsole, ldbchan::Command(cmdConsole, "description", {
							ldbchan::Option('p', "path", "run chan ldb with console mode.", ldbchan::ArgOne)
						})));
	
			m_mapCmds.insert(std::make_pair(cmdExport, ldbchan::Command(cmdExport, "description", {
							ldbchan::Option('t', "type", "type (sql, xlsx, text)", ldbchan::ArgNone),
							ldbchan::Option('p', "path", "file or directory", ldbchan::ArgOne),
							ldbchan::Option('o', "output", "output file path", ldbchan::ArgOne),
						})));
	
			m_mapCmds.insert(std::make_pair(cmdPrint, ldbchan::Command(cmdPrint, "description", {
							ldbchan::Option('p', "path", "description", ldbchan::ArgOne),
							ldbchan::Option('t', "test", "description", ldbchan::ArgOne),
							ldbchan::Option('t', "test", "description", ldbchan::ArgOne),
						})));

			
			// Initialize common options.
			m_mapCommOptions.insert(
				make_pair("foreground", ldbchan::Option('f', "foreground", "description", ldbchan::ArgNone))
				);
		}


		bool parseArgument(int argc, char** argv) {
			
			if (argc <= 1) {
				fprintf(stderr, "Couldnt found the command.\n");
				for (auto it = m_mapCmds.begin(); it != m_mapCmds.end(); ++it) {
					cout << " -- " << it->first << "\n";
				}				
				return false;
			}

			// Getting the inputted command.
			if (m_mapCmds.find(argv[1]) != m_mapCmds.end()) {
				m_cmdChoosen = &(m_mapCmds.find(argv[1])->second);
			
				if (m_cmdChoosen->ParseArgs(argc, argv) == false) {
					fprintf(stderr, "Couldnt parse arguments.\n");
					for (auto it = m_mapCmds.begin(); it != m_mapCmds.end(); ++it) {
						cout << " -- " << it->first << "\n";
					}				
					return false;
				}
			} else {
				fprintf(stderr, "Couldnt found the command (%s).\n", argv[1]);
				exit(EXIT_FAILURE);
				return false;
			}
			
			printf("found the command(%s)\n", argv[1]);
			
			return true;
		}		
		
	private:
		std::map<std::string, ldbchan::Command> m_mapCmds;
		ldbchan::Command *m_cmdChoosen;
		map<string, ldbchan::Option> m_mapCommOptions;
	};
} // namespace ldbchan
		
#endif
