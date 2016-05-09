#include "Filler.h"
#include "Logger.h"

#include <iostream> 
#include <string>
#include <functional>

/**
 *  Main method
 */
int main (int argc, char* argv[])
{
    // do we have our arguments?
    if (argc < 4) 
    {
        // give info to user
        std::cout << "usage: spool-filler sourceFilePath destinationsFilePath interval" << std::endl;

        // error
        return 1;
    }

    // parse arguments
    std::string srcPath(argv[1]);
    std::string dstPath(argv[2]);
    int interval = atoi(argv[3]) * 1000;

    // construct instance of logger
    SpoolFiller::Logger logger;

    // construct the filler instance
    SpoolFiller::Filler filler(srcPath, dstPath, interval);

    // install oniteration handler
    filler.onIteration([&logger](std::string msg) {
        logger.log(msg);
    });

    // start async filler
    auto thr = filler.asyncStart();

    // join on created thread
    thr.join();

    // we are done here
    return 0;
}
