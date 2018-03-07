#ifndef ADDUSERMODAL_H
#define ADDUSERMODAL_H

#include <QDialog>
#include "storage.h"
#include <QMessageBox>

namespace Ui {
class AddUserModal;
}

class AddUserModal : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserModal(QWidget *parent = 0, Storage *stor = 0);
    ~AddUserModal();

public slots:
    void showMessageBox(const QString&);

private:
    Ui::AddUserModal *ui;
    Storage *stor;
private slots:
    void on_addUserButton_clicked();
    void on_cancelButton_clicked();
};

#endif // ADDUSERMODAL_H
