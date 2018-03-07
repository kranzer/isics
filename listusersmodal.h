#ifndef LISTUSERSMODAL_H
#define LISTUSERSMODAL_H

#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>

namespace Ui {
class ListUsersModal;
}

class ListUsersModal : public QDialog
{
    Q_OBJECT

public:
    explicit ListUsersModal(QWidget *parent = 0, const QJsonArray* arr = 0);
    ~ListUsersModal();

private:
    Ui::ListUsersModal *ui;
};

#endif // LISTUSERSMODAL_H
