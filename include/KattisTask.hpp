/**
 * KattisTask interface file.
 * Part of the public kattis-skeleton project.
 */

#pragma once

#include <cassert>
#include <iostream>

/**
 * Generic interface implemented by solvers, written for specific
 * Kattis problems. Serves the purpose of cleaning up initialization,
 * ensuring proper termination and reducing bloat.
 */
class KattisTask
{
  public:
    /**
     * Constructor initializing efficient IO.
     */
    KattisTask()
    {
      std::ios::sync_with_stdio(false);
      std::cin.tie(NULL);
    }

    /**
     * Solver function called from main().
     * Ensures that a non-zero return code is not propagated to
     * the environment before making an assertion.
     *
     * @return Constant Zero.
     */
    int solve()
    {
      auto ret = solveTask();
      assert(ret == 0);
      return(ret);
    }

  private:
    /**
     * Solver function implemented by the solver.
     *
     * @return Return code from the solver.
     */
    virtual int solveTask() = 0;
};

/**
 * Type of global task reference, should be declared by a solver
 * (e.g. task_t g_task = TaskHelloWorld(); )
 * Makefile ensures that the proper compilation unit is referenced.
 */
typedef KattisTask && task_t;
