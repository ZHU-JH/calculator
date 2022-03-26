#include<string>
#include"operator.h"
#include"global.h"
#include"Factory.h"
using namespace std;

Calculator &Calculator::getInstance()
{
    static Calculator instance;
    return instance;
}

void Calculator::standardize(vector<string> &stream){
    int sign=1;     //判断正负号
    int lCount=0;   //未匹配的左括号数
    if(stream[0]=="") stream.erase(stream.begin());//清除空字符
    for(int i=0;i<stream.size();i++){
        if(!isNum(stream[i])){
            if(stream[i]=="(") lCount++;
            if(stream[i]==")") lCount--;
            auto ptr=Factory::create(stream[i]);
            assert(ptr!=nullptr);
            if(i==0||(!isNum(stream[i-1])&&stream[i-1]!=")"&&stream[i-1]!="inv")){//删去多余的+-号
                if(stream[i]=="+"){
                    stream.erase(stream.begin()+i);
                    i--;
                }
                else if(stream[i]=="-"){
                    stream.erase(stream.begin()+i);
                    sign=-sign;
                    i--;
                }
            }
            //补全忽略的乘号，补全条件：当前字符串为单目运算符或（，且前一个字符串为数字
            if(i>0&&(ptr->numOprand<=1&&!ptr->haveLeftOprand)&&(isNum(stream[i-1]))){
                stream.insert(stream.begin()+i,"*");
                i++;
             }
        }
        else{
            //补全忽略的乘号，补全条件：当前字符串为特殊数字，且前一个字符串为数字
            if(i>0&&isNum(stream[i-1])){
                stream.insert(stream.begin()+i,"*");
                i++;
             }
            stream[i]=sign>0?stream[i]:"-"+stream[i];
            sign=1;
            }
    }    
    if(lCount<0) throw string("error: unexpected \")\"");//缺少左括号
    while(lCount>0){//补全右括号
        stream.emplace_back(")");
        lCount--;
    }
    //语法检测
    for(int i=0;i<stream.size();i++){
        if(!isNum(stream[i])){
            auto ptr=Factory::create(stream[i]);
            if(ptr->haveLeftOprand){
                if(i==0) throw string("syntax error");
                if(!isNum(stream[i-1])){
                    auto lptr=Factory::create(stream[i-1]);
                    if(lptr->haveRightOprand) throw string("syntax error");
                }
            }
            if(ptr->haveRightOprand){
                if(i==stream.size()-1)throw string("syntax error");
                if(!isNum(stream[i+1])){
                    auto lptr=Factory::create(stream[i+1]);
                    if(lptr->haveLeftOprand) throw string("syntax error");
                }
            }
        }
    }
}

bool Calculator::solve(vector<string>& stream){
    standardize(stream);
    int mat_index=0;
    for(int i=0;i<stream.size();i++){
        if (isNum(stream[i])){ //操作数入栈
            if(!includeMatrix){
                num_stack.push(stringToDouble(stream[i]));  //非矩阵模式
            }
            else if(stream[i]=="MATRIX"){
                mat_stack.push(matrix_list[mat_index++]);
            }
            else{
                mat_stack.push(doubleToMatrix(stringToDouble(stream[i])));
            }
        }
        else{               //运算符入栈
            string op=stream[i];
            if(op=="(")op_stack.push(op);
            else if(op==")"){
                while(op_stack.top()!="("){
                    if(includeMatrix){
                        calculate(mat_stack);
                    }
                    else calculate(num_stack);
                }
                op_stack.pop();  //弹出(
            }
            else{//一般操作符
                while(!op_stack.empty()){
                    if(op_stack.top()=="(") break;
                    auto ptr1=Factory::create(op);
                    auto ptr2=Factory::create(op_stack.top());
                    if(ptr1->priority<=ptr2->priority){
                        if(includeMatrix){
                            calculate(mat_stack);
                        }
                        else calculate(num_stack);
                    }
                    else break;
                }
                op_stack.push(op);
            }
        }
    }
    while(!op_stack.empty()){
        if(includeMatrix) calculate(mat_stack);
        else calculate(num_stack);
    }
    return true;
}

void Calculator::clear()
{
    num_stack = stack<double>();
    mat_stack = stack<Eigen::MatrixXd>();
    op_stack = stack<string>();
}


// 单个操作符运算
void Calculator::calculate(stack<double>&num) {
    auto ptr=Factory::create(op_stack.top());
    //if(num.size()<ptr->numOprand) throw string("syntax error");
    double a[2]={0};
    for (auto i = 0; i < ptr->numOprand; ++i) {
        a[i] = num.top();
        num.pop();
    }
    num.push(ptr->get(a[1], a[0]));
    op_stack.pop();
}
void Calculator::calculate(stack<Eigen::MatrixXd>&mat) {
    auto ptr=Factory::create(op_stack.top());
    //if(mat.size()<ptr->numOprand) throw string("syntax error");
    Eigen::MatrixXd a[2];
    for (auto i = 0; i < ptr->numOprand; ++i) {
        a[i] = mat.top();
        mat.pop();
    }
    mat.push(ptr->get(a[1], a[0]));
    op_stack.pop();
}


