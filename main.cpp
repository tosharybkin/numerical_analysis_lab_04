#include "mainwindow.h"
#include "dirichlet_problem_solver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    auto solver = Dirichlet_problem_solver(
            4, 4, 10000, 1, 2, 2, 3, 1e-07
            );
    solver.solve();
    return a.exec();
}
