#pragma once

#include <exec/types.h>

extern "C" void gs_debug_str(CONST_STRPTR str);

extern "C" void gs_debug_fmt(CONST_STRPTR fmt, ...);

#define ___GS_DEBUG_STR(X) #X
#define __GS_DEBUG_STR(X) ___GS_DEBUG_STR(X)

#if defined(gs_debug_min_debug_level) && gs_debug_min_debug_level >= 0
#define TRACE gs_debug_str("TRC " __FILE__ "(" __GS_DEBUG_STR(__LINE__) ")" )
#define CAN_TRACE 1
#else
#define TRACE
#define CAN_TRACE 0
#endif

#if defined(gs_debug_min_debug_level) && gs_debug_min_debug_level >= 1
#define DEBUG_STR(STR) gs_debug_str("DBG " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " STR)
#define DEBUG_FMT(FMT, ...) gs_debug_fmt("DBG " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " FMT, __VA_ARGS__)
#define CAN_DEBUG 1
#else
#define DEBUG_STR(STR)
#define DEBUG_FMT(FMT, ...)
#define CAN_DEBUG 0
#endif

#if defined(gs_debug_min_debug_level) && gs_debug_min_debug_level >= 2
#define INFO_STR(STR) gs_debug_str("INF " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " STR)
#define INFO_FMT(FMT, ...) gs_debug_fmt("INF " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " FMT, __VA_ARGS__)
#define CAN_INFO 1
#else
#define INFO_STR(STR)
#define INFO_FMT(FMT, ...)
#define CAN_INFO 0
#endif

#if defined(gs_debug_min_debug_level) && gs_debug_min_debug_level >= 3
#define WARN_STR(STR) gs_debug_str("WRN " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " STR)
#define WARN_FMT(FMT, ...) gs_debug_fmt("WRN " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " FMT, __VA_ARGS__)
#define CAN_WARN 1
#else
#define WARN_STR(STR)
#define WARN_FMT(FMT, ...)
#define CAN_WARN 0
#endif

#if defined(gs_debug_min_debug_level) && gs_debug_min_debug_level >= 4
#define ERROR_STR(STR) gs_debug_str("ERR " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " STR)
#define ERROR_FMT(FMT, ...) gs_debug_fmt("ERR " __FILE__ "(" __GS_DEBUG_STR(__LINE__) "): " FMT, __VA_ARGS__)
#define CAN_ERROR 1
#else
#define ERROR_STR(STR)
#define ERROR_FMT(FMT, ...)
#define CAN_ERROR 0
#endif