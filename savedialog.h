#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#include <QDialog>
#include <QListView>
#include <QModelIndex>
#include <QStandardItemModel>

namespace Ui {
class SaveDialog;
}

class SaveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveDialog(QWidget *parent = nullptr);
    ~SaveDialog();

signals:
    void save_signal(const QString &name);

private slots:
    void on_lineEdit_editingFinished();

    void on_save_button_clicked();

    void on_cancel_button_clicked();

    void chosen(const QModelIndex &index);

private:
    Ui::SaveDialog *ui;
    QString file_name;
    QStandardItemModel *_model;
    QListView *_listView;
};

#endif // SAVEDIALOG_H
