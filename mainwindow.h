#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_rollD4_clicked();

    void on_rollD6_clicked();

    void on_rollD8_clicked();

    void on_rollD10_clicked();

    void on_rollD12_clicked();

    void on_rollD20_clicked();

    void on_rollD100_clicked();

    void on_rollDX_clicked();

    void on_buttonRollStealth_clicked();

    void on_buttonRollPerception_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
