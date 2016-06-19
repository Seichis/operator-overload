#include "../include/StrShift.h"
#include <cassert>
#include <stdio.h>
#include <string>
#include <stdexcept>
#include <stdlib.h>

using namespace std;

StrShift::StrShift()
{
    strPtr=string();
}

const StrShift& StrShift::operator=(const char *text)
{

    strPtr=string(text);
    if (strPtr.empty())
    {
        throw std::invalid_argument( "received empty string" );
        exit(0);

    }
    return *this;
}

bool StrShift::operator==(const StrShift& other) const
{
    return (strPtr.compare(other.strPtr)==0);
}


const char* operator<<(StrShift& str,int shift)
{
    if (shift<0)
    {
        throw std::invalid_argument( "received negative value" );
        exit(0);
    }
    if (str.strPtr.length()<(unsigned)shift)
    {
        int remainder = shift%str.strPtr.length();
        if (remainder!=0)
        {
            str.strPtr=str.strPtr.substr(str.strPtr.length()-remainder,str.strPtr.length()) + str.strPtr.substr(0,str.strPtr.length()-remainder);
        }
    }
    else
    {
        str.strPtr=str.strPtr.substr(str.strPtr.length()-shift,str.strPtr.length()) + str.strPtr.substr(0,str.strPtr.length()-shift);
    }

    return str.strPtr.c_str();

}

const char* operator>>(StrShift& str,int shift)
{
    if (shift<0)
    {
        throw std::invalid_argument( "received negative value" );
        exit(0);

    }

    if (str.strPtr.length()<(unsigned)shift)
    {
        int remainder = shift%str.strPtr.length();
        if (remainder!=0)
        {
            str.strPtr = str.strPtr.substr(remainder,str.strPtr.length())+str.strPtr.substr(0,remainder);
        }
    }
    else
    {
        str.strPtr = str.strPtr.substr(shift,str.strPtr.length())+str.strPtr.substr(0,shift);
    }

    return str.strPtr.c_str();
}

string& StrShift::getStrPtr()
{
    return strPtr;
}

void StrShift::setStrPtr(string& str)
{
    strPtr.clear();
    strPtr=str;
}
