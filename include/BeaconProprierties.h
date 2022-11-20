/**************************************************************
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.    
 **************************************************************/


// DO NO EDIT HERE!
#define BEACON_USE_ALTBEACON    1
#define BEACON_USE_IBEACON      2
// DO NO EDIT HERE!


// Choose which specification of beacon will be used
#define BEACON_SPEC BEACON_USE_ALTBEACON
// #define BEACON_SPEC BEACON_USE_IBEACON

// Total period of beacon
#define BEACON_ADVERTISING_TOTAL_PERIOD_S .9
// Absolute value of the duty cycle
#define BEACON_ADVERTISING_DUTY_CYCLE .12

// DO NO EDIT HERE!
const uint32_t BEACON_ADVERTISING_TIME_MS  = (uint32_t)
    (1000*BEACON_ADVERTISING_DUTY_CYCLE*BEACON_ADVERTISING_TOTAL_PERIOD_S);
const uint64_t BEACON_DEEP_SLEEP_TIME_US = (uint64_t)
    (1000000*BEACON_ADVERTISING_TOTAL_PERIOD_S - 1000*BEACON_ADVERTISING_TIME_MS);
// DO NO EDIT HERE!

// Tx power in dBm(power of transmission)
// Must be -12, -9, -6, -3, 0, +3, +6 or +9. Default will be 0 dBm
#define BEACON_TX_POWER         -6

// Propriertis of iBeacon and AltBeacon
#define BEACON_UUID             "bc3411a4-3198-45c0-aefe-3f4985a0400f"
#define BEACON_MAJOR            11000
#define BEACON_MINOR            1
// Keep it undefined to use the default value
// #define BEACON_REF_RSSI         -60

// Extra proprierties of AltBeacon
#if BEACON_SPEC == BEACON_USE_ALTBEACON
    #define BEACON_MFG_ID           0Xff
    #define BEACON_MFG_RESERVED     30
#endif

// DO NO EDIT HERE!
#if BEACON_TX_POWER == -12
    #define BEACON_TX_LEVEL ESP_PWR_LVL_N12
    #ifndef BEACON_REF_RSSI
        #define BEACON_REF_RSSI -67
    #endif
#elif BEACON_TX_POWER == -9
    #define BEACON_TX_LEVEL ESP_PWR_LVL_N9
    #ifndef BEACON_REF_RSSI
        #define BEACON_REF_RSSI -63
    #endif
#elif BEACON_TX_POWER == -6
    #define BEACON_TX_LEVEL ESP_PWR_LVL_N6
    #ifndef BEACON_REF_RSSI
        #define BEACON_REF_RSSI -58
    #endif
#elif BEACON_TX_POWER == -3
    #define BEACON_TX_LEVEL ESP_PWR_LVL_N3
    #ifndef BEACON_REF_RSSI
        #define BEACON_REF_RSSI -54
    #endif
#elif BEACON_TX_POWER == +3
    #define BEACON_TX_LEVEL ESP_PWR_LVL_P3
    #ifndef BEACON_REF_RSSI
        #define BEACON_REF_RSSI -45
    #endif
#elif BEACON_TX_POWER == +6
    #define BEACON_TX_LEVEL ESP_PWR_LVL_P6
    #ifndef BEACON_REF_RSSI
        #define BEACON_REF_RSSI -41
    #endif
#elif BEACON_TX_POWER == +9
    #define BEACON_TX_LEVEL ESP_PWR_LVL_P9
    #ifndef BEACON_REF_RSSI
        #define BEACON_REF_RSSI -37
    #endif
#else
    #define BEACON_TX_LEVEL ESP_PWR_LVL_N0
    #ifndef BEACON_REF_RSSI
        #define BEACON_REF_RSSI -50
    #endif
#endif
// DO NO EDIT HERE!