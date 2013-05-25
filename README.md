kattis-skeleton
===============

Basic kattis and general programming competition C++ skeleton code.

Basically consists of two separate interfaces: KattisTask and TestSuite, which are built separately using the supplied Makefile.

The test suite is useful during local testing (for example checking regressions), but isn't really necessary in most cases.

Basic workflow
---------------

Create a Task\<Assignment\>.cc file and implement the KattisTask interface.
Build using:

    make driver=Task<Assignment>

producing a binary "out", compiled using the same build flags as the current version of kattis.
Submit solutions by including "main.cc", "KattisTask.hpp" and "Task\<Assignment\>.cc".
