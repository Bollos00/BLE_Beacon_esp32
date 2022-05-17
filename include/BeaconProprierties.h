#define BEACON_USE_ALTBEACON    1
#define BEACON_USE_IBEACON      2

// Choose which specification of beacon will be used
#define BEACON_SPEC BEACON_USE_ALTBEACON
// #define BEACON_SPEC BEACON_USE_IBEACON

// Time of delay between advertisings
#define BEACON_PERIOD_MS        3000

// Tx power in dBm(power of transmission)
// Must be -12, -9, -6, -3, 0, +3, +6 or +9. Default will be 0 dBm
#define BEACON_TX_POWER         3


// Time on which the beacon will be advertising
#define BEACON_ADVERTISING_TIME_MS 100

// Propriertis of iBeacon and AltBeacon
#define BEACON_UUID             "123e4567-e89b-12d3-a456-426655440000"
#define BEACON_MAJOR            4001
#define BEACON_MINOR            26
#define BEACON_REF_RSSI         -60

#if BEACON_SPEC == BEACON_USE_ALTBEACON
    #define BEACON_MFG_ID           0Xff
    #define BEACON_MFG_RESERVED     30
#endif

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