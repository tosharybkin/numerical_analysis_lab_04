#include <sstream>
#include <cstdlib>
#include <QString>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dirichlet_problem_solver.h"

QString approx(double num)
{
    std::ostringstream streamObj;
    streamObj << num;

    return QString::fromStdString(streamObj.str());
}

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calc_button_main, &QPushButton::clicked, this, &MainWindow::solve);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::solve() {
    auto n_x_partitions = ui->n_x_partitions_in_main->text().toInt();
    auto m_y_partitions = ui->m_y_partitions_in_main->text().toInt();
    auto accuracy = ui->accuracy_in_main->text().toDouble();
    auto max_iters = ui->max_iters_in_main->text().toInt();

    auto solver = Dirichlet_problem_solver(
            m_y_partitions,
            n_x_partitions,
            max_iters,
            1, 2, 2, 3,
            accuracy
    );
    auto solution = solver.solve();

    for (int i = ui->out_table_main->rowCount(); i >= 0; --i) {
        ui->out_table_main->removeRow(i);
    }

    for (int i = ui->out_table_main->columnCount(); i >= 0; --i) {
        ui->out_table_main->removeColumn(i);
    }

    for (int j = 0; j < m_y_partitions + 1; ++j)
        ui->out_table_main->insertRow(j);

    for (int i = 0; i < m_y_partitions + 1; i++)
        ui->out_table_main->insertColumn(i);

    int row = 0;
    int column = 0;
    for (int j = m_y_partitions; j >= 0; j--)
    {
        for (int i = 0; i <= m_y_partitions; i++)
        {
            ui->out_table_main->setItem(row, column, new QTableWidgetItem(approx((*solution)[i][j])));
            column++;
            column %= (n_x_partitions + 1);
        }

        row++;
    }

    ui->step_num_lbl_main->setText(approx(solver.total_iters));
    ui->accuracy_lbl_main->setText(approx(solver.eps_max));

}
