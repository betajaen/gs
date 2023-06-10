#include <gs/common/configuration.hpp>
#include <gs/util/string.hpp>

int __nocommandline = 1;
extern char* __commandline;
extern struct WBStartup* _WBenchMsg;

namespace gs::common {

    Configuration Configuration::s_Instance;

    void Configuration::ParseFromEntry() {

        m_StartParam = 0;

        if (_WBenchMsg != nullptr) {
            // TODO - Parse from tooltypes, and maybe fill in a configuration class?
        }
        else if (__commandline != nullptr) {
            uint32_t value;
            if (util::CStringTryParseUInt32(__commandline, value)) {
                m_StartParam = value;
            }
        }
    }
}