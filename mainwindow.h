#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include "settings.h"
#include "savedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_Rotate_button_clicked();

    void on_RGB_change_button_clicked();

    void on_Save_button_clicked();

    void on_pushButton_settings_clicked();

    void on_pushButton_mask_clicked();

public slots:
   void receiver(int r, int g, int b);

   void save_image(const QString &name);

private:
    Ui::MainWindow *ui;
    QImage image;
    Settings *setting;
    SaveDialog *save;
    int red;
    int green;
    int blue;
};
#endif // MAINWINDOW_H
