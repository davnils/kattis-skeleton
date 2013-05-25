/**
 * Main entry point file.
 * Part of the public kattis-skeleton project.
 */

#include <iostream>

#ifdef TEST_DRIVER
#include "TestSuite.hpp"
#else
#include "KattisTask.hpp"
#endif

/**
 * Main wrapper calling a solver.
 */
int main()
{
#ifdef TEST_DRIVER
  extern test_t g_test;
  return(g_test.run());
#else
  extern task_t g_task;
  return(g_task.solve());
#endif
}
