#include "picojson_ruby.h"
#include "picojson.h"

VALUE rb_cPicojsonRuby;

static VALUE rb_picojson_merge(VALUE self, VALUE base, VALUE key, VALUE value) {
  picojson::value v;
  std::string err;
  const char* json = StringValuePtr(base);
  const char* json_end = picojson::parse(v, json, json + strlen(json), &err);
  if (!err.empty()) {
    std::cerr << err << std::endl;
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
  //rb_define_alloc_func(rb_cPicojsonRuby, allocate);
  rb_define_singleton_method(rb_cPicojsonRuby, "merge_json", RUBY_METHOD_FUNC(rb_picojson_merge), 3);
}
