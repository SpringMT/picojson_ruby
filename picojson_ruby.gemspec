# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'picojson_ruby/version'

Gem::Specification.new do |spec|
  spec.name          = "picojson_ruby"
  spec.version       = PicojsonRuby::VERSION
  spec.authors       = ["SpringMT"]
  spec.email         = ["today.is.sky.blue.sky@gmail.com"]

  spec.required_rubygems_version = ">= 2.0"

  spec.extensions    = ["ext/picojson_ruby/extconf.rb"]
  spec.summary       = %q{Memory saving JSON merge.}
  spec.description   = %q{Memory saving JSON merge. Using picojson}
  spec.homepage      = "https://github.com/SpringMT/picojson_ruby"
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.7"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rake-compiler"
end
