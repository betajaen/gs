#include <gs/hw/start_param.hpp>
#include <gs/util/debug.hpp>
#include <gs/util/string.hpp>

int __nocommandline = 1;
extern char* __commandline;
extern struct WBStartup* _WBenchMsg;

namespace gs::hw {

    start_param_t g_start_param = {};

    void start_param_t::parse_from_entry() {
        if (_WBenchMsg != nullptr) {
            code = 0;
            // TODO - Parse from tooltypes, and maybe fill in a configuration class?
        }
        else if (__commandline != nullptr) {
            util::string_parse_unsigned_int(__commandline);
            code = 0;
            param = util::pod_variant_t();
        }
        else {
            code = 0;
            param = util::pod_variant_t();
        }
    }
}