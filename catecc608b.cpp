#include "catecc608b.h"

CATECC608B::CATECC608B(QObject *parent)
    : QObject{parent}
{
    ATCA_STATUS status = init();
    if (status != ATCA_SUCCESS) {
        emit sig_erreur(status);
    } // if status
}

CATECC608B::~CATECC608B()
{
    atcab_release();
}

ATCA_STATUS CATECC608B::init()
{
    ATCA_STATUS status;

    // Configuration I2C pour Raspberry Pi
    _cfg = {
        .iface_type     = ATCA_I2C_IFACE,
        .devtype        = ATECC608B,       // Remplacer par ATECC508A si besoin
        .atcai2c        = {
            .address       = 0xC0,         // Adresse 0x60 donné par i2cdetect I2C du composant
            .bus           = 1,            // I2C1 sur Raspberry Pi
            .baud          = 100000        // 100 kHz
        },
        .wake_delay     = 1500,
        .rx_retries     = 20
    };

    status = atcab_init(&_cfg);

    if (status != ATCA_SUCCESS) {
        emit sig_erreur(status);
    } // if status
    return status;
} // method

ATCA_STATUS CATECC608B::lireNoSerie(QString &s)
{
    ATCA_STATUS status;
    uint8_t serial[9];

    status = atcab_read_serial_number(serial);
    if (status != ATCA_SUCCESS) {
        emit sig_erreur(status);
        return status;
    } // if status
    // n° de série sur 9 octets
    for(int i=0 ; i<9 ; i++) {
        s+=QString::number(serial[i],16)+" ";
    } // for
    return status;
}

ATCA_STATUS CATECC608B::lireInfoRevision(QString &rev)
{
    ATCA_STATUS status;

    uint8_t revision[4];
    status = atcab_info(revision);
    if (status == ATCA_SUCCESS) {
        for(int i=0 ; i<4 ; i++) {
            rev+=QString::number(revision[i],16)+" ";
        } // for
        return status;
    } // if
    emit sig_erreur(status);
    return status;
}

ATCA_STATUS CATECC608B::lireConfigZone(QString &cz)
{
    uint8_t config_data[128];
    ATCA_STATUS status = atcab_read_config_zone(config_data);
    if (status != ATCA_SUCCESS) {
        emit sig_erreur(status);
        return -1;
    } // if status

    for (int i = 0; i < 128; i++) {
        cz+=QString::number(config_data[i],16)+" ";
        if ((i+1) % 16 == 0) cz+="\n";
    } // for
    return ATCA_SUCCESS;
}

int CATECC608B::lireSlot(int noSlot, QString &slot)
{
    if ( (noSlot<0) || (noSlot>15)) {
        emit sig_erreur(-1);
        return -1;
    } // if noSlot

    // Cette fonction lit un "block" de 32 octets.
    uint8_t slot_data[32];
    ATCA_STATUS status = atcab_read_zone(ATCA_ZONE_DATA, noSlot, 0, 0, slot_data, sizeof(slot_data));
    if (status != ATCA_SUCCESS) {
        emit sig_erreur(status);
        return -1;
    }

    for (int i = 0; i < 32; i++) {
        slot+=QString::number(slot_data[i],16)+" ";
        if ((i+1) % 16 == 0) slot+="\n";
    }
    return ATCA_SUCCESS;
}

ATCA_STATUS CATECC608B::isZoneCFGLocked(bool &zoneCFG)
{
    ATCA_STATUS status = atcab_is_locked(ATCA_ZONE_CONFIG, &zoneCFG);
    if (status != ATCA_SUCCESS) {
        emit sig_erreur(status);
    } // if
    return (status == ATCA_SUCCESS) ? 0 : -1;
}


ATCA_STATUS CATECC608B::isZoneDataLocked(bool &zoneData)
{
    ATCA_STATUS status = atcab_is_locked(ATCA_ZONE_DATA, &zoneData);
    if (status != ATCA_SUCCESS) {
        emit sig_erreur(status);
    } // if
    return (status == ATCA_SUCCESS) ? 0 : -1;
}
