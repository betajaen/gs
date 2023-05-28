#pragma once

#include <exec/types.h>

extern "C" void gs_debug_str(CONST_STRPTR str);

extern "C" void gs_debug_fmt(CONST_STRPTR fmt, ...);
#define ___GS_DEBUG_STR(X) #X
#define __GS_DEBUG_STR(X) ___GS_DEBUG_STR(X)

#define TRACE gs_debug_str("TRC " __FILE__ "(" __GS_DEBUG_STR(__LINE__) ")" )

#define DEBUG_STR(STR) gs_debug_str("DBG " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " STR)
#define DEBUG_FMT(FMT, ...) gs_debug_fmt("DBG " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " FMT, __VA_ARGS__)

#define INFO_STR(STR) gs_debug_str("INF " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " STR)
#define INFO_FMT(FMT, ...) gs_debug_fmt("INF " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " FMT, __VA_ARGS__)

#define WARN_STR(STR) gs_debug_str("WRN " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " STR)
#define WARN_FMT(FMT, ...) gs_debug_fmt("WRN " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " FMT, __VA_ARGS__)

#define ERROR_STR(STR) gs_debug_str("ERR " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " STR)
#define ERROR_FMT(FMT, ...) gs_debug_fmt("ERR " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " FMT, __VA_ARGS__)