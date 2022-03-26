#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <vector>
#include <memory>
#include <stack>
#include<string>
#include<QObject>
#include<Eigen/Dense>
using namespace std;

class Calculator{

private:
    Calculator(){}
    ~Calculator(){}
    Calculator(const Calculator& cal);
    Calculator& operator=(const Calculator& cal);
    void standardize(vector<string> &stream);
    void calculate(stack<double> &num);
    void calculate(stack<Eigen::MatrixXd> &mat);
public:
    static Calculator& getInstance();
    bool solve(vector<string>& stream);
    void readLine(vector<string> &stream,string text);
    void clear();
public:
    stack<double> num_stack; // 数字栈
    stack<string> op_stack; // 运算符栈
    stack<Eigen::MatrixXd> mat_stack;
};

#endif // CALCULATOR_H
