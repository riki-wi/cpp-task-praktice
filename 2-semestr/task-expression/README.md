
Реализовать иерархию классов, представляющую выражения, где выражение может содержать не более одной переменной.

В этой иерархии должен быть один абстрактный базовый класс Expr, описывающий интерфейс выражения, для которого должны быть определены следующие методы:
* void print() – выводит выражение на экран (без параметров);
* double eval (double x) – вычисляет значение выражения (параметр – значение переменной);
* Expr* der() – находит производную выражения;
* Expr* clone() – возвращает копию выражения.

От класса Expr должны быть унаследованы другие выражения следующих типов: константа, переменная, сумма, произведение, Sin, Cos. 

У каждого из классов должны быть соответствующие конструкторы, виртуальный деструктор.