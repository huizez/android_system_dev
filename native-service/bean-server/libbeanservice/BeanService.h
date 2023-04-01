#ifndef BEANSERVICE_H
#define BEANSERVICE_H

#include <com/zzh/BnBeanService.h>
#include <binder/BinderService.h>

namespace android {

class BeanService:
    public BinderService<BeanService>,
    public virtual ::com::zzh::BnBeanService,
    public virtual IBinder::DeathRecipient
{
public:
    // Implementation of BinderService<T>
    static char const* getServiceName() { return "bean.like"; }

    // IBinder::DeathRecipient implementation
    virtual void        binderDied(const wp<IBinder> &who);
    
    BeanService();
    ~BeanService();
    virtual binder::Status  sayHello();
};

}

#endif