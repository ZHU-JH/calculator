#ifndef GLOBAL_H
#define GLOBAL_H
#include<Eigen/Dense>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include"calculator.h"
#define PI 3.1415926535
extern int _pos;
extern int includeMatrix;
extern double ans_num;
extern Eigen::MatrixXd ans_mat;
extern vector<Eigen::MatrixXd>matrix_list;
extern vector<string> stream;

extern bool isNum(string s);
extern double stringToDouble(std::string s);
extern std::string doubleToString(double value);
extern QString doubleToQString(double value);
extern Eigen::MatrixXd doubleToMatrix(double value);
#endif // GLOBAL_H
