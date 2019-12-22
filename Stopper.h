//
// Created by anka on 18.12.2019.
//

#pragma once

#include <mutex>
#include <memory>

class Stopper {
private:
    std::shared_ptr<bool> needStop;
    std::shared_ptr<std::mutex> mtx;

public:
    void stop();
    bool stopped();
    Stopper();
};

