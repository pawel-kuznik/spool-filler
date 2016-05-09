#pragma once

#include <string>
#include <thread>

// declare namespace
namespace SpoolFiller {

    /**
     *  The filler class that will try to keep a file in specific path.
     */
    class Filler
    {

    private:

        /**
         *  The original file path.
         */
        std::string _sourceFile;

        /**
         *  The path where the file should be copied.
         */
        std::string _targetPath;

        /**
         *  Amount of miliseconds that has to pass before filler will check if
         *  file is there.
         */
        int _interval;

        /**
         *  Callback to call when iteration occurs
         */
        std::function<void(std::string)> _onIteration;

    public:

        /**
         *  Constructor
         */
        Filler(std::string sourceFile, std::string targetPath, int interval) : _sourceFile(sourceFile), _targetPath(targetPath), _interval(interval) { }

        /**
         *  Start
         */
        void start();

        /**
         *  Async start. It will return a thread that this class will be started in.
         */
        std::thread asyncStart();

        /**
         *  Install callback to call when iteration occurs
         */
        void onIteration(std::function<void(std::string)> callback)
        {
            _onIteration = callback;
        }
    };
};
