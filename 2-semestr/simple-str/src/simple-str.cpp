#include "simple-str.h"

int lengthString(const char *str)
{
    if(str == nullptr || str[0] == '\0')
        return 0;
    int count = 0;
    while(str[count] != '\0')
    {
        count++;
    }
    return count;
}

int countSymbol(const char *str, char symbol)
{
    int count = 0;
    int length = lengthString(str);
    for(int i = 0; i < length; i++)
    {
        if(str[i] == symbol)
            count++;
    }
    return count;
}

long long myAtoi(const char *str)
{
    long long result = 0;
    long long rank = 1;

    int length = lengthString(str);
    for(int i = length - 1; i >= 1; i--)
    {
        if(str[i] < 48)
            throw ArgumentException();
        else if(str[i] == 48);
        else if(str[i] < 58)
            result += rank * (str[i] - 48);
        else
            throw ArgumentException();

        rank *= 10;
    }

    if(str[0] == 45)
        result *= -1;
    else if(str[0] < 48)
        throw ArgumentException();
    else if(str[0] == 48)
        result = 0;
    else if(str[0] < 58)
        result += rank * (str[0] - 48);
    else
        throw ArgumentException();

    return result;
}

char *concat(const char *strOne, const char *strTwo)
{
    char *result = new char[lengthString(strOne) + lengthString(strTwo) + 1];

    int lengthStrOne = lengthString(strOne);
    int lengthStrTwo = lengthString(strTwo);
    for(int i = 0; i < lengthStrOne; i++)
    {
        result[i] = strOne[i];
    }
    for(int i = 0; i < lengthStrTwo; i++)
    {
        result[lengthStrOne + i] = strTwo[i];
    }
    result[lengthStrOne + lengthStrTwo] = '\0';
    return result;
}

bool stringEQ(const char *strOne, const char *strTwo)
{
    if((strOne == nullptr && strTwo != nullptr) || (strOne != nullptr && strTwo == nullptr))
        return false;

    if(lengthString(strOne) != lengthString(strTwo))
        return false;

    for(int i = 0; i < lengthString(strOne); i++)
    {
        if(strOne[i] != strTwo[i])
            return false;
    }
    return true;
}

bool stringEmpty(const char *str)
{
    if(str == nullptr)
        return true;
    return stringEQ(str, "");
}

int splitString(const char *str, char symbol, char ***mas)
{
    int wordLen = 1;
    int count = countSymbol(str, symbol) + 1;
    int len = lengthString(str);
    int j = 0;

    *mas = new char *[count];
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '\0')
            break;
        if(str[i] == symbol)
        {
            (*mas)[j] = new char[wordLen];
            wordLen = 0;
            j++;
        }
        wordLen++;
    }
    (*mas)[j] = new char[wordLen];

    j = 0;
    char *temp = (*mas)[j];
    for(int i = 0; i < len; i++)
    {
        if(str[i] != symbol && str[i] != '\0')
        {
            *temp = *(str + i);
            temp++;
        } else
        {
            j++;
            temp = ((*mas)[j]);
        }
    }
    return count;
}

int myStrcmp(const char *strOne, const char *strTwo)
{
    if(stringEmpty(strOne) && stringEmpty(strTwo))
    {
        return 0;
    }

    if((stringEmpty(strOne) && !stringEmpty(strTwo)) || (!stringEmpty(strOne) && stringEmpty(strTwo)))
    {
        return 1;
    }

    int i = 1;
    while(strOne == strTwo && strOne[i - 1] != '\0' && strTwo[i - 1] != '\0')
    {
        strOne++;
        strTwo++;
        if(strOne != strTwo)
        {
            return i;
        }
        i++;
    }
    return 0;
}