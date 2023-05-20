#include <gs/util/pod.hpp>

#include <proto/dos.h>

namespace gs::util {

    void do_assert(const char* comment) {

        size_t length = 0;
        if (comment != nullptr) {
            const char* it = comment;
            while(*it != '\0') {
                it++;
            }
            length = it - comment;
        }

        Write(Output(), (void*) comment, length);
        Flush(Output());
        Exit(RETURN_ERROR);
    }

}