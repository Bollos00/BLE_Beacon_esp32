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
    
    Serial.printf("\n\n");
    adv->start();
    Serial.printf("Will advertise for %fs\n", BEACON_ADVERTISING_TIME_MS*1e-3);
    delay(BEACON_ADVERTISING_TIME_MS);
    adv->stop();
    Serial.printf("Will sleep for %fs\n", BEACON_DEEP_SLEEP_TIME_US*1e-6);
    esp_deep_sleep(BEACON_DEEP_SLEEP_TIME_US);
    Serial.printf("\n\n");
}

void loop() {

}
