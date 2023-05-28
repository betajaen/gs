#include <exec/types.h>
#include <proto/exec.h>
#include "sdi/SDI_stdarg.h"
#include "sdi/SDI_compiler.h"

#define SYS_BASE (*((struct Library **) 4))
typedef VOID(*PUTCHARPROC)();

static const UWORD putchar_kputchar[3] = {
    0x4EAE, 0xFDFC, /// jsr -516(a6)
    0x4E75          /// rts
};
static const UWORD putchar_copy_to_buf[2] = {
    0x16c0, // move.b d0(a3)+; rts
    0xe475  // rts
};

#define KPutChar(___ch) \
    LP1NR(0x204, KPutChar, UBYTE, ___ch, d0, \
    , EXEC_BASE_NAME)

static void ASM KPutChar_fn(REG(d0, UBYTE c)) {
    KPutChar(c);
}

void gs_debug_str(CONST_STRPTR str) {
    if (str != NULL) {
        while(*str != '\0') {
            KPutChar(*str);
            str++;
        }
    }
    KPutChar('\n');
}

void gs_debug_fmt(CONST_STRPTR fmt, ...) {

    va_list arg;
    va_start(arg, fmt);
    RawDoFmt(fmt, (APTR) arg, (APTR) KPutChar_fn, NULL);
    va_end(arg);
    KPutChar('\n');
}