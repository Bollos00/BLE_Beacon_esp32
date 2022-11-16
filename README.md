# [Bollos00/BLE_Beacon_esp32](https://github.com/Bollos00/BLE_Beacon_esp32)

Advertise iBeacon or AltBeacon using ESP32 microcontroller. The properties of the beacon can be modified by editing the macros on the header file `include/BeaconProprierties.h`.

* The Macro `BEACON_SPEC` sets the specification of the beacon. It must be `BEACON_USE_ALTBEACON` for AltBeacon specification or `BEACON_USE_IBEACON` for iBeacon specification.
* The Macro `BEACON_ADVERTISING_TOTAL_PERIOD_S` sets the period of work of the beacon, while `BEACON_ADVERTISING_DUTY_CYCLE` sets the duty cycle. The duty cycle represents the fraction of the time on which the beacon is advertising.
* The Macro `BEACON_TX_POWER` defines the Tx power in dBm (must be -12, -9, -6, -3, 0, +3, +6 or +9).
* The Macros `BEACON_UUID`, `BEACON_MAJOR` and `BEACON_MINOR` define the Beacon ID.
* The Macro `BEACON_REF_RSSI` sets the RSSI measured from a receiver at one meter away from the beacon.
* When using AltBeacon Specification, `BEACON_MFG_ID` and `BEACON_MFG_RESERVED` set the extra properties of the beacon.