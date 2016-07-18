#include <node.h>
#include <nan.h>

#include <chrono>

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
  auto now = std::chrono::steady_clock::now();
  auto since = now.time_since_epoch();

  uint32_t sec =  std::chrono::duration_cast<std::chrono::seconds>(since).count();
  uint32_t nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(since).count() - sec * 1000 * 1000 * 1000;

  Local<Object> obj = Nan::New<Object>();
  Nan::Set(obj, Nan::New<String>("sec").ToLocalChecked(),
    Nan::New<Number>(sec));
  Nan::Set(obj, Nan::New<String>("nsec").ToLocalChecked(),
    Nan::New<Number>(nsec));
  info.GetReturnValue().Set(obj);
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New<String>("getTime").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(GetTime)).ToLocalChecked());
}

NODE_MODULE(addon, Init)
