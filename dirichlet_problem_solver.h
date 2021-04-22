#pragma once
#include <vector>

class Dirichlet_problem_solver
{
    using uint = unsigned int;
    using vec = std::vector<double>;
    using matrix = std::vector<vec>;

private:
    uint m_y_partitions, n_x_partitions, max_iters;
    double eps, tau;
    double x_step, y_step;
    double x_left_bound;
    double x_right_bound;
    double y_left_bound;
    double y_right_bound;
    double eps_max;
    matrix solution;

public:
    Dirichlet_problem_solver(
            uint m_y_partitions_,
            uint n_x_partitions_,
            uint max_iters_,
            double x_left_bound_,
            double x_right_bound_,
            double y_left_bound_,
            double y_right_bound_,
            double eps_
            );

    static double Uxy(double x, double y);
    static double f(double x, double y);
    static double M1(double y);
    static double M2(double y);
    static double M3(double x);
    static double M4(double x);

    void fill_start_solution();
    void calculate_tau();
    void simple_iteration_method();
    void print_solution();
    matrix fill_right_side();
    double discrepancy_of_solution();
    void solve();

};
