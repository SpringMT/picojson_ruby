require "bundler/gem_tasks"

require "rake/extensiontask"

task :build => :compile

Rake::ExtensionTask.new("picojson_ruby") do |ext|
  ext.lib_dir = "lib/picojson_ruby"
end
