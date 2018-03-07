#ifndef CHANGEPASSWORDMODAL_H
#define CHANGEPASSWORDMODAL_H

#include <QDialog>
#include "storage.h"
#include <QMessageBox>
namespace Ui {
class ChangePasswordModal;
}

class ChangePasswordModal : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswordModal(QWidget *parent = 0, const QString& username="", Storage *stor = 0, const QString& restricted = "");
    ~ChangePasswordModal();

public slots:
    void showMessageBox(const QString&);

private:
    Ui::ChangePasswordModal *ui;
    Storage* stor;
    QString username;
    QString restricted;

private slots:
    void on_changePasswordButton_clicked();
    void on_cancelButton_clicked();
};

#endif // CHANGEPASSWORDMODAL_H
