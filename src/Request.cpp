#include <zconf.h>
#include "Request.h"

Request* GetRequest(Stopper stopSignal){
    if (stopSignal.stopped())
        return nullptr;
    sleep(1);
    Request* req = new Request();
    return req;
};

void ProcessRequest(Request* request, Stopper stopSignal) {
    int i = 1, n = request->numb;
    unsigned long long ans = 1;
    while (!stopSignal.stopped() && i <= n) {
        ans *= 2;
        ++i;
    }
    //if stopSignal is true
    if (i <= n) ans = -1;
    printf("%d : %lld\n", request->numb, ans);
};
