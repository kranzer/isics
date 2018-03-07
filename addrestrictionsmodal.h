#ifndef ADDRESTRICTIONSMODAL_H
#define ADDRESTRICTIONSMODAL_H

#include <QDialog>
#include "storage.h"
#include <QMessageBox>

namespace Ui {
class AddRestrictionsModal;
}

class AddRestrictionsModal : public QDialog
{
    Q_OBJECT

public:
    explicit AddRestrictionsModal(QWidget *parent = 0, Storage *stor = 0);
    ~AddRestrictionsModal();
public slots:
    void showMessageBox(const QString&);
private:
    Ui::AddRestrictionsModal *ui;
    Storage *stor;
private slots:
    void on_addRestrictionButton_clicked();
    void on_cancelButton_clicked();
};

#endif // ADDRESTRICTIONSMODAL_H
