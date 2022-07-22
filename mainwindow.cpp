#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QColor>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), red(0), green(0), blue(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save_image(const QString &name)
{
    image.save(QString(name) + ".jpg");
}


void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "choose your photo", "", "Images (*.jpg *.jpg *jpeg)");

    if (QString::compare(filename, QString()) != 0){

        bool isvalid = this->image.load(filename);

        if (isvalid){
            this->image = this->image.scaledToWidth(ui->image_label->width(), Qt::SmoothTransformation);
            ui->image_label->setPixmap(QPixmap::fromImage(this->image));
            ui->image_label_2->setPixmap(QPixmap::fromImage(this->image));
        }
        else{
            QMessageBox::critical(this, "Error message", "Error: loading of the photo is not valid");
        }
    }
}

void MainWindow::receiver(int r, int g, int b){
    this->red = r;
    this->green = g;
    this->blue = b;
}


void MainWindow::on_Rotate_button_clicked()
{
    this->image = this->image.mirrored(true, false);
    ui->image_label_2->setPixmap(QPixmap::fromImage(this->image));
}


void MainWindow::on_RGB_change_button_clicked()
{
    this->image = this->image.rgbSwapped();
    ui->image_label_2->setPixmap(QPixmap::fromImage(this->image));
}



void MainWindow::on_Save_button_clicked()
{
    save = new SaveDialog(this);
    save->activateWindow();
    save->show();
}


void MainWindow::on_pushButton_settings_clicked()
{
    setting = new Settings(this, this->red, this->green, this->blue);
    setting->activateWindow();
    setting->show();
}


void MainWindow::on_pushButton_mask_clicked()
{
    this->image = this->image.createMaskFromColor(QColor(this->red, this->green, this->blue).rgb(), Qt::MaskOutColor);
    ui->image_label_2->setPixmap(QPixmap::fromImage(this->image));
}

