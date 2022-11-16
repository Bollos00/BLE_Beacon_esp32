// DO NO EDIT HERE!
#define BEACON_USE_ALTBEACON    1
#define BEACON_USE_IBEACON      2
// DO NO EDIT HERE!


// Choose which specification of beacon will be used
#define BEACON_SPEC BEACON_USE_ALTBEACON
// #define BEACON_SPEC BEACON_USE_IBEACON

// Total period of beacon
#define BEACON_ADVERTISING_TOTAL_PERIOD_S .2
// Absolute value of the duty cycle
#define BEACON_ADVERTISING_DUTY_CYCLE .8

// DO NO EDIT HERE!
const uint32_t BEACON_ADVERTISING_TIME_MS  = (uint32_t)
    (1000*BEACON_ADVERTISING_DUTY_CYCLE*BEACON_ADVERTISING_TOTAL_PERIOD_S);
const uint64_t BEACON_DEEP_SLEEP_TIME_US = (uint64_t)
    (1000000*BEACON_ADVERTISING_TOTAL_PERIOD_S - 1000*BEACON_ADVERTISING_TIME_MS);
// DO NO EDIT HERE!

// Tx power in dBm(power of transmission)
// Must be -12, -9, -6, -3, 0, +3, +6 or +9. Default will be 0 dBm
#define BEACON_TX_POWER         -3

// Propriertis of iBeacon and AltBeacon
#define BEACON_UUID             "bc3411a4-3198-45c0-aefe-3f4985a0400f"
#define BEACON_MAJOR            4005
#define BEACON_MINOR            26
#define BEACON_REF_RSSI         -60

// Extra proprierties of AltBeacon
#if BEACON_SPEC == BEACON_USE_ALTBEACON
    #define BEACON_MFG_ID           0Xff
    #define BEACON_MFG_RESERVED     30
#endif

// DO NO EDIT HERE!
#if BEACON_TX_POWER == -12
#define BEACON_TX_LEVEL ESP_PWR_LVL_N12
#elif BEACON_TX_POWER == -9
#define BEACON_TX_LEVEL ESP_PWR_LVL_N9
#elif BEACON_TX_POWER == -6
#define BEACON_TX_LEVEL ESP_PWR_LVL_N6
#elif BEACON_TX_POWER == -3
#define BEACON_TX_LEVEL ESP_PWR_LVL_N3
#elif BEACON_TX_POWER == +3
#define BEACON_TX_LEVEL ESP_PWR_LVL_P3
#elif BEACON_TX_POWER == +6
#define BEACON_TX_LEVEL ESP_PWR_LVL_P6
#elif BEACON_TX_POWER == +9
#define BEACON_TX_LEVEL ESP_PWR_LVL_P9
#else
#define BEACON_TX_LEVEL ESP_PWR_LVL_N0
#endif
// DO NO EDIT HERE!