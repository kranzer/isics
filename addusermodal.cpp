#include "addusermodal.h"
#include "ui_addusermodal.h"

AddUserModal::AddUserModal(QWidget *parent, Storage *stor) :
    QDialog(parent),
    ui(new Ui::AddUserModal)
{
    this->stor = stor;
    connect(this->stor, SIGNAL(messageSignal(const QString&)), this, SLOT(showMessageBox(const QString&)));
    ui->setupUi(this);
}

AddUserModal::~AddUserModal()
{
    delete ui;
}

void AddUserModal::on_addUserButton_clicked()
{
    if(stor->createNewUser(ui->addUserField->text()))
    {
        this->close();
    }
}

void AddUserModal::on_cancelButton_clicked()
{
    this->close();
}

void AddUserModal::showMessageBox(const QString &m)
{
    QMessageBox::warning(this, "info", m);
}
