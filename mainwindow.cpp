#include <sstream>
#include <cstdlib>
#include <QString>
#include <iostream>

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

void MainWindow::clear_table(QTableWidget *table)
{
    for (int i = table->rowCount(); i >= 0; --i) {
        table->removeRow(i);
    }

    for (int i = table->columnCount(); i >= 0; --i) {
        table->removeColumn(i);
    }
}

void MainWindow::fill_table(QTableWidget *table,
                int m_y_partitions,
                int n_x_partitions,
                Dirichlet_problem_solver::matrix* matrix)
{
    for (int j = 0; j < m_y_partitions + 1; ++j)
        table->insertRow(j);

    for (int i = 0; i < m_y_partitions + 1; i++)
        table->insertColumn(i);

    int row = 0;
    int column = 0;
    for (int j = m_y_partitions; j >= 0; j--)
    {
        for (int i = 0; i <= m_y_partitions; i++)
        {
            table->setItem(row, column, new QTableWidgetItem(approx((*matrix)[i][j])));
            column++;
            column %= (n_x_partitions + 1);
        }

        row++;
    }
}

void MainWindow::solve() {
    auto n_x_partitions = ui->n_x_partitions_in_main->text().toInt();
    auto m_y_partitions = ui->m_y_partitions_in_main->text().toInt();
    auto accuracy = ui->accuracy_in_main->text().toDouble();
    auto max_iters = ui->max_iters_in_main->text().toInt();

    auto solver = Dirichlet_problem_solver_main_task(
            m_y_partitions,
            n_x_partitions,
            max_iters,
            1, 2, 2, 3,
            accuracy
    );
    auto solution = solver.solve();

    clear_table(ui->out_table_main);
    fill_table(ui->out_table_main, m_y_partitions, n_x_partitions, solution);

    auto solver_double = Dirichlet_problem_solver_main_task(
            m_y_partitions * 2,
            n_x_partitions * 2,
            max_iters,
            1, 2, 2, 3,
            accuracy
    );
    auto solution_double = solver_double.solve();

    clear_table(ui->out_table_2_main);
    fill_table(ui->out_table_2_main, m_y_partitions * 2, n_x_partitions * 2, solution_double);

    double curr_accuracy = 0;
    double max_accuracy = 0;

    for (int j = 0; j <= m_y_partitions; j++)
    {
        for (int i = 0; i <= n_x_partitions; i++)
        {
            curr_accuracy = abs((*solution_double)[2 * i][2 * j] - (*solution)[i][j]);
            if (curr_accuracy > max_accuracy)
                max_accuracy = curr_accuracy;
        }
    }

    std::cout << std::scientific << max_accuracy << std::endl;

    ui->step_num_lbl_main->setText(approx(solver.total_iters));
    ui->accuracy_lbl_main->setText(approx(solver.eps_max));

}
