#define LOG_TAG "BeanService"
//#define LOG_NDEBUG 0

#include "BeanService.h"
#include <iostream>

namespace android {

using binder::Status;

BeanService::BeanService() {

}

BeanService::~BeanService() {

}

/*virtual*/void BeanService::binderDied(const wp<IBinder> &who) {
    ALOGE("%s: Java client's binder died, removing it from the list of active clients， who=%p",
            __FUNCTION__, &who);
}

Status BeanService::sayHello() {
    ALOGD(" BeanService::sayHello ");
    return Status::ok();
}

}