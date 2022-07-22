#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent, int r, int g, int b) : QDialog(parent), ui(new Ui::Settings), red_set(r), green_set(g), blue_set(b)
{
    ui->setupUi(this);
    this->setParent(parent);
    ui->spinBox_red->setValue(r);
    ui->spinBox_green->setValue(g);
    ui->spinBox_blue->setValue(b);
    connect(this, SIGNAL(newSettings(int, int, int)), parent, SLOT(receiver(int, int, int)));
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_spinBox_red_valueChanged(int arg1)
{
    this->red_set = ui->spinBox_red->value();
    ui->lcd_red->display(this->red_set);
    emit newSettings(this->red_set, this->green_set, this->blue_set);
}


void Settings::on_spinBox_green_valueChanged(int arg1)
{
    this->green_set = ui->spinBox_green->value();
    ui->lcd_green->display(this->green_set);
    emit newSettings(this->red_set, this->green_set, this->blue_set);
}


void Settings::on_spinBox_blue_valueChanged(int arg1)
{
    this->blue_set = ui->spinBox_blue->value();
    ui->lcd_blue->display(this->blue_set);
    emit newSettings(this->red_set, this->green_set, this->blue_set);
}


void Settings::on_pushButton_close_clicked()
{
    hide();
}

