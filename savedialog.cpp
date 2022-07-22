#include "savedialog.h"
#include "ui_savedialog.h"

#include <QStandardItemModel>
#include <QString>

SaveDialog::SaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveDialog)
{
    ui->setupUi(this);
    this->setParent(parent);
    _model = new QStandardItemModel(parent);
    _model->setItem(0, 0, new QStandardItem("changedPhoto"));
    _model->setItem(1, 0, new QStandardItem("newPhoto"));
    _model->setItem(2, 0, new QStandardItem("new"));
    ui->listView->setModel(_model);
    connect(this, SIGNAL(save_signal(const QString &)), parent, SLOT(save_image(const QString &)));
    connect(this->ui->listView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(chosen(const QModelIndex &)));
}

SaveDialog::~SaveDialog()
{
    delete ui;
}

void SaveDialog::on_lineEdit_editingFinished()
{
    this->file_name = ui->lineEdit->text();
}



void SaveDialog::on_save_button_clicked()
{
    emit save_signal(file_name);
    hide();
}


void SaveDialog::on_cancel_button_clicked()
{
    hide();
}


void SaveDialog::chosen(const QModelIndex &listIndex)
{
     ui->lineEdit->setText(listIndex.data().toString());
}

