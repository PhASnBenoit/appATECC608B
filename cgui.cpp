#include "cgui.h"
#include "ui_cgui.h"

CGUI::CGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CGUI)
{
    ui->setupUi(this);
    connect(&_atecc608b, &CATECC608B::sig_erreur, this, &CGUI::on_sig_erreur);
} // construct

CGUI::~CGUI()
{
    delete ui;
}

void CGUI::on_sig_erreur(ATCA_STATUS err)
{
    ui->teStatus->append("Erreur de l'ATECC608B : "+QString::number(err));
} // destruct

void CGUI::on_pbVersion_clicked()
{
    ui->teStatus->append("Lecture version...");
    QString rev;
    ATCA_STATUS status = _atecc608b.lireInfoRevision(rev);
    if (status != ATCA_SUCCESS)
        return;
    ui->teStatus->append("Version : "+rev);
}

void CGUI::on_pbSerie_clicked()
{
    ui->teStatus->append("Lecture du numéro de série...");
    QString s;
    ATCA_STATUS status = _atecc608b.lireNoSerie(s);
    if (status != ATCA_SUCCESS)
        return;
    ui->teStatus->append("Numéro : "+s);
}


void CGUI::on_pbSlots_clicked()
{
    ui->teStatus->append("Lecture slot ");
    QString s;
    int slot = ui->sbSlot->value();
    ATCA_STATUS status = _atecc608b.lireSlot(slot, s);
    if (status != ATCA_SUCCESS)
        return;
    ui->teStatus->append("Slot 0 : "+s);
}

void CGUI::on_pbEtatCFG_clicked()
{
    bool cfg_locked = false;
    ATCA_STATUS status;

    status = _atecc608b.isZoneCFGLocked(cfg_locked);
    if (status == ATCA_SUCCESS) {
        ui->lZoneConfig->setText(cfg_locked ? "CFG LOCKED" : "CFG NOT LOCKED");
    } // if
}

void CGUI::on_pbEtatDATA_clicked()
{
    bool data_locked = false;
    ATCA_STATUS status;

    status = _atecc608b.isZoneDataLocked(data_locked);
    if (status == ATCA_SUCCESS) {
        ui->lZoneData->setText(data_locked ? "DATA LOCKED" : "DATA NOT LOCKED");
    } // if
}


void CGUI::on_pbLireCFG_clicked()
{
    ui->teStatus->append("Lecture zone config");
    QString s;
    ATCA_STATUS status = _atecc608b.lireConfigZone(s);
    if (status == ATCA_SUCCESS)
        ui->teStatus->append(s);
}

