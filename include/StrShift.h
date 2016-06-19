#ifndef STRSHIFT_H
#define STRSHIFT_H
#include <string>
using namespace std;

/********************************************//**
 * \class StrShift
 *  \brief Overloads 4 operators. =,==,>>,<<
 *
 ***********************************************/


class StrShift
{
    /********************************************//**
     * \brief Overload right shift
     * Example of usage:
     * @code
     * StrShift example;
     * example="Microsoft";
     * printf("%s" , example>>2);
     * @endcode
     * Prints: crosoftMi
     * \param str Reference of StrShift object on which the left shift will be applied
     * \param shift The number of letters to be shifted.
     * \return The pointer of the array of characters which represent the shifted string of the StrShift object passed.
     *
     ***********************************************/

    friend const char* operator<<(StrShift& str,int shift);

    /********************************************//**
     * \brief Overload left shift
     * Example of usage:
     * @code
     * StrShift example;
     * example="Microsoft";
     * printf("%s" , example<<2);
     * @endcode
     * Prints: ftMicroso
     *
     * \param str Reference of StrShift object on which the right shift will be applied.
     * \param shift The number of letters to be shifted.
     * \return The pointer of the array of characters which represent the shifted string of the StrShift object passed.
     *
     ***********************************************/
    friend const char* operator>>(StrShift& str,int shift);

public:
    /********************************************//**
     * \brief Default constructor
     *
     ***********************************************/
    StrShift();

    /********************************************//**
     * \brief Overload assignment operator
     * Example of usage:
     * @code
     * StrShift example;
     * example="Microsoft";
     * printf("%s", example.getStrPtr().c_str());
     * @endcode
     * Prints: Microsoft
     * \param *text pointer of the start of the char[] on the right side of the assignment
     * \return Constant reference to the object called this function
     *
     ***********************************************/
    const StrShift& operator=(const char *text);

    /********************************************//**
     * \brief Overload assignment operator
     * Example of usage:
     * @code StrShift example1, example2;
     * example1="Microsoft";
     * example2="Something else";
     * printf("%s", (example1==example2) ? "True" : "False");
     * @endcode
     * Prints: False
     * \param *text shows the start of the char[]
     * \return Constant reference to the object called this function
     *
     ***********************************************/
    bool operator==(const StrShift& str) const;

    /********************************************//**
         * \brief getter
     *
     * \return reference of the strPtr
     *
     ***********************************************/

    string& getStrPtr();
      /********************************************//**
     * \brief setter
     * \param reference of the strPtr
     * \return
     *
     ***********************************************/

    void setStrPtr(string& str);
private:

    string strPtr;/**< String variable to hold the text of the object */

};

#endif // STRSHIFT_H
