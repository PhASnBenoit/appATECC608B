#ifndef CATECC6_8B_H
#define CATECC6_8B_H

#include <QObject>
#include "cryptoauthlib.h"

class CATECC608B : public QObject
{
    Q_OBJECT
public:
    explicit CATECC608B(QObject *parent = nullptr);
    ATCA_STATUS init();
    ATCA_STATUS lireNoSerie(QString &s);
    ATCA_STATUS lireInfoRevision(QString &rev);

private:
    ATCAIfaceCfg _cfg;

signals:
    void sig_erreur(ATCA_STATUS err);
};

#endif // CATECC6_8B_H
