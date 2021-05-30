#include <sstream>
#include <cstdlib>
#include <QString>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dirichlet_problem_solver.h"

using matrix = Dirichlet_problem_solver::matrix;
using vec = Dirichlet_problem_solver::vec;


QString approx(double num)
{
    std::ostringstream streamObj;
    streamObj << std::scientific << num;

    return QString::fromStdString(streamObj.str());
}

QString int_to_QString(int num)
{
    std::ostringstream streamObj;
    streamObj << std::scientific << num;

    return QString::fromStdString(streamObj.str());
}

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calc_button_main, &QPushButton::clicked, this, &MainWindow::solve);
    connect(ui->calc_button_test, &QPushButton::clicked, this, &MainWindow::solve_test_task);
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

void MainWindow::fill_table(QTableWidget* table,
    int m_y_partitions,
    int n_x_partitions,
    Dirichlet_problem_solver::matrix* matrix)
{
    int max_out = 10;
    int max_out_x = n_x_partitions;
    int max_out_y = m_y_partitions;
    if (max_out_x > max_out || max_out_y > max_out) {
        max_out_x = max_out;
        max_out_y = max_out;
    }


    for (int j = 0; j < max_out_y + 1; j++)
        table->insertRow(j);

    for (int i = 0; i < max_out_x + 1; i++)
        table->insertColumn(i);

    int column = 0;
    for (int j = 0; j <= max_out_y; j++)
    {
        for (int i = 0; i <= max_out_x; i++)
        {
            table->setHorizontalHeaderItem(i, new QTableWidgetItem(int_to_QString(i)));
            table->setVerticalHeaderItem(j, new QTableWidgetItem(int_to_QString(j)));
            table->setItem(j, column, new QTableWidgetItem(approx((*matrix)[j][i])));
            column++;
            column %= (max_out_x + 1);
        }
    }
}
void MainWindow::solve() {
    auto n_x_partitions = ui->n_x_partitions_in_main->text().toInt();
    auto m_y_partitions = ui->m_y_partitions_in_main->text().toInt();
    auto accuracy = ui->accuracy_in_main->text().toDouble();
    auto max_iters = ui->max_iters_in_main->text().toInt();
    auto k = ui->k_in_main->text().toInt();

    auto solver = Dirichlet_problem_solver_main_task(
            m_y_partitions,
            n_x_partitions,
            max_iters,
            1, 2, 2, 3,
            accuracy,
            k
    );
    auto solution = solver.solve();

    clear_table(ui->out_table_main);
    fill_table(ui->out_table_main, m_y_partitions, n_x_partitions, solution);

    auto solver_double = Dirichlet_problem_solver_main_task(
            m_y_partitions * 2,
            n_x_partitions * 2,
            max_iters,
            1, 2, 2, 3,
            accuracy,
            k
    );
    auto solution_double = solver_double.solve();

   clear_table(ui->out_table_2_main);
    fill_table(ui->out_table_2_main, m_y_partitions * 2, n_x_partitions * 2, solution_double);

    double curr_accuracy = 0;
    double max_accuracy = 0;
    auto solution_sub = new matrix(m_y_partitions + 1, vec(n_x_partitions + 1, 0.0));

    double max_i {0};
    double max_j {0};
    for (int j = 0; j <= m_y_partitions; j++)
    {
        for (int i = 0; i <= n_x_partitions; i++)
        {
            curr_accuracy = abs((*solution_double)[2 * j][2 * i] - (*solution)[j][i]);
            (*solution_sub)[j][i] = curr_accuracy;

            if (curr_accuracy > max_accuracy)
            {
                max_accuracy = curr_accuracy;
                max_i = i;
                max_j = j;
            }
        }
    }

    clear_table(ui->out_table_3_main);
    fill_table(ui->out_table_3_main, m_y_partitions, n_x_partitions, solution_sub);

    ui->test_accurac_lbl_main->setText(approx(max_accuracy));
    ui->step_num_lbl_main->setText(approx(solver.total_iters));
    ui->accuracy_lbl_main->setText(approx(solver.eps_max));

    std::cout << "------------------------------------------------" << std::endl
              << "Max sub at (" << max_i << ", " << max_j << ")" << std::endl
              << "Discrepancy: " << solver.discrepancy_of_solution() << std::endl
              << "------------------------------------------------" << std::endl;

}

void MainWindow::solve_test_task() {
    auto n_x_partitions = ui->n_x_partitions_in_test->text().toInt();
    auto m_y_partitions = ui->m_y_partitions_in_test->text().toInt();
    auto accuracy = ui->accuracy_in_test->text().toDouble();
    auto max_iters = ui->max_iters_in_test->text().toInt();
    auto k = ui->k_in_test->text().toInt();

    auto solver = Dirichlet_problem_solver_test_task(
            m_y_partitions,
            n_x_partitions,
            max_iters,
            1, 2, 2, 3,
            accuracy,
            k
    );
    auto solution = solver.solve();

    clear_table(ui->out_table_test);
    fill_table(ui->out_table_test, m_y_partitions, n_x_partitions, solution);

    ui->accuracy_lbl_test->setText(approx(solver.eps_max));
    ui->step_num_lbl_test->setText(approx(solver.total_iters));
    ui->test_accurac_lbl_test->setText(approx(solver.check_num_solution()));

    clear_table(ui->out_table_2_test);
    fill_table(ui->out_table_2_test, m_y_partitions, n_x_partitions, solver.analytic_solution);

    double max_i {0};
    double max_j {0};
    double max_sub {0};
    auto solution_sub = new matrix(m_y_partitions + 1, vec(n_x_partitions + 1, 0.0));
    for (int j = 0; j <= m_y_partitions; j++)
    {
        for (int i = 0; i <= n_x_partitions; i++)
        {
            double sub = abs((*solver.analytic_solution)[j][i] - (*solution)[j][i]);
            (*solution_sub)[j][i] = sub;

            if (sub > max_sub)
            {
                max_sub = sub;
                max_i = i;
                max_j = j;
            }
        }
    }

    clear_table(ui->out_table_3_test);
    fill_table(ui->out_table_3_test, m_y_partitions, n_x_partitions, solution_sub);

    std::cout << "------------------------------------------------" << std::endl
              << "Max sub at (" << max_i << ", " << max_j << ")" << std::endl
              << "Discrepancy: " << solver.discrepancy_of_solution() << std::endl
              << "------------------------------------------------" << std::endl;

}
