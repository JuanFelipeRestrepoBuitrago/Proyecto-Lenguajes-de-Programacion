//
// Created by Juan Felipe Restrepo Buitrago on 04/11/2022.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *e);

private slots:
    void on_verifyButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
