#include "TinyTest.hpp"
#include <iostream>

bool firstTestCase()
{
    PASS;
}

bool secondTestCase()
{
    FAIL;
}

int main()
{
    TestRunner::inst().addTestCase(firstTestCase);
    TestRunner::inst().addTestCase(secondTestCase);
    TestRunner::inst().runAll();
    return 0;
}
