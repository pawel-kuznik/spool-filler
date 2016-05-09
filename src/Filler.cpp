#include "Filler.h"
#include <unistd.h>

#include <fstream>
#include <sys/stat.h>

using namespace SpoolFiller;

/**
 *  Implementation for start method.
 */
void Filler::start()
{
    // infinie loop
    while (true) 
    {
        // construct timestamp
        time_t now = time(nullptr);
        auto timestamp = std::asctime(std::localtime(&now));

        // if file exists we shall skip the iteration
        struct stat buffer;
        if (stat(_targetPath.c_str(), &buffer) == 0) 
        {
            // call callback
            _onIteration(std::string(timestamp) + " " +  "no change");

            // ok sleep execution
            usleep(_interval);

            // to the next iteration
            continue;
        }

        // create source and destination streams
        std::ifstream src(_sourceFile, std::ios::binary);
        std::ofstream dst(_targetPath, std::ios::binary);

        // copy the actual file
        dst << src.rdbuf();

        // call the callback
        _onIteration(std::string(timestamp) + " " + "filled");

        // ok sleep execution
        usleep(_interval);
    }
}

/**
 *  Implementation for async start.
 */
std::thread Filler::asyncStart()
{
    // construct thread and return it
    return std::thread(&Filler::start, this);
}

