#include "cgui.h"
#include "ui_cgui.h"

CGUI::CGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CGUI)
{
    ATCA_STATUS status;

    ui->setupUi(this);

    connect(&_atecc608b, &CATECC608B::sig_erreur, this, &CGUI::on_sig_erreur);

    ui->teStatus->append("Initialisation...");
    status = _atecc608b.init();
    if (status != ATCA_SUCCESS)
        return;
    ui->teStatus->append("Initialisation terminée...");

    ui->teStatus->append("Lecture version...");
    QString rev;
    status = _atecc608b.lireInfoRevision(rev);
    if (status != ATCA_SUCCESS)
        return;
    ui->teStatus->append("Version : "+rev);

    ui->teStatus->append("Lecture du numéro de série...");
    QString s;
    status = _atecc608b.lireNoSerie(s);
    if (status != ATCA_SUCCESS)
        return;
    ui->teStatus->append("Numéro : "+s);

} // construct

CGUI::~CGUI()
{
    delete ui;
}

void CGUI::on_sig_erreur(ATCA_STATUS err)
{
    ui->teStatus->append("Erreur de l'ATECC608B : "+QString::number(err));
} // destruct
