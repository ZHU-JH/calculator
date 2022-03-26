#include"global.h"

vector<string> stream={""};
vector<Eigen::MatrixXd>matrix_list;
//Calculator cal;
int position=0;
bool includeMatrix=false;
double ans_num=0;
Eigen::MatrixXd ans_mat=Eigen::MatrixXd::Zero(1,1);

bool isNum(string s) {
    return s.empty()||(s[0] >= '0' && s[0] <= '9' )||(s[0]=='-'&&s.size()>1)|| s[0] == '.'||s=="e"||s=="MATRIX";
}

std::string doubleToString(double value)
{
    std::ostringstream stream;
    stream.precision(10);
    stream << value;
    return stream.str();
}

double stringToDouble(std::string s)
{
    double value;
    std::stringstream ss(s);
        ss.precision(s.length());
        ss >> value;
    return value;
}

QString doubleToQString(double value)
{
    return QString::fromStdString(doubleToString(value));
}

Eigen::MatrixXd doubleToMatrix(double value){
    Eigen::Matrix<double,1,1> m;
    m(0,0)=value;
    return m;
}


