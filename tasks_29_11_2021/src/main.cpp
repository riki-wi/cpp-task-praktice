#include <iostream>
#include <fstream>

/* размер файла */
size_t sizeFile(const std::string& name)
{
    std::ifstream fin(name, std::ios_base::in | std::ios_base::binary);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << name << std::endl;
        fin.close();
        return false;
    }
    fin.seekg(0, std::ios::end);
    long long size =  fin.tellg();
    return size;
}

/* копирование файла через read, write */
bool copyReadWrite(const std::string& nameIn, const std::string& nameOut)
{
    std::ifstream fin(nameIn, std::ios_base::in | std::ios_base::binary);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << nameIn << std::endl;
        fin.close();
        return false;
    }

    std::ofstream fout(nameOut, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
    for(size_t i = 0; i < sizeFile(nameIn); i++)
    {
        char byte;
        fin.read(&byte, sizeof(char));
        fout.write(&byte, sizeof(char));
    }

    fin.close();
    fout.close();
    return true;
}

/* функция выводит каждый 4-ый байт файла */
bool printEveryFour(const std::string& name)
{
    std::ifstream fin(name, std::ios_base::in | std::ios_base::binary);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << name << std::endl;
        fin.close();
        return false;
    }
    for(size_t i = 0; i < sizeFile(name); i += 4)
    {
        int byte;
        fin.seekg((long long)i);
        std::cout << "position: " << fin.tellg();
        fin.read((char*)&byte, sizeof(char));
        std::cout << " byte: " << byte << std::endl;
    }
    fin.close();
    return true;
}

/* запись массива в файл */
template <typename T>
void writeMasInFile(const std::string& name, T** mas, size_t n, size_t m)
{
    std::ofstream fout(name, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
    fout.write((char*)mas, sizeof(T) * m * n);
    std::cout << "Записанно " << fout.tellp() << " байт" << std::endl;
    fout.close();
}

/* получение эллемента массива из файла по индексу */
int getElementByIndex(const std::string& name, size_t n, size_t m, size_t indexN, size_t indexM)
{
    std::ifstream fin(name, std::ios_base::in | std::ios_base::binary);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << name << std::endl;
        fin.close();
        return false;
    }
    int res;
    fin.seekg((long long)(m * indexN + indexM));
    fin.read((char*)&res, 4);
    fin.close();
    return res;
}

/* функция получает ширину bmp файла */
size_t getWidth(const std::string& name)
{
    std::ifstream fin(name, std::ios_base::in | std::ios_base::binary);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << name << std::endl;
        fin.close();
        return 0;
    }
    fin.seekg(18);
    size_t width = 0;
    fin.read((char*)&width, 4);
    fin.close();
    return width;
}

/* функция получает высоту bmp файла */
size_t getHeight(const std::string& name)
{
    std::ifstream fin(name, std::ios_base::in | std::ios_base::binary);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << name << std::endl;
        fin.close();
        return 0;
    }
    fin.seekg(22);
    size_t height = 0;
    fin.read((char*)&height, 4);
    fin.close();
    return height;
}


int main(int argc, char* argv[])
{
    std::string source;
    std::string destination;

    if(argc != 5)
    {
        std::cout << "Неверное число параметров " << std::endl;
        exit(1);
    }

    for(int i = 1; i < 5; i++)
    {
        if(strcmp(argv[i], "-i") == 0)
        {
            source = argv[i + 1];
        }
        if(strcmp(argv[i], "-o") == 0)
        {
            destination = argv[i + 1];
        }
    }

    copyReadWrite(source, destination);
    printEveryFour(source);
    std::cout << "Ширина(в байтах) exBMP.bpm = " << getWidth("../resources/exBMP.bmp")
              << " Высота(в байтах) = " << getHeight("../resources/exBMP.bmp") << std::endl;



    size_t n = 5;
    size_t m = 4;
    int* masDate = new int[n * m];
    for(size_t i = 0; i < n * m; i++)
    {
        masDate[i] = (int)i;
    }
    int** mas = new int*[n];
    for(size_t i = 0, j = 0; i < n * m; i += m, j++)
    {
        mas[j] = &masDate[i];
    }
    writeMasInFile("../resources/exMas.txt", mas, 5, 4);
    std::cout << "эллемент с индексом (3 2) = "
              << getElementByIndex("../resources/exMas.txt", 5, 4, 3, 2)
              << std::endl;
    return 0;
}
