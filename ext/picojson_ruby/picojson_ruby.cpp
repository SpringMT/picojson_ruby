#include "picojson_ruby.h"
#include "../../modules/picojson/picojson.h"

VALUE rb_cPicojsonRuby;

static VALUE rb_picojson_merge(VALUE self, VALUE base, VALUE addingObj) {
  picojson::value v;
  std::string err;
  const char* json = StringValuePtr(base);
  picojson::parse(v, json, json + strlen(json), &err);
  if (!err.empty()) {
    rb_raise(rb_eTypeError, err.c_str());
  }

  picojson::object &obj = v.get<picojson::object>();
  switch (TYPE(addingObj)) {
    case T_HASH:
      break;
    default:
      /* 例外を発生させる */
      rb_raise(rb_eTypeError, "not valid value");
      break;
  }
  VALUE ary = rb_funcall(addingObj, rb_intern("to_a"), 0);
  if (TYPE(ary) != T_ARRAY) {
    rb_raise(rb_eTypeError, "Can not execute to_a");
  }

  long i;
  for (i = 0; i < RARRAY_LEN(ary); ++i) {
    VALUE entry = rb_ary_entry(ary, i);
    if (TYPE(entry) != T_ARRAY || RARRAY_LEN(entry) != 2) {
      rb_raise(rb_eTypeError, "Not A Hash");
    }
    VALUE key = rb_ary_entry(entry, 0);
    VALUE val = rb_ary_entry(entry, 1);
    const char* inserting_key = StringValuePtr(key);
    switch (TYPE(val)) {
      case T_FIXNUM:
        obj.insert(std::map<std::string, double>::value_type(inserting_key, FIX2INT(val)));
        break;
      case T_STRING:
        obj.insert(std::make_pair(inserting_key, StringValuePtr(val)));
        break;
      default:
        /* 例外を発生させる */
        rb_raise(rb_eTypeError, "not valid value");
        break;
    }
  }

  std::string new_json = v.serialize();
  const char* new_json_char = new_json.c_str();
  return rb_str_new(new_json_char, strlen(new_json_char));
}

extern "C" void
Init_picojson_ruby(void)
{
  rb_cPicojsonRuby = rb_define_class("PicojsonRuby", rb_cObject);
  rb_define_singleton_method(rb_cPicojsonRuby, "append", RUBY_METHOD_FUNC(rb_picojson_merge), 2);
}
