#include "storage.h"
#include <QDebug>
#include <QCoreApplication>
bool isUnique(std::string);
Storage::Storage()
{
    QString storageName = QCoreApplication::applicationDirPath();
    storageName.append("/admin_file.json");
    this->database.setFileName(storageName);
    qDebug() << this->database.fileName();
    if(!this->database.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        this->database.open(QIODevice::WriteOnly);
        QJsonObject admin {
            {"username", "admin"},
            {"password", ""},
            {"blocked", false},
            {"restriction", false}
        };
        QJsonDocument docum(admin);
        this->database.write("[");
        this->database.write(docum.toJson());
        this->database.write("]");
        this->database.close();
    } else {
        this->database.close();
    }

}

QJsonArray Storage::getAllUsers()
{
    this->database.open(QIODevice::ReadOnly | QIODevice::Text);
    QString data = this->database.readAll();
    this->database.close();
    QJsonDocument d = QJsonDocument::fromJson(data.toUtf8());

    return d.array();
}

bool Storage::setNewPassword(const QString &username, const QString &oldPassword, const QString &newPassword, const QString &confirm, const QString &restricted)
{
    bool success = false;
    QJsonObject updated;
    QJsonArray dataList = this->getAllUsers();
    QVariantMap user;
    bool found = false;
    for(QJsonArray::iterator it = dataList.begin(); it != dataList.end(); ++it)
    {
        const QJsonValue &val = *it;
        QJsonObject userData = val.toObject();
        QVariantMap data = userData.toVariantMap();
        if (data["username"] == username)
        {
            found = true;
            user = data;
            dataList.erase(it);
            break;
        }
    }
    if(!found)
    {
        emit np_messageSignal("No such user");
        return false;
    }
    if(user["password"] == oldPassword)
    {
        if(newPassword == confirm)
        {
            if(restricted == "true"){
                if(isUnique(newPassword.toStdString()))
                {
                    user["password"] = newPassword;
                    updated = QJsonObject::fromVariantMap(user);
                    success = true;
                } else {
                    emit np_messageSignal("Password doesn't match restriction");
                }
            } else {
                user["password"] = newPassword;
                updated = QJsonObject::fromVariantMap(user);
                success = true;
            }
        }
        else {
            emit np_messageSignal("Password and it's confirmation don't match");
        }
    }
    else {
       emit np_messageSignal("Wrong password");
    }
    if(success)
    {
        dataList << updated;
        qDebug() << dataList;
        updateStorage(dataList);
        emit np_messageSignal("Password changed");
        return true;
    }
    return false;
}

bool Storage::createNewUser(const QString &username)
{
    QJsonArray dataList = this->getAllUsers();
    QJsonObject user {
        {"username", username},
        {"password", ""},
        {"blocked", false},
        {"restriction", false}
    };
    QJsonValue val = QJsonValue(user);
    dataList.append(val);
    updateStorage(dataList);
    emit nu_messageSignal("User added");
    return true;
}

bool Storage::setRestrictions(const QString &username, bool restricted){
    bool success = false;
    bool found = false;
    QJsonObject updated;
    QJsonArray dataList = this->getAllUsers();
    QVariantMap user;
    for(QJsonArray::iterator it = dataList.begin(); it != dataList.end(); ++it)
    {
        const QJsonValue &val = *it;
        QJsonObject userData = val.toObject();
        QVariantMap data = userData.toVariantMap();
        if (data["username"] == username)
        {
            user = data;
            found = true;
            dataList.erase(it);
            break;
        }
    }
    if(found)
    {
        user["restriction"] = restricted;
        updated = QJsonObject::fromVariantMap(user);
        success = true;
    } else {
        emit ru_messageSignal("No such user");
    }
    if(success)
    {
        dataList << updated;
        qDebug() << dataList;
        updateStorage(dataList);
        emit ru_messageSignal("User restricted");
        return true;
    }
    return false;
}

bool Storage::changeUserMode(const QString &username, bool blocked)
{
    bool success = false;
    bool found = false;
    QJsonObject updated;
    QJsonArray dataList = this->getAllUsers();
    QVariantMap user;
    for(QJsonArray::iterator it = dataList.begin(); it != dataList.end(); ++it)
    {
        const QJsonValue &val = *it;
        QJsonObject userData = val.toObject();
        QVariantMap data = userData.toVariantMap();
        if (data["username"] == username)
        {
            found = true;
            user = data;
            dataList.erase(it);
            break;
        }
    }
    if(found)
    {
        user["blocked"] = blocked;
        updated = QJsonObject::fromVariantMap(user);
        success = true;
    }else {
        emit um_messageSignal("No such user");
    }
    if(success)
    {
        dataList << updated;
        qDebug() << dataList;
        updateStorage(dataList);
        emit um_messageSignal("User blocked");
        return true;
    }
    return false;
}

void Storage::updateStorage(const QJsonArray &updatedData)
{
    QString storageName = QCoreApplication::applicationDirPath();
    storageName.append("/admin_file.json");
    this->database.setFileName(storageName);
    if(this->database.open(QIODevice::WriteOnly | QIODevice::Append)){
        this->database.resize(0);
        this->database.write(QByteArray::fromRawData("[",1));
        int size = updatedData.count();
        int index = 0;
        for(QJsonArray::const_iterator it = updatedData.begin(); it != updatedData.end(); ++it)
        {
            const QJsonValue &val = *it;
            QJsonObject userData = val.toObject();
            QJsonDocument docum(userData);
            this->database.write(docum.toJson());
            index++;
            if(index < size)
            {
                this->database.write(QByteArray::fromRawData(",",1));
            }
        }
        this->database.write(QByteArray::fromRawData("]",1));
        this->database.close();
    }
}

bool isUnique(std::string str){
    bool uniq = true;
    for (std::string::size_type i = 0; i < str.size(); ++i)
        {
         if(i < str.size()-1){
            for (std::string::size_type j = i+1; j < str.size(); ++j)
            {
                if (str[j] == str[i])
                {
                    uniq = false;
                }
            }
         }
        }
    return uniq;
}
