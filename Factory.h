#ifndef FACTORY_H
#define FACTORY_H
#include <map>
#include <iostream>
#include <string>
#include<functional>
#include<memory>
#include"operator.h"
using namespace std;
class Factory {
public:
    static shared_ptr<Operator> create(string op) {
        auto it = op_map.find(op);
        if (it != op_map.end())
            return it->second();
        return 0;
    }
    static map<string, function<shared_ptr<Operator>()>> op_map; // 存储已注册运算符名及对应构建函数指针的map
};                     //函数对象

template<typename T>
class RegisterClass {
public:
    RegisterClass(string op) {//向map中插入：关键字为string,值为用lambda初始化的function对象
        Factory::op_map.emplace(op, [] {return make_shared<T>(); });
    }
};

#endif
