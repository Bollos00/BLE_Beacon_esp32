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


#include "sdkconfig.h"
#include <string.h>
#include "BLE_AltBeacon.h"
#include "esp32-hal-log.h"

#define ENDIAN_CHANGE_U16(x) ((((x)&0xFF00)>>8) + (((x)&0xFF)<<8))

BLE_AltBeaconID::BLE_AltBeaconID() {

}

BLEUUID BLE_AltBeaconID::getUUID()const {
    uint8_t uuid[16];
    for(uint8_t i=0; i<16; ++i) {
        uuid[i] = id[i];
    }
	return BLEUUID(uuid, 16, false);
}

void BLE_AltBeaconID::setUUID(BLEUUID uuid) {
	uuid = BLEUUID(uuid.to128().getNative()->uuid.uuid128, 16, true);
	memcpy(id, uuid.getNative()->uuid.uuid128, 16);
}

uint16_t BLE_AltBeaconID::getMinor() {
    return ((uint16_t)id[19] << 8) | id[18];
}

void BLE_AltBeaconID::setMinor(const uint16_t minor) {
    id[19] = minor & 0xff;
    id[18] = (minor >> 8) & 0xff;
}

uint16_t BLE_AltBeaconID::getMajor() {
    return ((uint16_t)id[17] << 8) | id[16];
}

void BLE_AltBeaconID::setMajor(const uint16_t major) {
    id[17] = major & 0xff;
    id[16] = (major >> 8) & 0xff;
}

uint8_t* BLE_AltBeaconID::getData(){
    return id;
}



BLE_AltBeacon::BLE_AltBeacon() {
    m_beaconData.mfgId          = 0;
	m_beaconData.refRSSI        = 0;
    m_beaconData.mfgReserved    = 0;
	memset(m_beaconData.id.getData(), 0, sizeof(m_beaconData.id.getData()));
}

std::string BLE_AltBeacon::getData() {
	return std::string((char*) &m_beaconData, sizeof(m_beaconData));
}

uint16_t BLE_AltBeacon::getMfgId() {
	return m_beaconData.mfgId;
}

const BLE_AltBeaconID& BLE_AltBeacon::getId()const {
    return m_beaconData.id;
}

BLE_AltBeaconID& BLE_AltBeacon::getId() {
    return m_beaconData.id;
}

int8_t BLE_AltBeacon::getRefRSSI() {
	return m_beaconData.refRSSI;
}

/**
 * Set the raw data for the beacon record.
 */
void BLE_AltBeacon::setData(const std::string& data) {
	if (data.length() != sizeof(m_beaconData)) {
		log_e("Unable to set the data ... length passed in was %d and expected %d", data.length(), sizeof(m_beaconData));
		return;
	}
	memcpy(&m_beaconData, data.data(), sizeof(m_beaconData));
} // setData

void BLE_AltBeacon::setMfgId(int16_t v)
{
    m_beaconData.mfgId = ENDIAN_CHANGE_U16(v);
}

void BLE_AltBeacon::setId(const BLE_AltBeaconID& v) {
    m_beaconData.id = v;
}

void BLE_AltBeacon::setRefRSSI(int8_t rssi) {
	m_beaconData.refRSSI = rssi;
}

void BLE_AltBeacon::setMfgReserved(uint8_t v) {
	m_beaconData.mfgReserved = v;
}