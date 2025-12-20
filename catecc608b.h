#ifndef CATECC6_8B_H
#define CATECC6_8B_H

#include <QObject>
#include "cryptoauthlib.h"

class CATECC608B : public QObject
{
    Q_OBJECT
public:
    explicit CATECC608B(QObject *parent = nullptr);
    ~CATECC608B();
    ATCA_STATUS lireNoSerie(QString &s);
    ATCA_STATUS lireInfoRevision(QString &rev);
    ATCA_STATUS lireConfigZone(QString &cz);
    int lireSlot(int noSlot, QString &slot);
    ATCA_STATUS isZoneCFGLocked(bool &zoneConfig);
    ATCA_STATUS isZoneDataLocked(bool &zoneData);

private:
    ATCAIfaceCfg _cfg;
    ATCA_STATUS init();

signals:
    void sig_erreur(ATCA_STATUS err);
};

#endif // CATECC6_8B_H
