#include "catecc608b.h"

CATECC608B::CATECC608B(QObject *parent)
    : QObject{parent}
{

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
        atcab_release();
        emit sig_erreur(status);
        return status;
    } // if status
    // n° de série sur 9 octets
    for(int i=0 ; i<9 ; i++) {
        s+=QString::number(serial[i],16)+" ";
    } // for
    atcab_release();
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
