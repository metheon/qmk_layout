#pragma once

#define _NONE_  KC_NO

// A grid planck maps one to one to the Eon40, except for the 2U spacebar

// clang-format off
#define LAYOUT_metheon( \
        L00   ,L01   ,L02   ,L03   ,L04   ,R04   ,R03   ,R02   ,R01   ,R00   , \
        L10   ,L11   ,L12   ,L13   ,L14   ,R14   ,R13   ,R12   ,R11   ,R10   , \
        L20   ,L21   ,L22   ,L23   ,L24   ,R24   ,R23   ,R22   ,R21   ,R20   , \
                      L30   ,L31   ,L32   ,R32   ,R31   ,R30                   \
    ) \
    LAYOUT_planck_mit( \
        L00   ,L01   ,L02   ,L03   ,L04   ,_NONE_,_NONE_,R04   ,R03   ,R02   ,R01   ,R00   , \
        L10   ,L11   ,L12   ,L13   ,L14   ,_NONE_,_NONE_,R14   ,R13   ,R12   ,R11   ,R10   , \
        L20   ,L21   ,L22   ,L23   ,L24   ,_NONE_,_NONE_,R24   ,R23   ,R22   ,R21   ,R20   , \
        _NONE_,_NONE_,L30   ,L31   ,L32   ,_NONE_       ,R32   ,R31   ,R30   ,_NONE_,_NONE_  \
    )
// clang-format on

