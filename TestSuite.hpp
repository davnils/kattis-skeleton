/**
 * TestSuite interface file.
 * Part of the public kattis-skeleton project.
 */

#pragma once

#include <cassert>
#include <iostream>
#include <sstream>

class TestSuite
{
  public:
    TestSuite()
    {
      std::ios::sync_with_stdio(false);
      std::cin.tie(NULL);
    }

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
    virtual int runTests() = 0;
};

typedef TestSuite && test_t;

template<typename T>
bool verifyStreamOutput(T & source, const std::string & ref)
{
  std::ostringstream os;
  os << source;
  return(os.str() == ref);
}

template<typename T>
bool verifyStreams(T & tester, const std::string & inputRef, const std::string & outputRef)
{
  std::istringstream input(inputRef);
  input >> tester;
  return(verifyStreamOutput(tester, outputRef));
}

template<typename T>
bool verifyStreamsId(T & tester, const std::string & ref)
{
  return(verifyStreams(tester, ref, ref));
}
