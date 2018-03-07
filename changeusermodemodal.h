#ifndef CHANGEUSERMODEMODAL_H
#define CHANGEUSERMODEMODAL_H

#include <QDialog>
#include "storage.h"
#include <QMessageBox>

namespace Ui {
class ChangeUserModeModal;
}

class ChangeUserModeModal : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeUserModeModal(QWidget *parent = 0,Storage *stor = 0);
    ~ChangeUserModeModal();
public slots:
    void showMessageBox(const QString&);
private:
    Ui::ChangeUserModeModal *ui;
    Storage *stor;

private slots:
    void on_forbidButton_clicked();
    void on_cancelButton_clicked();
};

#endif // CHANGEUSERMODEMODAL_H
