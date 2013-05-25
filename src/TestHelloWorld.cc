#include <cassert>
#include "TestSuite.hpp"

class TestHelloWorld : public TestSuite
{
  int runTests()
  {
    assert(1 == 1);
    return(0);
  }
};

test_t g_test = TestHelloWorld();
