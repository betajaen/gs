#include <gs/util/pod.hpp>

#include <proto/exec.h>
#include <proto/dos.h>

namespace gs::util {

    void do_assert(const char* comment) {

        if (DOSBase != nullptr) {
            size_t length = 0;
            if (comment != nullptr) {
                const char* it = comment;
                while (*it != '\0') {
                    it++;
                }
                length = it - comment;
            }

            if (length) {
                Write(Output(), (void*)comment, length);
                Flush(Output());
            }

            // Exit(RETURN_FAIL);
        }
        else {
            Alert(0x1234'5678);
        }

    }

}