#ifndef OPERATOR_H
#define OPERATOR_H
#include<string>
#include<map>
#include<math.h>
#include<Eigen/Dense>

using namespace std;
class Operator {
public:
    const int numOprand;  // 运算符目数
    const int priority; //运算符优先级
    bool haveLeftOprand;
    bool haveRightOprand;
    Operator(int numOprd, int pre,bool lopr=true,bool ropr=true) :
        numOprand(numOprd), priority(pre),haveLeftOprand(lopr),haveRightOprand(ropr){ }
    virtual double get(double a, double b)const{throw string("undefined");}
    virtual Eigen::MatrixXd get(Eigen::MatrixXd& a,Eigen::MatrixXd& b)const{throw string("undefined");}
    virtual ~Operator() {}
};

class Plus : public Operator { // 运算符+
public:
    Plus() :Operator( 2, 2) {}
    double get(double a, double b) const {
        return a + b;
    }
    Eigen::MatrixXd get(Eigen::MatrixXd& a,Eigen::MatrixXd& b)const{
        if(a.rows()!=b.rows()||a.cols()!=b.cols()) throw string("undefined");
        return a + b;
    }
};

class Minus :public Operator { // 运算符-
public:
    Minus() :Operator(2, 2) {}
    double get(double a, double b) const {
        return a - b;
    }
    Eigen::MatrixXd get(Eigen::MatrixXd& a,Eigen::MatrixXd& b)const{
        if(a.rows()!=b.rows()||a.cols()!=b.cols()) throw string("undefined");
        return a - b;
    }
};

class Multiply :public Operator { // 运算符*
public:
    Multiply() :Operator(2, 3) {}
    double get(double a, double b) const {
        return a * b;
    }
    Eigen::MatrixXd get(Eigen::MatrixXd& a,Eigen::MatrixXd& b)const{
        if(a.rows()==1&&a.cols()==1) return a(0,0)*b;
        if(b.rows()!=a.cols()) throw string("undefined");
        return b * a;
    }
};


class Divide :public Operator { // 运算符/
public:
    Divide() :Operator(2, 3) {}
    double get(double a, double b) const {
        if(b==0){throw string("divide by zero");}
        return a / b;
    }
};


class Left :public Operator { // 运算符#
public:
    Left() :Operator(0, 0,false,true) {}
    double get(double a, double b) const {
        return b; // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
    Eigen::MatrixXd get(Eigen::MatrixXd& a, Eigen::MatrixXd& b) const {
                return b; // 本身#不需要进行任何运算, 但是仍然需要返回值
            }
};

class Right :public Operator { // 运算符#
public:
    Right() :Operator(0, 0,true,false) {}
    double get(double a, double b) const {
        return b; // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
    Eigen::MatrixXd get(Eigen::MatrixXd& a, Eigen::MatrixXd& b) const {
            return b; // 本身#不需要进行任何运算, 但是仍然需要返回值
        }
};

class Exp10 :public Operator { // 运算符#
public:
    Exp10() :Operator(2, 4) {}
    double get(double a, double b=1) const {
        return a*pow(10,b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Pow :public Operator { // 运算符#
public:
    Pow() :Operator(2, 4) {}
    double get(double a, double b) const {
        return pow(a,b);
    }
    Eigen::MatrixXd get(Eigen::MatrixXd& a, Eigen::MatrixXd& b) const {
        if(b.size()>1) throw string("undefined");
        Eigen::MatrixXd res=a;
        double n=b(0,0);
        for(int i=1;i<n;i++){
            res*=a;
        }
        return res;
    }
};

class Mod :public Operator { // 运算符#
public:
    Mod() :Operator(2, 3) {}
    double get(double a, double b) const {
        return int(a)%int(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Sin :public Operator { // 运算符#
public:
    Sin() :Operator(1, 5,false,true) {}
    double get(double a, double b) const {
        return sin(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};


class Cos :public Operator { // 运算符#
public:
    Cos() :Operator(1, 5,false,true) {}
    double get(double a, double b) const {
        return cos(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Tan :public Operator { // 运算符#
public:
    Tan() :Operator(1, 5,false,true) {}
    double get(double a, double b) const {
        if(b==(atan(1.0) * 4)/2)throw string("undefined");
        return tan(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Sqrt :public Operator { // 运算符#
public:
    Sqrt() :Operator(1, 5,false,true) {}
    double get(double a, double b) const {
        return sqrt(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Log :public Operator { // 运算符#
public:
    Log() :Operator(1, 5,false,true) {}
    double get(double a, double b) const {
        return log10(b);
    }
};

class Ln :public Operator { // 运算符#
public:
    Ln() :Operator(1, 5,false,true) {}
    double get(double a, double b) const {
        return log(b);
    }
};

class Inverse :public Operator{
public:
    Inverse():Operator(1,5,true,false){}
    double get(double a,double b)const{
        if(b==0){throw string("divide by zero");}
        return 1 / b;
    }
    Eigen::MatrixXd get(Eigen::MatrixXd& a,Eigen::MatrixXd& b)const{
        if(b.rows()!=b.cols()||b.determinant()==0) throw string("undefined");
        return b.inverse();
    }
};


class EigValues : public Operator { // 运算符+
public:
    EigValues() :Operator( 1, 2,false,true) {}
    Eigen::MatrixXd get(Eigen::MatrixXd& a,Eigen::MatrixXd& b)const{
        Eigen::EigenSolver<Eigen::MatrixXd> eig(b);
        return eig.pseudoEigenvalueMatrix();
    }
};
class Det : public Operator{
public:
    Det():Operator(1,2,false,true){}
    Eigen::MatrixXd get(Eigen::MatrixXd& a, Eigen::MatrixXd& b) const{
        if(b.cols()!=b.rows()) throw string("undifined");
        Eigen::Matrix<double,1,1> m;
        m(0,0)=b.determinant();
        return m;
    }
};

class Adjoint : public Operator{
public:
    Adjoint():Operator(1,2,false,true){}
    Eigen::MatrixXd get(Eigen::MatrixXd& a, Eigen::MatrixXd& b) const{
        if(b.cols()!=b.rows()||b.size()==1) throw string("undifined");
        return b.adjoint();
    }
};

class Trace : public Operator{
public:
    Trace():Operator(1,2,false,true){}
    Eigen::MatrixXd get(Eigen::MatrixXd& a, Eigen::MatrixXd& b) const{
        if(b.cols()!=b.rows()) throw string("undifined");
        Eigen::Matrix<double,1,1> m;
        m(0,0)=b.trace();
        return m;
    }
};

class Transpose : public Operator{
public:
    Transpose():Operator(1,2,false,true){}
    Eigen::MatrixXd get(Eigen::MatrixXd& a, Eigen::MatrixXd& b) const{
        return b.transpose();
    }
};
#endif // OPERATOR_H
