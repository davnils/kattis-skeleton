#include "KattisTask.hpp"

class TaskHelloWorld : public KattisTask
{
  int solveTask()
  {
    std::cout << "Hello World!" << std::endl;
    return(0);
  }
};

task_t g_task = TaskHelloWorld();
