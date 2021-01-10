// clang-format off
#define LAYOUT_metheon( \
        L11  ,L12  ,L13  ,L14  ,L15  ,R11  ,R12  ,R13  ,R14  ,R15  , \
        L21  ,L22  ,L23  ,L24  ,L25  ,R21  ,R22  ,R23  ,R24  ,R25  , \
        L31  ,L32  ,L33  ,L34  ,L35  ,R31  ,R32  ,R33  ,R34  ,R35  , \
                    L41  ,L42  ,L43  ,R41  ,R42  ,R43,               \
        E01  ,E02                                                     \
    ) \
    LAYOUT( \
        KC_NO,L11  ,L12  ,L13  ,L14  ,L15                          ,R11  ,R12  ,R13  ,R14  ,R15  ,KC_NO, \
        KC_NO,L21  ,L22  ,L23  ,L24  ,L25                          ,R21  ,R22  ,R23  ,R24  ,R25  ,KC_NO, \
        KC_NO,L31  ,L32  ,L33  ,L34  ,L35  ,KC_NO,KC_NO,KC_NO,KC_NO,R31  ,R32  ,R33  ,R34  ,R35  ,KC_NO, \
                          E01  ,KC_NO,L41  ,L42  ,L43  ,R41  ,R42  ,R43  ,KC_NO,E02                      \
    )
// clang-format on

#include "sendstring_danish_osx.h"
#include "metheon.c"
