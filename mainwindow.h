#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_number_button_clicked();

    void on_button_CE_clicked();

    void on_button_add_clicked();
    void on_button_subtract_clicked();
    void on_button_multiply_clicked();
    void on_button_divide_clicked();

    void on_button_equal_clicked();

    void on_button_backspace_clicked();

    void on_button_open_parenthesis_clicked();

    void on_button_close_parenthesis_clicked();

    void on_button_factorial_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
