#pragma once

namespace gs {

    enum class return_code_t : LONG {
        Ok = 0,
        Warn = 5,
        Error = 10,
        Fail = 20
    };

}