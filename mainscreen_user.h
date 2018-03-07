#ifndef MAINSCREEN_USER_H
#define MAINSCREEN_USER_H

#include <QMainWindow>
#include <QVariantMap>
#include "storage.h"
#include "changepasswordmodal.h"
#include "about.h"

namespace Ui {
class MainScreen_user;
}

class MainScreen_user : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen_user(QWidget *parent = 0, Storage *stor = 0, QVariantMap *user = 0);
    ~MainScreen_user();

private:
    Ui::MainScreen_user *ui;
    Storage *stor;
    QVariantMap user;
    ChangePasswordModal *modal;
    About *ab;

private slots:
    void on_changePasswordButton_clicked();
    void on_actionAbout_triggered();
};

#endif // MAINSCREEN_USER_H
