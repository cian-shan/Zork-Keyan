#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ZorkUL.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_North_clicked();
    void on_South_clicked();
    void on_East_clicked();
    void on_West_clicked();
    void on_pushButton_Action1_clicked();
    void on_pushButton_Action2_clicked();
    void on_pushButton_Action3_clicked();
    void on_comboBox_activated(const QString &arg1);
};
#endif // MAINWINDOW_H
