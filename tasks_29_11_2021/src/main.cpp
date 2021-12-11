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

bool printEveryFour(const std::string& name)
{

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
    return 0;
}
