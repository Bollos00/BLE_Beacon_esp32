#ifndef BLE_ALTBEACON_H_
#define BLE_ALTBEACON_H_
#include "BLEUUID.h"

class BLE_AltBeaconID
{
private:
    uint8_t  id[20];

public:
    BLE_AltBeaconID();
    BLEUUID getUUID()const;
    void setUUID(BLEUUID uuid);
    uint16_t getMinor();
    void setMinor(const uint16_t minor);
    uint16_t getMajor();
    void setMajor(const uint16_t major);
    uint8_t* getData();
    
}__attribute__((packed));

class BLE_AltBeacon {
private:
    struct {
        const uint8_t         flags[3]{0x02, 0x01, 0x1a};
        const uint8_t         length{27};
        const uint8_t         type{0xff};
        uint16_t              mfgId;
        const uint16_t        code{0xacbe};
        BLE_AltBeaconID       id;
        int8_t                refRSSI;
        uint8_t               mfgReserved;
    } __attribute__((packed)) m_beaconData;// BLEBeacon

public:
    BLE_AltBeacon();
    std::string               getData();
    uint16_t                  getMfgId();
    const BLE_AltBeaconID&    getId()const;
    BLE_AltBeaconID&          getId();
    int8_t                    getRefRSSI();
    uint8_t                   getMfgReserved();

    void                      setData(const std::string& data);
    void                      setMfgId(int16_t v);
    void                      setId(const BLE_AltBeaconID& v);
    void                      setRefRSSI(int8_t v);
    void                      setMfgReserved(uint8_t v);
};

#endif /* BLE_ALTBEACON_H_ */
