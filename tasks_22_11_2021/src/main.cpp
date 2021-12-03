#include <iostream>
#include <bitset>
#include <fstream>

/* Запись массива в файл */
bool writeMasFile(const std::string& name, std::string mas[], size_t size)
{
    std::ofstream fout(name, std::ios_base::app);
    for(size_t i = 0; i < size; i++)
    {
        fout << mas[i] << std::endl;

    }
    fout.close();
    return true;
}

/* Копирование файла */
bool copyFile(const std:: string& nameOne, const std:: string& nameTwo)
{
    std::ifstream fin(nameOne, std::ios_base::in);
    std::ofstream fout(nameTwo, std::ios_base::out);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << nameOne << std::endl;
        fin.close();
        return false;
    }

    int ch;
    for(;(ch = fin.get()) != EOF;)
    {
        fout.put((char)ch);
    }
    fout << std::endl;

    fin.close();
    fout.close();
    return true;
}

/* Вывод файла в консоль */
bool readFile(const std::string& name)
{
    std::ifstream fin(name, std::ios_base::in);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << name << std::endl;
        fin.close();
        return false;
    }

    int ch;
    for(;(ch = fin.get()) != EOF;)
    {
        std::cout << (char)ch;
    }

    fin.close();
    return true;
}

/* файл - картинка через bitset */
bool fileImageBitSet(const std::string& finName, const std::string& foutName)
{
    std::ifstream fin(finName, std::ios_base::in | std::ios_base::binary);
    std::ofstream fout(foutName, std::ios_base::out);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << finName << std::endl;
        fin.close();
        return false;
    }

    unsigned char ch;
    for(;fin.peek() != EOF;)
    {
        ch = fin.get();
        if(ch == 10)
        {
            fout << '\n';
        }
        else
        {
            std::bitset<8> bitCh (ch);
            for(int i = 7; i >= 0; i--)
            {
                if(bitCh[i] == 1)
                {
                    fout << '*';
                }
                else
                {
                    fout << ' ';
                }
            }
        }
    }
    fin.close();
    fout.close();
    return true;
}


/* файл - картинка */
bool fileImage(const std::string& finName, const std::string& foutName)
{
    std::ifstream fin(finName, std::ios_base::in | std::ios_base::binary);
    std::ofstream fout(foutName, std::ios_base::out);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << finName << std::endl;
        fin.close();
        return false;
    }

    unsigned char ch;
    for(;fin.peek() != EOF;)
    {
        ch = fin.get();
        if(ch == 10)
        {
            fout << '\n';
        }
        else
        {
            auto* mas = new unsigned char[8];
            for(int i = 0; i < 8; i++)
            {
                mas[i] = ch % 2;
                ch /= 2;
            }

            for(int i = 7; i > 0; i--)
            {
                if(mas[i] == 1)
                {
                    fout << '*';
                }
                else
                {
                    fout << ' ';
                }
            }
        }
    }
    fin.close();
    fout.close();
    return true;
}




int main()
{
    readFile("../resources/ex.txt");

    std::string mas[] = {"Hello", "word", "!"};
    writeMasFile("../resources/ex1.txt", mas, 3);

    copyFile("../resources/ex.txt", "../resources/ex2.txt");

    fileImageBitSet("../resources/ex.txt", "../resources/ex3.txt");
}
