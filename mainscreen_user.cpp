#include "mainscreen_user.h"
#include "ui_mainscreen_user.h"

MainScreen_user::MainScreen_user(QWidget *parent, Storage *stor, QVariantMap *user) :
    QMainWindow(parent),
    ui(new Ui::MainScreen_user)
{
    this->stor = stor;
    this->user = *user;
    ui->setupUi(this);
    if(this->user.value("blocked").toString() == "true")
    {
        ui->changePasswordButton->setEnabled(false);
        ui->blockedLabel->setText("You are blocked, contact admin");
        ui->blockedLabel->setEnabled(true);
    }

}

MainScreen_user::~MainScreen_user()
{
    delete ui;
}

void MainScreen_user::on_changePasswordButton_clicked(){
    modal = new ChangePasswordModal(this, QString(user.value("username").toString()), stor, this->user.value("restriction").toString());
    modal->setModal(true);
    modal->show();
}

void MainScreen_user::on_actionAbout_triggered()
{
    ab = new About();
    ab->setModal(true);
    ab->show();
}
