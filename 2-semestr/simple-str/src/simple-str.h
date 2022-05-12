class ArgumentException
{
private:
    char *msg;

public:
    ArgumentException()
    {
        msg = "Argument exception";
    }

    explicit ArgumentException(char *errorMsg)
    {
        msg = errorMsg;
    }

    char *what()
    {
        return msg;
    }
};

int lengthString(const char *str);

int countSymbol(const char *str, char symbol);

long long myAtoi(const char *str);

char *concat(const char *strOne, const char *strTwo);

bool stringEQ(const char *strOne, const char *strTwo);

bool stringEmpty(const char *str);

int splitString(const char *str, char symbol, char ***mas);

int myStrcmp(const char *strOne, const char *strTwo);