#define BEACON_USE_ALTBEACON    1
#define BEACON_USE_IBEACON      2

// Choose which specification of beacon will be used
#define BEACON_SPEC BEACON_USE_ALTBEACON
// #define BEACON_SPEC BEACON_USE_IBEACON

// Time of delay between advertisings
#define BEACON_PERIOD_MS        1000

// Time on which the beacon will be advertising
#define BEACON_ADVERTISING_TIME_MS 100

// Propriertis of iBeacon and iBeacon
#define BEACON_UUID             "123e4567-e89b-12d3-a456-426655440000"
#define BEACON_MAJOR            4001
#define BEACON_MINOR            26
#define BEACON_REF_RSSI         -60

#if BEACON_SPEC == BEACON_USE_ALTBEACON
    #define BEACON_MFG_ID           0Xff
    #define BEACON_MFG_RESERVED     30
#endif