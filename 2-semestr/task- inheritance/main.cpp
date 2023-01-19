#include "src/TwoThree.h"

int main()
{
    Two x(3, 12);
    x.print();
    std::cout << x.study(5) << std::endl;
    x.print();

    Three y(12, 17, 3);
    y.print();
    std::cout << y.study(22) << std::endl;
    y.print();

    Three z(12, 3, 17);
    z.print();
    std::cout << z.study(15) << std::endl;
    z.print();

    Three w(12, 3, 17);
    w.print();
    std::cout << w.study(8) << std::endl;
    w.print();

    Three q(3, 12, 17);
    q.print();
    std::cout << q.study(1) << std::endl;
    q.print();
    return 0;
}