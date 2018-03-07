#include "listusersmodal.h"
#include "ui_listusersmodal.h"

ListUsersModal::ListUsersModal(QWidget *parent, const QJsonArray* arr) :
    QDialog(parent),
    ui(new Ui::ListUsersModal)
{
    ui->setupUi(this);
    for(QJsonArray::const_iterator it = (*arr).begin(); it != (*arr).end(); ++it)
    {
        const QJsonValue &val = *it;
        QJsonObject userData = val.toObject();
        QVariantMap data = userData.toVariantMap();
        ui->displayBrowser->append(QString(data.value("username").toString() + " " +
                                   data.value("password").toString() + " " +
                                   data.value("blocked").toString() + " " +
                                   data.value("restriction").toString()));
    }
}

ListUsersModal::~ListUsersModal()
{
    delete ui;
}
