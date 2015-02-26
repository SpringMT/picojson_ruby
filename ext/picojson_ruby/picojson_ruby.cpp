#include "picojson_ruby.h"
#include "../../modules/picojson/picojson.h"

VALUE rb_cPicojsonRuby;

static VALUE rb_picojson_merge(VALUE self, VALUE base, VALUE key, VALUE value) {
  picojson::value v;
  std::string err;
  const char* json = StringValuePtr(base);
  picojson::parse(v, json, json + strlen(json), &err);
  if (!err.empty()) {
    rb_raise(rb_eTypeError, err.c_str());
  }
  const char* inserting_key = StringValuePtr(key);
  const char* inserting_value = StringValuePtr(value);
  picojson::object &obj = v.get<picojson::object>();
  obj.insert(std::make_pair(inserting_key, inserting_value));
  std::string new_json = v.serialize();
  return rb_str_new(new_json.c_str(), strlen(new_json.c_str()));
}

extern "C" void
Init_picojson_ruby(void)
{
  rb_cPicojsonRuby = rb_define_class("PicojsonRuby", rb_cObject);
  rb_define_singleton_method(rb_cPicojsonRuby, "append", RUBY_METHOD_FUNC(rb_picojson_merge), 3);
}
