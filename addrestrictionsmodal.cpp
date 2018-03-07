#include "addrestrictionsmodal.h"
#include "ui_addrestrictionsmodal.h"

AddRestrictionsModal::AddRestrictionsModal(QWidget *parent, Storage *stor) :
    QDialog(parent),
    ui(new Ui::AddRestrictionsModal)
{
    this->stor = stor;
    connect(this->stor, SIGNAL(messageSignal(const QString&)), this, SLOT(showMessageBox(const QString&)));
    ui->setupUi(this);
}

AddRestrictionsModal::~AddRestrictionsModal()
{
    delete ui;
}

void AddRestrictionsModal::on_addRestrictionButton_clicked()
{
    if(stor->setRestrictions(ui->restrictionField->text(), true)){
        this->close();
    }
}

void AddRestrictionsModal::on_cancelButton_clicked()
{
    this->close();
}

void AddRestrictionsModal::showMessageBox(const QString &m)
{
    QMessageBox::warning(this, "info", m);
}
