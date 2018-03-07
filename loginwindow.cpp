#include "loginwindow.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>


LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    counter = 0;
    stor = new Storage();
    ui->setupUi(this);
    ui->passwordField->setEchoMode(QLineEdit::Password);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    bool success = false;
    QString username = ui->usernameField->text();
    QString password = ui->passwordField->text();
    QJsonArray dataList = this->stor->getAllUsers();
    for(QJsonArray::iterator it = dataList.begin(); it != dataList.end(); ++it)
    {
        const QJsonValue &val = *it;
        QJsonObject userData = val.toObject();
        QVariantMap data = userData.toVariantMap();
        if (data["username"] == username && data["password"] == password)
        {
            success = true;
            if (username == "admin")
            {
                adm = new MainScreen_admin(this, stor);
                this->close();
                adm->show();
            }
            else {
                usr = new MainScreen_user(this, stor, &data);
                this->close();
                usr->show();
            }
            break;
        }
    }
    if(!success)
    {
        QMessageBox::warning(this, "Login", "Your login credentials are incorrect!");
        this->counter+=1;
        if(this->counter == 3)
        {
            this->close();
        }
    }


}
