#include <iostream>
#include <cmath>
#include <algorithm>
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

