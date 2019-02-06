#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {

    // Get the render type
    if (ui->radioButton->isChecked()) {
        render_type = 0;
    } else if (ui->radioButton_2->isChecked()) {
        render_type = 1;
    }

    // Get the RGB colors
    color[0] = ui->doubleSpinBox->value();
    color[1] = ui->doubleSpinBox_2->value();
    color[2] = ui->doubleSpinBox_3->value();

    // Get point size
    point_size = ui->spinBox->value();

}

void MainWindow::on_pushButton_2_clicked() {

    // Reset the window
    color[0] = color[1] = color[2] = 0;
    point_size = 2;

}

void MainWindow::on_pushButton_3_clicked() {

    // Clear the window
    clear = true;

}
