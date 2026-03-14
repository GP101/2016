#include <stdio.h>
#include <string.h>


//namespace mtstd
//{
//}

class string
{
    friend string operator+(const char* left, const string& right);

public:
    string(const char* s = nullptr)
    {
        if (s == nullptr)
            buffer[0] = NULL;
        else
            strcpy_s(buffer, 100, s);
    }

    const char* c_str() const
    {
        return buffer;
    }

    string operator+(const char* right) // operator overloading
    {
        string temp = *this;
        strcat_s(temp.buffer, right);
        return temp;
    }

    string& operator=(const string& rhs)
    {
        memcpy(buffer, rhs.buffer, sizeof(buffer));
        return *this;
    }

private:
    char    buffer[100];
};

string operator+(const char* left, const string& right)
{
    string t = left;
    strcat_s(t.buffer, right.buffer);
    return t;
}

void main()
{
    string s = "hello"; // implicit constructor
    //s = s.operator+( " world" ).operator+( "!\r\n" ); // explicit call
    s = s + " world" + "!\r\n"; // implicit call
    printf("%s\r\n", s.c_str());

    string t;
    t = "hello" + s;
    //t.operator=( operator+( "hello", s ) )
    printf("%s\r\n", t.c_str());
}