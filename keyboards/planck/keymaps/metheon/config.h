#pragma once

// A Planck EZ has 47 keys while the Kyria has 50. Two of the extra keys are encoders,
// which I do not have on my Planck EZ. The two encoder spots are L30 and R30 and these
// are simply left out. The remaining key is due to the Planck EZ having a 2U spacebar.
// I compensate for the missing key simply by having that key function on a layer, still
// clicked with the right thumb. It it not terribly convenient but it is okay for now,
// until I get a grid Planck at some point. R33 left out as a result.
// After this its simply a matter of aligning the Kyria thumb cluster along the bottom
// row of the Planck EZ.

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

