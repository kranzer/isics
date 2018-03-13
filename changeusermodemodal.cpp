#include "changeusermodemodal.h"
#include "ui_changeusermodemodal.h"
#include <QMessageBox>
ChangeUserModeModal::ChangeUserModeModal(QWidget *parent, Storage *stor) :
    QDialog(parent),
    ui(new Ui::ChangeUserModeModal)
{
    this->stor = stor;
    connect(this->stor, SIGNAL(um_messageSignal(const QString&)), this, SLOT(showMessageBox(const QString&)), Qt::UniqueConnection);
    ui->setupUi(this);
}

ChangeUserModeModal::~ChangeUserModeModal()
{
    delete ui;
}

void ChangeUserModeModal::on_forbidButton_clicked()
{
    if(stor->changeUserMode(ui->userNameField->text(), true))
    {
        this->close();
    }
}

void ChangeUserModeModal::on_cancelButton_clicked()
{
    this->close();
}

void ChangeUserModeModal::showMessageBox(const QString &m)
{
    QMessageBox::warning(this, "info", m);
}
