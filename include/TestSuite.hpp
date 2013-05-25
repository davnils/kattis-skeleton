/**
 * TestSuite interface file.
 * Part of the public kattis-skeleton project.
 */

#pragma once

#include <iostream>
#include <sstream>

/**
 * TestSuite interface implemented by some tester.
 */
class TestSuite
{
  public:
    /**
     * Constructor initializing efficient IO.
     */
    TestSuite()
    {
      std::ios::sync_with_stdio(false);
      std::cin.tie(NULL);
    }

    /**
     * Executes all tests and verifies the return code.
     *
     * @return Zero on success.
     */
    int run()
    {
      auto ret = runTests();
      if(ret == 0)
      {
        std::cout << "All tests passed" << std::endl;
      }
      else
      {
        std::cerr << "Some test failed" << std::endl;
      }

      return(ret);
    }

  private:
    /**
     * Test function implemented by the tested class.
     *
     * @return Zero on success.
     */
    virtual int runTests() = 0;
};

/**
 * Type of global test reference, should be declared by a tester
 * (e.g. test_t g_test = TestHelloWorld(); )
 * Makefile ensures that the proper compilation unit is referenced.
 */
typedef TestSuite && test_t;

/* Here follows some misc stream testing functions */

/**
 * Verify that some output stream matches a reference string.
 *
 * @param source Source producing output.
 * @param ref Reference string.
 * @return true if the produced output matches the reference.
 */
template<typename T>
bool verifyStreamOutput(T & source, const std::string & ref)
{
  std::ostringstream os;
  os << source;
  return(os.str() == ref);
}

/**
 * Verify that some object produces the reference string, given some input string.
 *
 * @param tester Object to be tested, should implement both input and output streams.
 * @param inputRef Input string.
 * @param outputRef Reference output string.
 * @return true if the produced output matches the reference.
 */
template<typename T>
bool verifyStreams(T & tester, const std::string & inputRef, const std::string & outputRef)
{
  std::istringstream input(inputRef);
  input >> tester;
  return(verifyStreamOutput(tester, outputRef));
}

/**
 * Verify that some object maps some given input string to itself, i.e. an id function.
 *
 * @param tester Object to be tested, should implement both input and output streams.
 * @param ref Reference string.
 * @return true if the string is invariant over the tested object.
 */
template<typename T>
bool verifyStreamsId(T & tester, const std::string & ref)
{
  return(verifyStreams(tester, ref, ref));
}
