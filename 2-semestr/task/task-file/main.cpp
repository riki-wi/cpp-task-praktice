#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void fileDistribution(const std::string &fileIn, const std::string &prefix)
{
    std::ifstream fin(fileIn,std::ios_base::in);

    if(!fin)
    {
        throw std::invalid_argument(fileIn);
    }

    std::string s;
    size_t i = 0;
    while(std::getline(fin, s))
    {
        i++;
        std::string path = prefix + std::to_string(i) + ".txt";
        std::ofstream fout(path, std::ios_base::out);
        if(!fout)
        {
            throw std::invalid_argument(path);
        }
        fout << s;
        fout.close();
    }

    fin.close();
}


void fileSum(const std::string &fileIn, const std::string &fileOut)
{
    std::ifstream fin(fileIn,   std::ios_base::in);
    std::ofstream fout(fileOut, std::ios_base::trunc);

    if(!fin)
    {
        throw std::invalid_argument(fileIn);
    } else if(!fout)
    {
        throw std::invalid_argument(fileOut);
    }else
    {
        std::string s;
        long long sum = 0;
        while(std::getline(fin, s))
        {
            std::stringstream st(s);
            long long number;

            while(st >> number)
            {
                sum += number;
            }
        }

        fout << sum;
    }
    fin.close();
    fout.close();
}


int main(int argc, char *argv[])
{
    try {

        fileSum("../resource/in_2.txt", "../resource/out_2.txt");
        fileDistribution("../resource/in_1.txt", "../resource/g");
    } catch(const std::invalid_argument &e)
    {
        std::cerr << e.what();
    }
    return 0;
}