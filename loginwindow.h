#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "storage.h"
#include "mainscreen_admin.h"
#include "mainscreen_user.h"
#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
    Storage *stor;
    int counter;
    MainScreen_admin *adm;
    MainScreen_user *usr;


private slots:
    void on_loginButton_clicked();
};

#endif // MAINWINDOW_H
