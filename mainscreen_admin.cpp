#include "mainscreen_admin.h"
#include "ui_mainscreen_admin.h"
#include <QDebug>

MainScreen_admin::MainScreen_admin(QWidget *parent, Storage *stor) :
    QMainWindow(parent),
    ui(new Ui::MainScreen_admin)
{
    this->stor = stor;
    ui->setupUi(this);
}

MainScreen_admin::~MainScreen_admin()
{
    delete ui;
}

void MainScreen_admin::on_adm_changePassword_clicked()
{
    changePassword = new ChangePasswordModal(this, "admin", this->stor);
    changePassword->setModal(true);
    changePassword->show();
}

void MainScreen_admin::on_forbidUserButton_clicked()
{
    changeUserMode = new ChangeUserModeModal(this, this->stor);
    changeUserMode->setModal(true);
    changeUserMode->show();
}

void MainScreen_admin::on_restrictButton_clicked()
{
    addRestrinctions = new AddRestrictionsModal(this, this->stor);
    addRestrinctions->setModal(true);
    addRestrinctions->show();
}

void MainScreen_admin::on_addUserButton_clicked()
{
    addUser = new AddUserModal(this, this->stor);
    addUser->setModal(true);
    addUser->show();
}

void MainScreen_admin::on_exitButton_clicked()
{
    this->close();
}

void MainScreen_admin::on_listUsersButton_clicked()
{
    QJsonArray users = this->stor->getAllUsers();
    listUsers = new ListUsersModal(this, &users);
    listUsers->setModal(true);
    listUsers->show();
}

void MainScreen_admin::on_actionAbout_triggered()
{
    ab = new About(this);
    ab->setModal(true);
    ab->show();
}
