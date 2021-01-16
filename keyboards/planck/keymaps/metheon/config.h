// clang-format off
#define LAYOUT_metheon( \
        L11  ,L12  ,L13  ,L14  ,L15  ,R11  ,R12  ,R13  ,R14  ,R15  , \
        L21  ,L22  ,L23  ,L24  ,L25  ,R21  ,R22  ,R23  ,R24  ,R25  , \
        L31  ,L32  ,L33  ,L34  ,L35  ,R31  ,R32  ,R33  ,R34  ,R35  , \
                    E01  ,L41  ,L42  ,R41  ,R42  ,E02                \
    ) \
    LAYOUT_planck_1x2uC( \
        L11  ,L12  ,L13  ,L14  ,L15  ,KC_NO,KC_NO,R11  ,R12  ,R13  ,R14  ,R15  , \
        L21  ,L22  ,L23  ,L24  ,L25  ,KC_NO,KC_NO,R21  ,R22  ,R23  ,R24  ,R25  , \
        L31  ,L32  ,L33  ,L34  ,L35  ,KC_NO,KC_NO,R31  ,R32  ,R33  ,R34  ,R35  , \
        KC_NO,KC_NO,E01  ,L41  ,L42  ,KC_NO      ,R41  ,R42  ,E02  ,KC_NO,KC_NO  \
    )
// clang-format on
