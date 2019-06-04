
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


	
	enum OptionArgType { ArgNone, ArgOne, ArgMulti };
	
	class Option {
	public:
		Option(const char shortOpt,
					 const std::string longOpt,
					 const std::string description,
					 OptionArgType argType)
			
			: m_shortOpt(shortOpt),
				m_longOpt(longOpt),
				m_argType(argType),
				m_description(description) {}
		
		// getter
		virtual ~Option() {}
		virtual char ShortOption() { return this->m_shortOpt; }
		virtual std::string LongOption() { return this->m_longOpt; }
		virtual std::string Description() { return this->m_description; }
		virtual ldbchan::OptionArgType ArgType() { return this->m_argType; }
		
	private:
		const char m_shortOpt;
		const std::string m_longOpt;
		const ldbchan::OptionArgType m_argType;
		const std::vector<std::string> m_argValues;
		const std::string m_description;
	};

	class Command {
	public:
		Command(const string name,
						const string description,
						const std::vector<ldbchan::Option> options) : m_name(name), m_description(description) {
			
			for_each(options.begin(), options.end(),
							 [this](Option opt) {
								 this->m_mapLongOpt.insert(std::make_pair(opt.LongOption(), opt));
								 this->m_mapShortOpt.insert(std::make_pair(opt.ShortOption(), opt));
							 });
		}

		bool ParseArgs(int argc, char* argv[]) {
			bool ret = true;
			
			return ret;
		}

		bool IsContain(string longOpt) {
			bool ret = true;
			m_mapLongOpt.find(longOpt);
			
			return ret;
		}

		bool IsContain(char shortOpt) {
			bool ret = true;
			m_mapShortOpt.find(shortOpt);
			
			return ret;
		}
		
	private:
		std::string m_name;
		std::map<string, Option> m_mapLongOpt;
		std::map<char, Option> m_mapShortOpt;
		std::string m_description;
	};
	
	class CommandOptionMap {
	public:
		CommandOptionMap(vector<Option> commands) {
			for_each(commands.begin(), commands.end(),
							 [](Option opt) {
								 // cmd.LongOption()
							 });
			// std::for_each(commands.begin(), commands.end(),
			// [&ret, &argc, &argv](Command &cmd) {
			// for (int i = 0; i < argc; i++) {
			// Long option.
			// if (argv[i][0] == '-' && argv[i][0] == argv[i][1]) {
			// printf("log \n");
			// } else if (argv[i][0] == '-') {
			// Short Option.
			// printf("short log. \n");
			// } else {
			// printf("else");
			// }
			// }
			// });
		}
		bool operator()(int argc, char *argv[]) {
			bool ret = true;
			// [&ret, &argc, &argv](Option &cmd) {
			// for (int i = 0; i < argc; i++) {
			// Long option.
			// if (argv[i][0] == '-' && argv[i][0] == argv[i][1]) {
			// printf("log \n");
			// } else if (argv[i][0] == '-') {
			// Short Option.
			// printf("short log. \n");
			// } else {
			// printf("else");
			// }
			// }
			// });
			return ret;
		}

		bool IsContain(Option cmd) {
			bool ret;
			
			return ret;
		}

		vector<string> GetArgs(Option cmd) {
			vector<std::string> ret;
			return ret;
		}

		
	private:
		map<std::string, Option> m_mapCmd;
	};
} // namespace ldbchan

#endif
