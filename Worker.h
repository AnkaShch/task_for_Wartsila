//
// Created by anka on 21.12.2019.
//

#pragma once

#include <boost/lockfree/queue.hpp>
#include <boost/thread/thread.hpp>
#include "Request.h"
#include <thread>
#include <vector>

class Worker {
private:
    boost::lockfree::queue<Request*> q{128};
    std::vector<std::thread> threads;
    int NUMB_OF_THREADS = 3;
    Stopper stopper;

    void runMaster();
    void runOneWorker();
    void runWorkers();
    void stopAll();
    void cleanQueue();

public:
    void run(int time);
    Worker(int numb_of_treads);
};

