#ifndef STORAGE_H
#define STORAGE_H
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QObject>
class Storage : public QObject
{
    Q_OBJECT
public:
    Storage();
    QJsonArray getAllUsers();
    void updateStorage(const QJsonArray&);
public slots:
    bool setRestrictions(const QString&, bool);
    bool setNewPassword(const QString&, const QString&, const QString&, const QString&, const QString&);
    bool createNewUser(const QString&);
    bool changeUserMode(const QString&, bool);
private:
    QFile database;
signals:
    void np_messageSignal(const QString&);
    void ru_messageSignal(const QString&);
    void um_messageSignal(const QString&);
    void nu_messageSignal(const QString&);
};

#endif // STORAGE_H
