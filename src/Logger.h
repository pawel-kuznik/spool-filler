#pragma once

#include <string>

namespace SpoolFiller {

    /**
     *  The class that will log messages.
     */
    class Logger
    {
    public:
        // log the message
        void log(std::string message);
    };
}
