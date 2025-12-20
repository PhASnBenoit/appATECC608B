#ifndef CGUI_H
#define CGUI_H

#include <QMainWindow>
#include "catecc608b.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class CGUI;
}
QT_END_NAMESPACE

class CGUI : public QMainWindow
{
    Q_OBJECT

public:
    CGUI(QWidget *parent = nullptr);
    ~CGUI();

private slots:
    void on_sig_erreur(ATCA_STATUS err);
    void on_pbVersion_clicked();
    void on_pbSerie_clicked();
    void on_pbSlots_clicked();
    void on_pbEtatCFG_clicked();
    void on_pbEtatDATA_clicked();
    void on_pbLireCFG_clicked();

private:
    Ui::CGUI *ui;
    CATECC608B _atecc608b;  // composition statique
};
#endif // CGUI_H
