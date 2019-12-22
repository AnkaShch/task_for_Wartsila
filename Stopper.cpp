//
// Created by anka on 18.12.2019.
//

#include "Stopper.h"

void Stopper::stop() {
    std::lock_guard<std::mutex> lck(*mtx);
    *needStop = true;
}

bool Stopper::stopped() {
    std::lock_guard<std::mutex> lck(*mtx);
    return *needStop;
}

Stopper::Stopper()
        : mtx(std::make_shared<std::mutex>())
        , needStop(std::make_shared<bool>(false)){}
