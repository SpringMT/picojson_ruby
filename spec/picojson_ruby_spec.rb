require "spec_helper"
require "picojson_ruby"

describe PicojsonRuby do
  describe ".append" do
    context 'valid' do
      subject { PicojsonRuby.append("{}", "test", "test") }
      it { expect(subject).to eq "{\"test\":\"test\"}" }
    end
    context 'invalid with Array' do
      subject { PicojsonRuby.append("{}", "test", []) }
      it { expect { subject }.to raise_error TypeError }
    end
    context 'invalid with invalid json' do
      subject { PicojsonRuby.append("{test]", "test", "test") }
      it { expect { subject }.to raise_error TypeError }
    end
  end
end
