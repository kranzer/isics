#include "changepasswordmodal.h"
#include "ui_changepasswordmodal.h"

ChangePasswordModal::ChangePasswordModal(QWidget *parent, const QString& username, Storage *stor, const QString& restricted ) :
    QDialog(parent),
    ui(new Ui::ChangePasswordModal)
{
    this->restricted = restricted;
    this->stor = stor;
    this->username = username;
    connect(this->stor, SIGNAL(messageSignal(const QString&)), this, SLOT(showMessageBox(const QString&)));
    ui->setupUi(this);
}

ChangePasswordModal::~ChangePasswordModal()
{
    delete ui;
}

void ChangePasswordModal::on_changePasswordButton_clicked()
{
    QString oldPassword = ui->oldPasswordField->text();
    QString newPassword = ui->newPasswordField->text();
    QString confirm = ui->confirmField->text();
    if(this->stor->setNewPassword(username, oldPassword, newPassword, confirm, restricted))
    {
        this->close();
    }
}

void ChangePasswordModal::on_cancelButton_clicked()
{
    this->close();
}

void ChangePasswordModal::showMessageBox(const QString &m)
{
    QMessageBox::warning(this, "info", m);
}
