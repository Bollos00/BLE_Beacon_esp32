
#ifndef BLE_IBEACON_H_
#define BLE_IBEACON_H_
#include "BLEUUID.h"
/**
 * @brief Representation of a beacon.
 * See:
 * * https://en.wikipedia.org/wiki/IBeacon
 */
class BLE_iBeacon {
private:
	struct {
	 	const uint8_t    flags[3]{0x02, 0x01, 0x06};
		const uint8_t  	 length{26};
		const uint8_t    type{0xff};
		const uint8_t    companyId[2]{0x4c, 0x00};
		const uint8_t    beacon_type[2]{0x02, 0x15};
		uint8_t  		 uuid[16];
		uint16_t		 major;
		uint16_t 		 minor;
		int8_t   		 refRSSI;
	} __attribute__((packed)) m_beaconData;
public:
	BLE_iBeacon();
	std::string 		 getData();
	uint16_t    	     getMajor();
	uint16_t    		 getMinor();
	BLEUUID     		 getUUID();
	int8_t		         getRefRSSI();
	
	void          		 setData(const std::string& data);
	void		         setMajor(uint16_t major);
	void        		 setMinor(uint16_t minor);
	void        		 setUUID(BLEUUID uuid);
	void        		 setRefRSSI(int8_t rssi);
}; // BLEBeacon

#endif /* BLE_IBEACON_H_ */
