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
  picojson::object &obj = v.get<picojson::object>();

  switch (TYPE(value)) {
    case T_FIXNUM:
      obj.insert(std::map<std::string, double>::value_type(inserting_key, FIX2INT(value)));
      break;
    case T_STRING:
      obj.insert(std::make_pair(inserting_key, StringValuePtr(value)));
      break;
    default:
      /* 例外を発生させる */
      rb_raise(rb_eTypeError, "not valid value");
      break;
  }
  std::string new_json = v.serialize();
  const char* new_json_char = new_json.c_str();
  return rb_str_new(new_json_char, strlen(new_json_char));
}

extern "C" void
Init_picojson_ruby(void)
{
  rb_cPicojsonRuby = rb_define_class("PicojsonRuby", rb_cObject);
  rb_define_singleton_method(rb_cPicojsonRuby, "append", RUBY_METHOD_FUNC(rb_picojson_merge), 3);
}
