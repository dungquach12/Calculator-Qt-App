#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "utils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect all number buttons to the same slot
    QList<QPushButton*> numButtons = {
        ui->button_num_0, ui->button_num_1, ui->button_num_2,
        ui->button_num_3, ui->button_num_4, ui->button_num_5,
        ui->button_num_6, ui->button_num_7, ui->button_num_8,
        ui->button_num_9
    };
    for (QPushButton *button : numButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::on_number_button_clicked);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_number_button_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        ui->txtDisplay->insert(button->text());
    }
}

void MainWindow::on_button_CE_clicked()
{
    ui->txtDisplay->clear();
    ui->hisDisplay->clear();
}

void MainWindow::on_button_add_clicked()
{
    ui->txtDisplay->insert(QChar(0x002B));
}

void MainWindow::on_button_subtract_clicked()
{
    ui->txtDisplay->insert(QChar(0x2212));
}

void MainWindow::on_button_multiply_clicked()
{
    ui->txtDisplay->insert(QChar(0x00D7));
}

void MainWindow::on_button_divide_clicked()
{
    ui->txtDisplay->insert(QChar(0x00F7));
}

void MainWindow::on_button_equal_clicked()
{
    if (ui->txtDisplay->text().isEmpty()) {
        return; // No expression to evaluate
    }

    // Show the submitted expression
    ui->hisDisplay->setText(QString(ui->txtDisplay->text() + "="));

    // Calculate and return the result
    QString expression = ui->txtDisplay->text();
    int result = calculateExpression(expression);
    ui->txtDisplay->setText(QString::number(result));
}

void MainWindow::on_button_backspace_clicked()
{
    int cursorPos = ui->txtDisplay->cursorPosition();
    if (cursorPos > 0) {
        ui->txtDisplay->setText(ui->txtDisplay->text().remove(cursorPos - 1, 1));
        ui->txtDisplay->setCursorPosition(cursorPos - 1);
    }
}

void MainWindow::on_button_open_parenthesis_clicked()
{
    ui->txtDisplay->insert(QChar('('));
}


void MainWindow::on_button_close_parenthesis_clicked()
{
    ui->txtDisplay->insert(QChar(')'));
}

