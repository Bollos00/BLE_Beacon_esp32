#include <Arduino.h>
#include "sys/time.h"

#include "BLEDevice.h"
#include "BLEUtils.h"
#include "esp_sleep.h"

#include "BLE_iBeacon.h"
#include "BLE_AltBeacon.h"
#include "BeaconProprierties.h"

void setBeacon(BLEAdvertising* adv) {

    esp_ble_tx_power_set(ESP_BLE_PWR_TYPE_ADV, BEACON_TX_LEVEL);

#if BEACON_SPEC == BEACON_USE_ALTBEACON
    BLE_AltBeacon beac = BLE_AltBeacon();
    beac.getId().setUUID(BLEUUID(BEACON_UUID));
    beac.getId().setMajor(BEACON_MAJOR);
    beac.getId().setMinor(BEACON_MINOR);
    beac.setMfgId(BEACON_MFG_ID);
    beac.setRefRSSI(BEACON_REF_RSSI);
    beac.setMfgReserved(BEACON_MFG_RESERVED);
#elif BEACON_SPEC == BEACON_USE_IBEACON
    BLE_iBeacon beac = BLE_iBeacon();
    beac.setUUID(BLEUUID(BEACON_UUID));
    beac.setMajor(BEACON_MAJOR);
    beac.setMinor(BEACON_MINOR);
    beac.setRefRSSI(BEACON_REF_RSSI);
#else
    // Choose a valid value for BEACON_SPEC
#endif

    BLEAdvertisementData advData = BLEAdvertisementData();
    advData.addData(beac.getData());

    // for(int i=0; i<beac.getData().size(); ++i)
    // {
    //     Serial.printf(" %x ", beac.getData()[i]);
    // }

    adv->setAdvertisementData(advData);
    adv->setAdvertisementType(ADV_TYPE_NONCONN_IND);

}

void setup() {
    Serial.begin(115200);
    
    BLEDevice::init("");

    BLEAdvertising* adv = BLEDevice::getAdvertising();

    setBeacon(adv);
    
    adv->start();
    delay(BEACON_ADVERTISING_TIME_MS);
    adv->stop();
    esp_deep_sleep(1000LL * BEACON_PERIOD_MS);
}

void loop() {
}
