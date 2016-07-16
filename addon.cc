#include <node.h>
#include <nan.h>

#include <time.h>
#ifdef __MACH__
  #include <mach/clock.h>
  #include <mach/mach.h>
#endif

using v8::Exception;
using v8::Function;
using v8::FunctionTemplate;
using v8::Handle;
using v8::Local;
using v8::Number;
using v8::Integer;
using v8::Object;
using v8::String;
using v8::Value;

using Nan::AsyncQueueWorker;
using Nan::AsyncWorker;
using Nan::Callback;
using Nan::Error;
using Nan::HandleScope;
using Nan::MakeCallback;
using Nan::Null;
using Nan::ObjectWrap;
using Nan::Persistent;
using Nan::Undefined;
using Nan::Utf8String;

NAN_METHOD(GetTime) {
  int ret;
  struct timespec ts;
  #ifdef __MACH__
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), SYSTEM_CLOCK, &cclock);
    ret = clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    ts.tv_sec = mts.tv_sec;
    ts.tv_nsec = mts.tv_nsec;
  #else
    ret = clock_gettime(CLOCK_MONOTONIC, &ts);
  #endif

  if (ret != 0) {
    return Nan::ThrowError(Nan::ErrnoException(errno));
  }

  uint32_t msec = static_cast<uint32_t>(ts.tv_sec * 1000 + (ts.tv_nsec / 1000 / 1000));
  uint32_t nsec = static_cast<uint32_t>(ts.tv_nsec - ((ts.tv_nsec / 1000 / 1000) * 1000 * 1000));

  Local<Object> obj = Nan::New<Object>();
  Nan::Set(obj, Nan::New<String>("msec").ToLocalChecked(),
    Nan::New<Number>(msec));
  Nan::Set(obj, Nan::New<String>("nsec").ToLocalChecked(),
    Nan::New<Number>(nsec));
  info.GetReturnValue().Set(obj);
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New<String>("getTime").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(GetTime)).ToLocalChecked());
}

NODE_MODULE(addon, Init)
