#include "dirichlet_problem_solver.h"

#include <cmath>
#include <cstdio>

#define _USE_MATH_DEFINES
#include <cmath>

Dirichlet_problem_solver::Dirichlet_problem_solver(Dirichlet_problem_solver::uint m_y_partitions_,
                                                   Dirichlet_problem_solver::uint n_x_partitions_,
                                                   Dirichlet_problem_solver::uint max_iters_, double x_left_bound_,
                                                   double x_right_bound_, double y_left_bound_, double y_right_bound_,
                                                   double eps_)
{
    m_y_partitions = m_y_partitions_;
    n_x_partitions = n_x_partitions_;
    max_iters = max_iters_;
    total_iters = 0;

    x_left_bound = x_left_bound_;
    x_right_bound = x_right_bound_;
    y_left_bound = y_left_bound_;
    y_right_bound = y_right_bound_;

    x_step = (x_right_bound - x_left_bound) / n_x_partitions;
    y_step = (y_right_bound - y_left_bound) / m_y_partitions;

    eps = eps_;
    eps_max = 0.0;

    solution = new matrix(m_y_partitions + 1, vec(n_x_partitions + 1, 0.0));
}


double Dirichlet_problem_solver::Uxy(double x, double y)
{
    return sin(M_PI * x * y);
}


double Dirichlet_problem_solver::f(double x, double y)
{
    return -exp(-1 * x * y * y);
}


double Dirichlet_problem_solver::M1(double y)
{
    return (y - 2) * (y - 3);
}


double Dirichlet_problem_solver::M2(double y)
{
    return (y - 2) * (y - 3) * y;
}


double Dirichlet_problem_solver::M3(double x)
{
    return (x - 1) * (x - 2);
}


double Dirichlet_problem_solver::M4(double x)
{
    return (x - 1) * (x - 2) * x;
}


void Dirichlet_problem_solver::fill_start_solution()
{
    for (int j = 0; j <= m_y_partitions; j++) {
        for (int i = 0; i <= n_x_partitions; i++) {
            if (i == 0 || j == 0 || i == n_x_partitions || j == m_y_partitions) {
                double Xi, Yj;
                Xi = x_left_bound + i * x_step;
                Yj = y_left_bound + j * y_step;

                if (j == 0)
                    (*solution)[i][j] = M3(Xi);
                else if (j == m_y_partitions)
                    (*solution)[i][j] = M4(Xi);

                if (i == 0)
                    (*solution)[i][j] = M1(Yj);
                else if (i == n_x_partitions)
                    (*solution)[i][j] = M2(Yj);
            } else
                (*solution)[i][j] = 0.0;
        }
    }
}

void Dirichlet_problem_solver::calculate_tau() {
    double eig_val_max;
    double eig_val_min;

    eig_val_min = (4.0 / (x_step * x_step))
                * sin(M_PI / (2 * n_x_partitions))
                * sin(M_PI / (2 * n_x_partitions))
                + (4.0 / (y_step * y_step))
                * sin(M_PI / (2 * m_y_partitions))
                * sin(M_PI / (2 * m_y_partitions));

    eig_val_max = (4.0 / (x_step * x_step))
                  * sin((M_PI * (n_x_partitions - 1)) / (2 * n_x_partitions))
                  * sin((M_PI * (n_x_partitions - 1)) / (2 * n_x_partitions))
                  + (4.0 / (y_step * y_step))
                  * sin((M_PI * (m_y_partitions - 1)) / (2 * m_y_partitions))
                  * sin((M_PI * (m_y_partitions - 1)) / (2 * m_y_partitions));



    tau = 2 / (eig_val_max + eig_val_min);
}

void Dirichlet_problem_solver::simple_iteration_method() {
    double eps_cur = 0.0;
    double h2 = 1 / (x_step * x_step);
    double k2 = 1 / (y_step * y_step);
    double a2 = -2 * (h2 + k2);
    uint iter = 0;

    double v_old, v_new;

    while (true)
    {
        iter++;
        eps_max = 0;

        for (int j = 1; j < m_y_partitions; j++)
            for (int i = 1; i < n_x_partitions; i++)
            {
                double Xi, Yj;
                Xi = x_left_bound + i * x_step;
                Yj = y_left_bound + j * y_step;

                v_old = (*solution)[i][j];
                v_new = v_old + tau * (
                        h2 * ((*solution)[i - 1][j] + (*solution)[i + 1][j])
                        + k2 * ((*solution)[i][j - 1] + (*solution)[i][j + 1])
                        + a2 * v_old
                        + f(Xi, Yj)
                        );


                eps_cur = std::abs(v_old - v_new);

                if (eps_cur > eps_max)
                    eps_max = eps_cur;

                (*solution)[i][j] = v_new;
            }

        if ((eps_max < eps) || (iter >= max_iters))
            break;
    }

    total_iters = iter;
}

void Dirichlet_problem_solver::print_solution() {
    for (int j = m_y_partitions; j >= 0; j--)
    {
        for (int i = 0; i <= m_y_partitions; i++)
            printf("%5.3lf   ", (*solution)[i][j]);
        printf("\n");
    }

    printf("%5.16lf   ", discrepancy_of_solution());
}

Dirichlet_problem_solver::matrix* Dirichlet_problem_solver::fill_right_side()
{
    auto F = new matrix(m_y_partitions + 1, vec(n_x_partitions + 1, 0.0));

    for (int j = 1; j < m_y_partitions; j++)
        for (int i = 1; i < n_x_partitions; i++)
        {
            double Xi, Yj, sum = 0;
            Xi = x_left_bound + i * x_step;
            Yj = y_left_bound + j * y_step;

            if (j == 1)
                sum += (1 / (y_step * y_step)) * M3(Xi);
            else if (j == m_y_partitions - 1)
                sum += (1 / (y_step * y_step)) * M4(Xi);

            if (i == 1)
                sum += (1 / (x_step * x_step)) * M1(Yj);
            else if (i == n_x_partitions - 1)
                sum += (1 / (x_step * x_step)) * M2(Yj);

            (*F)[i][j] = -f(Xi, Yj) - sum;
        }

    return F;
}

double Dirichlet_problem_solver::discrepancy_of_solution()
{
    double rs = 0;

    double h2 = 1 / (x_step * x_step);
    double k2 = 1 / (y_step * y_step);
    double a2 = -2 * (h2 + k2);

    auto F = fill_right_side();

    for (int j = 1; j < m_y_partitions; j++)
    {
        for (int i = 1; i < n_x_partitions; i++)
        {
            double r {0};
            double mult {1};

            if (j != 1 && j != m_y_partitions - 1)
            {
                if (i != 1 && i != n_x_partitions - 1)
                    mult = k2 * (*solution)[i][j - 1] + h2 * (*solution)[i - 1][j] + a2 * (*solution)[i][j] + h2 * (*solution)[i + 1][j] + k2 * (*solution)[i][j + 1];
                else if (i == 1)
                    mult = k2 * (*solution)[i][j - 1] + a2 * (*solution)[i][j] + h2 * (*solution)[i + 1][j] + k2 * (*solution)[i][j + 1];
                else if (i == n_x_partitions - 1)
                    mult = k2 * (*solution)[i][j - 1] + h2 * (*solution)[i - 1][j] + a2 * (*solution)[i][j] + k2 * (*solution)[i][j + 1];
            }
            else if (j == 1)
            {
                if (i == 1)
                    mult = a2 * (*solution)[i][j] + h2 * (*solution)[i + 1][j] + k2 * (*solution)[i][j + 1];
                else if (i != n_x_partitions - 1)
                    mult = h2 * (*solution)[i - 1][j] + a2 * (*solution)[i][j] + h2 * (*solution)[i + 1][j] + k2 * (*solution)[i][j + 1];
                else if (i == n_x_partitions - 1)
                    mult = h2 * (*solution)[i - 1][j] + a2 * (*solution)[i][j] + k2 * (*solution)[i][j + 1];
            }
            else if (j == m_y_partitions - 1)
            {
                if (i == 1)
                    mult = k2 * (*solution)[i][j - 1] + a2 * (*solution)[i][j] + h2 * (*solution)[i + 1][j];
                else if (i != n_x_partitions - 1)
                    mult = k2 * (*solution)[i][j - 1] + h2 * (*solution)[i - 1][j] + a2 * (*solution)[i][j] + h2 * (*solution)[i + 1][j];
                else if (i == n_x_partitions - 1)
                    mult = k2 * (*solution)[i][j - 1] + h2 * (*solution)[i - 1][j] + a2 * (*solution)[i][j];
            }

            r = fabs(mult - (*F)[i][j]);
            rs += r * r;
        }
    }

    return sqrt(rs);
}

Dirichlet_problem_solver::matrix* Dirichlet_problem_solver::solve() {
    fill_start_solution();
    calculate_tau();
    simple_iteration_method();
    //print_solution();

    return solution;
}
