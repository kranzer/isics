#ifndef MAINSCREEN_ADMIN_H
#define MAINSCREEN_ADMIN_H

#include <QMainWindow>
#include "changepasswordmodal.h"
#include "changeusermodemodal.h"
#include "addrestrictionsmodal.h"
#include "addusermodal.h"
#include "listusersmodal.h"
#include "about.h"

namespace Ui {
class MainScreen_admin;
}

class MainScreen_admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen_admin(QWidget *parent = 0, Storage *stor = 0);
    ~MainScreen_admin();

private:
    Ui::MainScreen_admin *ui;
    ChangePasswordModal *changePassword;
    ChangeUserModeModal *changeUserMode;
    AddRestrictionsModal *addRestrinctions;
    AddUserModal *addUser;
    ListUsersModal *listUsers;
    Storage *stor;
    About *ab;

private slots:
    void on_adm_changePassword_clicked();
    void on_forbidUserButton_clicked();
    void on_restrictButton_clicked();
    void on_addUserButton_clicked();
    void on_exitButton_clicked();
    void on_listUsersButton_clicked();
    void on_actionAbout_triggered();

signals:
    void changePasswordSingal(const QString &);
};

#endif // MAINSCREEN_ADMIN_H
