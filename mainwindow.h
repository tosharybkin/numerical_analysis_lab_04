#pragma once

#include <QMainWindow>
#include <QTableWidget>
#include "dirichlet_problem_solver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void clear_table(QTableWidget *table);
    void fill_table(QTableWidget *table,
                    int m_y_partitions,
                    int n_x_partitions,
                    Dirichlet_problem_solver::matrix* matrix);
    void solve();
    void solve_test_task();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
