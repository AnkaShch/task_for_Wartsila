#include "Worker.h"

void Worker::run(int time) {
    std::thread getReq(&Worker::runMaster, this);
    runWorkers();
    sleep(time);
    stopAll();
    getReq.join();
    cleanQueue();
}

void Worker::runMaster() {
    while (!stopper.stopped()) {
        Request *request = GetRequest(stopper);
        if (request != nullptr)
            q.push(request);
    }
}

void Worker::runWorkers() {
    for (int i = 0; i < NUMB_OF_THREADS; ++i) {
        threads.emplace_back(&Worker::runOneWorker, this);
    }
}

void Worker::runOneWorker() {
    while (!stopper.stopped()) {
        Request *request;
        if (q.pop(request)) {
            ProcessRequest(request, stopper);
            delete request;
        }
    }
}

void Worker::stopAll() {
    stopper.stop();
    for (int i = 0; i < NUMB_OF_THREADS; ++i) {
        threads[i].join();
    }
}

Worker::Worker(int numb_of_treads) {
    NUMB_OF_THREADS = numb_of_treads;
}

void Worker::cleanQueue() {
    while (!q.empty()) {
        Request *req;
        q.pop(req);
        delete req;
    }
}

