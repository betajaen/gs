#include <gs/common/configuration.hpp>
#include <gs/util/debug.hpp>
#include <gs/util/string.hpp>

int __nocommandline = 1;
extern char* __commandline;
extern struct WBStartup* _WBenchMsg;

namespace gs::common {

    configuration_t g_configuration = {};

    void configuration_t::parse_from_entry() {
        if (_WBenchMsg != nullptr) {
            start_param = 0;
            // TODO - Parse from tooltypes, and maybe fill in a configuration class?
        }
        else if (__commandline != nullptr) {
            start_param = util::string_parse_unsigned_int(__commandline);
        }
        else {
            start_param = 0;
        }
    }
}