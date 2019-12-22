#pragma once

#include "Stopper.h"

class Request {
public:
    int arr[20] = {1, 2, 3, 4, 87443624, 5, 6, 7, 8, 9, 10770047, 10, 13 ,14, 15, 16, 1000000000, 18 , 20};
    int numb = arr[rand() % 20];
};

Request* GetRequest(Stopper stopSignal);

void ProcessRequest(Request* request, Stopper stopSignal);

