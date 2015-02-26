# PicojsonRuby

Memory saving JSON merge for Ruby.

Using picojson parsing JSON.

[kazuho / picojson](https://github.com/kazuho/picojson)


## Installation

Add this line to your application's Gemfile:

```ruby
gem 'picojson_ruby'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install picojson_ruby

## Usage

### append
Add JSON for one item.

```
p PicojsonRuby.append("{}", "key", "value")
# => "{\"key\":\"value\"}"
```

## Contributing

1. Fork it ( https://github.com/[my-github-username]/picojson_ruby/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request
