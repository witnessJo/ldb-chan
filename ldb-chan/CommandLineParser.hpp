#ifndef CommandLineParser_hpp
#define CommandLineParser_hpp

#include <algorithm>
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
		Option(const char shortOpt, const std::string longOpt,
					 const std::string description, OptionArgType argType)
		
			: m_shortOpt(shortOpt), m_longOpt(longOpt), m_argType(argType),
				m_description(description) {}

		virtual ~Option() {}
		
		// getters
		virtual char ShortOption() { return this->m_shortOpt; }
		virtual std::string LongOption() { return this->m_longOpt; }
		virtual std::string Description() { return this->m_description; }
		virtual ldbchan::OptionArgType ArgType() { return this->m_argType; }
		virtual void PushArg(string arg) { this->m_argValues.push_back(arg); }
		virtual void PrintStatus() {
			printf("**long option : %s\n", this->m_longOpt.c_str());
			printf("**short : %c\n", this->m_shortOpt);
			for_each(m_argValues.begin(), m_argValues.end(),
							 [](string arg) { cout << arg << "\n"; });
		}

	private:
		const char m_shortOpt;
		const std::string m_longOpt;
		const ldbchan::OptionArgType m_argType;
		std::vector<std::string> m_argValues;
		const std::string m_description;
	};

	class Command {
	public:
		Command(const string name, const string description,
						const std::vector<ldbchan::Option> options)
      : m_name(name), m_description(description) {

			for_each(options.begin(), options.end(),
							 [this](Option opt) {
								 this->m_vecOptions.push_back(opt);
								 Option &elemLast = this->m_vecOptions.back();
								 this->m_mapLongOpt.insert(std::make_pair<string, Option *>(opt.LongOption(), &elemLast));
								 this->m_mapShortOpt.insert(std::make_pair<char, Option *>(opt.ShortOption(), &elemLast));
							 });
		}

		bool ParseArgs(int argc, char *argv[]) {
			for (int i = 2; i < argc; i++) {
				// Long Option
				string option;
				Option *targetOpt = nullptr;

				if (argv[i][0] == '-' &&
						argv[i][1] == '-') {
				
					option = argv[i] += 2;
					if (m_mapLongOpt.find(option) != m_mapLongOpt.end()) {
						fprintf(stderr, "Couldn't find the invalid option...\n");
						return false;
					}

					targetOpt = m_mapLongOpt.find(option)->second;

				} else if (argv[i][0] == '-') {
					if (m_mapShortOpt.find(argv[i][1]) != m_mapShortOpt.end()) {
						fprintf(stderr, "Couldn't find the invalid option...\n");
						return false;
					}

					targetOpt = m_mapShortOpt.find(argv[i][1])->second;
				} else {
					if (targetOpt != nullptr)
						targetOpt->PushArg(argv[i]);
				}
			}

			return true;
		}

		void PrintStatus() {
			printf("Command (%s)\n", m_name.c_str());
			for_each(m_vecOptions.begin(), m_vecOptions.end(),
							 [](Option opt) { opt.PrintStatus(); });
		}

		bool IsContain(string longOpt) {
			if (m_mapLongOpt.find(longOpt) == m_mapLongOpt.end()) {
				return false;
			}
			return true;
		}

		bool IsContain(char shortOpt) {
			if (m_mapShortOpt.find(shortOpt) == m_mapShortOpt.end()) {
				return false;
			}
			return true;
		}

		bool PrintDescription() {
			for (auto it = this->m_vecOptions.begin(); it != this->m_vecOptions.end();
					 ++it) {
				it->Description();
			}
			return true;
		}

		std::string GetCommand(){
			return this->m_name;
		}

	private:
		std::string m_name;
		std::vector<Option> m_vecOptions;
		std::map<string, Option *> m_mapLongOpt;
		std::map<char, Option *> m_mapShortOpt;
		std::string m_description;
	};

	class CommandOptionMap {
	public:
		CommandOptionMap(vector<Option> commands) {
			for_each(commands.begin(), commands.end(),
							 [](Option opt) {
								 opt.Description();
							 });
		}
		
		bool operator()(int argc, char *argv[]) {
			bool ret = true;
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
