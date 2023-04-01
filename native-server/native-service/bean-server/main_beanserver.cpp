#define LOG_TAG "beanserver"
//#define LOG_NDEBUG 0

#include "BeanService.h"
#include <hidl/HidlTransportSupport.h>
using namespace android;


int main(int argc __unused, char** argv __unused)
{
    ALOGD(" beamserver start...");
    signal(SIGPIPE, SIG_IGN);

    // Set 5 threads for HIDL calls. Now cameraserver will serve HIDL calls in
    // addition to consuming them from the Camera HAL as well.
    hardware::configureRpcThreadpool(5, /*willjoin*/ false);

    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    ALOGI("ServiceManager: %p", sm.get());
    BeanService::instantiate();
    ALOGI("ServiceManager: %p done instantiate", sm.get());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
}
