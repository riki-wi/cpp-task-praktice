#include "src/Expression.h"

int main()
{
    Expr *e = new Sum(new Var, new Const(2)), *p;
    e->print(); // (x+2)
    std::cout << std::endl << e->eval(4.0) << std::endl; // 6
    p = e->der(); // (1+0)
    p->print();
    std::cout << std::endl;
    delete e;
    delete p;

    //---------------------
    Expr *m = new Multiplication(new Var, new Const(2)), *p_m;
    m->print(); // (x*2)
    std::cout << std::endl << m->eval(4.0) << std::endl; // 8
    p_m = m->der(); // (1*2 + x * 0)
    p_m->print();
    std::cout << std::endl;
    delete m;
    delete p_m;


    //---------------------
    Expr *s_var = new Sin(new Var);
    Expr *c_var = new Cos(new Multiplication(new Var, new Const(2)));
    s_var->print(); // (sin(x))
    std::cout << std::endl;//
    c_var->print(); // (cos((x*2)))

    std::cout << std::endl << s_var->eval(4.0); // -0.756802
    std::cout << std::endl << c_var->eval(4.0) << std::endl; // -0.1455

    Expr *p_sin = s_var->der();
    p_sin->print();// ((cos(x))*1)
    std::cout << std::endl;

    Expr *p_cos = c_var->der();
    p_cos->print(); // ((-1*(sin((x*2))))*((1*2)+(0*x)))
    std::cout << std::endl;

    delete p_sin;
    delete p_cos;
    return 0;
}