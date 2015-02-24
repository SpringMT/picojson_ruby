require 'spec_helper'

require 'picojson_ruby'

describe PicojsonRuby do
  context 'merge' do
    subject do
      PicojsonRuby.merge_json("{}", 'test', 'test')
    end
    it do
      p subject
    end
  end
end
