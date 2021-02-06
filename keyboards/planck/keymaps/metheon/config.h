#pragma once

#define _NONE_  KC_NO

// L30 and R30 are Kyria encoder spots, so left out for the Planck EZ.
// R33 left out as Planck EZ has a 2U spacebar. The R33 mapping is on layer for
// same key.
// Also R/L 33 and 34 are swapped compared to Kyria as thumb rests differently.

// clang-format off
#define LAYOUT_metheon( \
        L00   ,L01   ,L02   ,L03   ,L04   ,L05                                    ,R05   ,R04   ,R03   ,R02   ,R01   ,R00   , \
        L10   ,L11   ,L12   ,L13   ,L14   ,L15                                    ,R15   ,R14   ,R13   ,R12   ,R11   ,R10   , \
        L20   ,L21   ,L22   ,L23   ,L24   ,L25   ,L26   ,L27        ,R27   ,R26   ,R25   ,R24   ,R23   ,R22   ,R21   ,R20   , \
                             L30   ,L31   ,L32   ,L33   ,L34        ,R34   ,R33   ,R32   ,R31   ,R30                          \
    ) \
    LAYOUT_planck_1x2uC( \
        L00   ,L01   ,L02   ,L03   ,L04   ,L05   ,R05   ,R04   ,R03   ,R02   ,R01   ,R00   , \
        L10   ,L11   ,L12   ,L13   ,L14   ,L15   ,R15   ,R14   ,R13   ,R12   ,R11   ,R10   , \
        L20   ,L21   ,L22   ,L23   ,L24   ,L25   ,R25   ,R24   ,R23   ,R22   ,R21   ,R20   , \
        L26   ,L27   ,L31   ,L32   ,L34   ,L33          ,R34   ,R32   ,R31   ,R27   ,R26     \
    )
// clang-format on

