#include"Factory.h"
#include<QString>
map<string, function<shared_ptr<Operator>()>> Factory::op_map;
#define REGISTER(Key,T)  RegisterClass<T> reg_##T(Key)

REGISTER("+",Plus);
REGISTER("-",Minus);
REGISTER("×",Multiply);
REGISTER("÷",Divide);
REGISTER("(",Left);
REGISTER(")",Right);
REGISTER("%",Mod);
REGISTER("e+",Exp10);
REGISTER("inv",Inverse);
REGISTER("pow",Pow);
REGISTER("sin",Sin);
REGISTER("cos",Cos);
REGISTER("tan",Tan);
REGISTER("ln",Ln);
REGISTER("log",Log);
REGISTER("eigen",EigValues);
REGISTER("det",Det);
REGISTER("tr",Trace);
REGISTER("trans",Transpose);
REGISTER("adj",Adjoint);
REGISTER(QString(QChar(0x221A)).toStdString(),Sqrt);

