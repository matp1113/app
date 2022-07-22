#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr, int r = 0, int g = 0, int b = 0);
    ~Settings();

signals:
    void newSettings(int r, int g, int b);

private slots:

    void on_spinBox_red_valueChanged(int arg1);

    void on_spinBox_green_valueChanged(int arg1);

    void on_spinBox_blue_valueChanged(int arg1);

    void on_pushButton_close_clicked();

private:
    Ui::Settings *ui;
    int red_set;
    int green_set;
    int blue_set;
};

#endif // SETTINGS_H
