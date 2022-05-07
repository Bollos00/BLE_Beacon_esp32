
#include "sdkconfig.h"
#include <string.h>
#include "BLE_iBeacon.h"
#include "esp32-hal-log.h"

#define ENDIAN_CHANGE_U16(x) ((((x)&0xFF00)>>8) + (((x)&0xFF)<<8))


BLE_iBeacon::BLE_iBeacon() {
	memset(m_beaconData.uuid, 0, sizeof(m_beaconData.uuid));
	m_beaconData.major          = 0;
	m_beaconData.minor          = 0;
	m_beaconData.refRSSI        = 0;
}

std::string BLE_iBeacon::getData() {
	return std::string((char*) &m_beaconData, sizeof(m_beaconData));
}

uint16_t BLE_iBeacon::getMajor() {
	return m_beaconData.major;
}

uint16_t BLE_iBeacon::getMinor() {
	return m_beaconData.minor;
}

BLEUUID BLE_iBeacon::getUUID() {
	return BLEUUID(m_beaconData.uuid, 16, false);
}

int8_t BLE_iBeacon::getRefRSSI() {
	return m_beaconData.refRSSI;
}

/**
 * Set the raw data for the beacon record.
 */
void BLE_iBeacon::setData(const std::string& data) {
	if (data.length() != sizeof(m_beaconData)) {
		log_e("Unable to set the data ... length passed in was %d and expected %d", data.length(), sizeof(m_beaconData));
		return;
	}
	memcpy(&m_beaconData, data.data(), sizeof(m_beaconData));
}
void BLE_iBeacon::setMajor(uint16_t major) {
	m_beaconData.major = ENDIAN_CHANGE_U16(major);
}
void BLE_iBeacon::setMinor(uint16_t minor) {
	m_beaconData.minor = ENDIAN_CHANGE_U16(minor);
}

void BLE_iBeacon::setUUID(BLEUUID uuid) {
	uuid = BLEUUID(uuid.to128().getNative()->uuid.uuid128, 16, true);
	memcpy(m_beaconData.uuid, uuid.getNative()->uuid.uuid128, 16);
}

void BLE_iBeacon::setRefRSSI(int8_t rssi) {
	m_beaconData.refRSSI = rssi;
}
