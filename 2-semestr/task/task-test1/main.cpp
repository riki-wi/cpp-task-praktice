#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <initializer_list>

using namespace std;

struct Polynomial
{
    int deg;
    double *m;

    Polynomial()
    {
        deg = 0;
        m = new double(0);
    }

    Polynomial(const int n, const double *t)
    {
        deg = n;
        m = new double[n + 1];
        for (auto i = 0; i < n + 1; i++)
            m[i] = t[i];
    }

    Polynomial(const Polynomial &x)
    {
        deg = x.deg;
        m = new double[deg + 1];
        for (auto i = 0; i < deg + 1; i++)
            m[i] = x.m[i];
    }

    Polynomial(const initializer_list<double> &t) :
            deg(t.size() - 1), m(new double[t.size()])
    {
        copy(t.begin(), t.end(), m);
    }

    Polynomial &operator=(const Polynomial &y)
    {
        if (this == &y)
            return *this;

        delete[] m;
        deg = y.deg;
        m = new double[deg + 1];
        for (auto i = 0; i < deg + 1; i++)
            m[i] = y.m[i];
        return *this;
    }

    double &operator[](const int i) const
    {
        static double e = -1;
        if (i >= 0 && i <= deg)
            return m[i];
        else
        {
            cout << "Ошибка: Выход за пределы массива!" << endl;
            return e;
        }
    }

    double operator()(const double y) const
    {
        double r = 0;
        for (auto i = deg; i >= 0; i--)
            r = r + m[i] * pow(y, i);
        return r;
    }

    ~Polynomial()
    {
        delete[] m;
    }
};

bool operator==(const Polynomial r1, const Polynomial r2)
{
    if (r1.deg != r2.deg) return false;
    for (auto i = 0; i <= r1.deg; i++)
        if (fabs(r1.m[i] - r2.m[i]) > 1e-12)
            return false;
    return true;
}

bool operator!=(const Polynomial r1, const Polynomial r2)
{
    return !(r1 == r2);
}

ostream &operator<<(ostream &st, const Polynomial p) // вывод
{

    for (auto i = p.deg; i > 0; i--)
        st << p.m[i] << "*x^" << i << " " << "+" << " ";
    st << p.m[0] << endl;
    return st;
}

istream &operator>>(istream &st, Polynomial &p) // ввод
{
    cin >> p.deg;
    p.m = new double[p.deg + 1];
    for (int i = 0; i <= p.deg; i++)
        cin >> p.m[i];
    return st;
}

Polynomial operator+(const Polynomial p1, const Polynomial p2)
{
    Polynomial p;
    p.deg = max(p1.deg, p2.deg);
    p.m = new double[p.deg + 1];
    if (p1.deg < p2.deg)
    {
        for (auto i = 0; i <= p1.deg; i++)
            p.m[i] = p1.m[i] + p2.m[i];
        for (auto i = p1.deg + 1; i <= p.deg; i++)
            p.m[i] = p2.m[i];
    } else
    {
        for (auto i = 0; i <= p2.deg; i++)
            p.m[i] = p1.m[i] + p2.m[i];
        for (int i = p2.deg + 1; i <= p.deg; i++)
            p.m[i] = p1.m[i];
    }
    return p;
}

void TestOne()
{
    double mas[] = {0};
    Polynomial p(0, mas);
    Polynomial g;

    assert(p == g);
}

void TestIndex()
{
    Polynomial f({1, 2, 3});

    assert(1 == f[0]);
    assert(2 == f[1]);
    assert(3 == f[2]);

    f[0] = 10;

    assert(10 == f[0]);
}

void TestAttention()
{
    Polynomial g({1, 2, 3});

    assert(1 == g(0));
    assert(6 == g(1));
}

void TestPrint()
{
    Polynomial g({1, 2, 3});
    stringstream ss;
    ss << g;

    std::string test = "3*x^2 + 2*x^1 + 1\n";
    std::string res = ss.str();

    assert(res == test);
}

void TestInput()
{
    Polynomial g({1, 2, 3});

    Polynomial p;
    cin >> p;
    assert(p == g);
}

void TestSum()
{
    Polynomial g({1, 2, 3});
    Polynomial f({3, 2, 1});

    Polynomial sum({4, 4, 4});

    assert(sum == (g + f));
}

void TestInit()
{
    double mas[] = {1, 2, 3};
    Polynomial p(2, mas);
    Polynomial g({1, 2, 3});

    assert(p == g);
}

void TestCopy()
{
    Polynomial g({1, 2, 3});
    Polynomial f = g;

    assert(g == f);
}


int main()
{
    TestOne();
    TestIndex();
    TestAttention();
    TestPrint();
    TestInput();
    TestSum();
    TestInit();
    TestCopy();
    return 0;
}