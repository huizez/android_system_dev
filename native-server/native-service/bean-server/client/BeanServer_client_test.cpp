#define LOG_TAG "beanclient"
//#define LOG_NDEBUG 0
#include <com/zzh/IBeanService.h>
#include <binder/IServiceManager.h>

using namespace android;
using com::zzh::IBeanService;


int main(int argc __unused, char** argv __unused) {

    ALOGD(" beanclient start...");  
    sp<IServiceManager> sm = defaultServiceManager(); 
    sp<IBinder> binder;
    do {
        binder = sm->getService(String16("bean.like"));
        if (binder != 0) {
            break;
        }
        usleep(500000); // 0.5s
    } while (true);

    sp<IBeanService>   beanService = interface_cast<IBeanService>(binder);
    
    beanService->sayHello();
    
    return 0;
}