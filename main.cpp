#include "./include/StrShift.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "./include/catch.h"
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


StrShift getTestObject(const char *input)
{
    StrShift example;
    example=input;
    return example;
}

const char* ts[]= {"Microsoft", "Boogle", "Amazona", "ParseIsDead", "Azure", "SomeW?#4!_''|@","1234" };
vector<string> testStrings(ts, ts+7);

TEST_CASE( "Overload = Operator Test", "[assignment]" )
{
    for (unsigned int i = 0; i < (unsigned)testStrings.size(); i++)
    {
        REQUIRE(getTestObject(testStrings.at(i).c_str()).getStrPtr().compare(testStrings.at(i))==0);
    }
}

TEST_CASE( "Overload == Operator Test", "[equals]" )
{
    for (unsigned int i = 0; i < (unsigned)testStrings.size(); i++)
    {
        REQUIRE(getTestObject(testStrings.at(i).c_str())==getTestObject(testStrings.at(i).c_str()));
    }
}

TEST_CASE( "Overload << Operator Test", "[out_to_left]" )
{
    printf("\n<< operator test\n");
    StrShift example = getTestObject("Microsoft");
    example << 1;
    printf("%s\n",example.getStrPtr().c_str());

    REQUIRE(string("tMicrosof").compare(example.getStrPtr())==0);

    example << 1;
    printf("%s\n",example.getStrPtr().c_str());

	REQUIRE(string("ftMicroso").compare(example.getStrPtr())==0);
}

TEST_CASE( "Overload >> Operator Test", "[in_to_right]" )
{
	printf("\n>> operator test\n");
    StrShift example = getTestObject("Microsoft");
    example >> 1;
    printf("%s\n",example.getStrPtr().c_str());

    REQUIRE(string("icrosoftM").compare(example.getStrPtr())==0);

    example >> 1;
    printf("%s\n",example.getStrPtr().c_str());

	REQUIRE(string("crosoftMi").compare(example.getStrPtr())==0);
}



TEST_CASE( "Right (>>) and back again (<<) Test", "[right_and_left]" )
{ 	srand (0);
    printf("\nRight and back again test\n");
    for (unsigned int i = 0; i < (unsigned)testStrings.size(); i++)
    {
        int randomInt = rand() % 20;
        printf("%d\n",randomInt);
        StrShift example=getTestObject(testStrings.at(i).c_str());
        int shift=randomInt;
        example>>shift;
        printf(" %s >> %d \n",example.getStrPtr().c_str(), shift );
        example<<shift;
        printf(" %s << %d \n",example.getStrPtr().c_str(), shift );

        REQUIRE(example==getTestObject(testStrings.at(i).c_str()));
    }
}


TEST_CASE( "Left (<<) and back again (>>) Test", "[left_and_right]" )
{
	srand (1);
    printf("\nLeft and back again test\n");
    for (unsigned int i = 0; i < (unsigned)testStrings.size(); i++)
    {
        int randomInt = rand() % 20;
        StrShift example=getTestObject(testStrings.at(i).c_str());
        int shift=randomInt;
        printf("%d\n",randomInt);
        example<<shift;
        printf(" %s << %d \n",example.getStrPtr().c_str(), shift );
        example>>shift;
        printf(" %s >> %d \n",example.getStrPtr().c_str(), shift );

        REQUIRE(example==getTestObject(testStrings.at(i).c_str()));
    }
}


TEST_CASE( "Empty string", "[empty_string]" )

{
    StrShift example;
    REQUIRE_THROWS_AS(example="",invalid_argument);
}

TEST_CASE( "Negative left shift", "[negative_left_shift]" )
{
    StrShift example=getTestObject("Microsoft");

    REQUIRE_THROWS_AS( example<<-10, invalid_argument);
}

TEST_CASE( "Negative right shift", "[negative_right_shift]" )
{
    StrShift example=getTestObject("Microsoft");

    REQUIRE_THROWS_AS( example>>-10, invalid_argument);
}



