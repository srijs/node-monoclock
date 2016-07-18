#include <node.h>
#include <nan.h>

#include <chrono>

NAN_METHOD(GetTime) {
  auto now = std::chrono::steady_clock::now();
  auto since = now.time_since_epoch();

  uint32_t sec =  std::chrono::duration_cast<std::chrono::seconds>(since).count();
  uint32_t nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(since).count() % (1000 * 1000 * 1000);

  v8::Local<v8::Object> obj = Nan::New<v8::Object>();
  Nan::Set(obj, Nan::New<v8::String>("sec").ToLocalChecked(),
    Nan::New<v8::Number>(sec));
  Nan::Set(obj, Nan::New<v8::String>("nsec").ToLocalChecked(),
    Nan::New<v8::Number>(nsec));
  info.GetReturnValue().Set(obj);
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New<v8::String>("getTime").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(GetTime)).ToLocalChecked());
}

NODE_MODULE(addon, Init)
