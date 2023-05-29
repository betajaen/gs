#include <gs/common/configuration.hpp>
#include <gs/util/string.hpp>



int __nocommandline = 1;
extern char* __commandline;
extern struct WBStartup* _WBenchMsg;

namespace gs::common {

    configuration_t g_configuration = {};

    void configuration_t::parse_from_entry() {

        start_param = 0;

        if (_WBenchMsg != nullptr) {
            // TODO - Parse from tooltypes, and maybe fill in a configuration class?
        }
        else if (__commandline != nullptr) {
            auto rv = util::string_parse_unsigned_int(__commandline);
            if (rv.has_value()) {
                start_param = rv.get<uint32_t>();
            }
        }
    }
}