#pragma once
#include <vector>

class Dirichlet_problem_solver
{
public:
    using uint = unsigned int;
    using vec = std::vector<double>;
    using matrix = std::vector<vec>;

protected:
    int m_y_partitions, n_x_partitions, max_iters;
    double eps, tau;
    double x_step, y_step;
    double x_left_bound;
    double x_right_bound;
    double y_left_bound;
    double y_right_bound;
    matrix* solution;

    void fill_start_solution();
    void calculate_tau();
    void simple_iteration_method();
    matrix* fill_right_side();

public:
    double eps_max;
    int total_iters;

    Dirichlet_problem_solver(
            int m_y_partitions_,
            int n_x_partitions_,
            int max_iters_,
            double x_left_bound_,
            double x_right_bound_,
            double y_left_bound_,
            double y_right_bound_,
            double eps_
        );

    virtual double Uxy(double x, double y) = 0;
    virtual double f(double x, double y) = 0;
    virtual double M1(double y) = 0;
    virtual double M2(double y) = 0;
    virtual double M3(double x) = 0;
    virtual double M4(double x) = 0;

    double discrepancy_of_solution();
    matrix* solve();

};

class Dirichlet_problem_solver_main_task : public  Dirichlet_problem_solver
{
public:
    using Dirichlet_problem_solver::Dirichlet_problem_solver;

protected:
    virtual double Uxy(double x, double y) override {return 0;};
    virtual double f(double x, double y) override;
    virtual double M1(double y) override;
    virtual double M2(double y) override;
    virtual double M3(double x) override;
    virtual double M4(double x) override;
};

class Dirichlet_problem_solver_test_task : public  Dirichlet_problem_solver
{
public:
    using Dirichlet_problem_solver::Dirichlet_problem_solver;

protected:
    virtual double Uxy(double x, double y) override;
    virtual double f(double x, double y) override;
    virtual double M1(double y) override;
    virtual double M2(double y) override;
    virtual double M3(double x) override;
    virtual double M4(double x) override;
    double check_num_solution();
};
