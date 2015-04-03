require "spec_helper"
require "picojson_ruby"

describe PicojsonRuby do
  describe ".append" do
    context 'valid appending string value' do
      subject { PicojsonRuby.append("{}", {"test" => "test"}) }
      it { expect(subject).to eq "{\"test\":\"test\"}" }
    end
    context 'valid appending string value 2' do
      subject { PicojsonRuby.append("{}", {"test" => "1234567890"}) }
      it { expect(subject).to eq "{\"test\":\"1234567890\"}" }
    end
    context 'valid appending string fixnum' do
      subject { PicojsonRuby.append("{}", {"test" => 1234567890}) }
      it { expect(subject).to eq "{\"test\":1234567890}" }
    end
    context 'invalid with Array' do
      subject { PicojsonRuby.append("{}", "test") }
      it { expect { subject }.to raise_error TypeError }
    end
    context 'invalid with invalid json' do
      subject { PicojsonRuby.append("{hoge]", "test") }
      it { expect { subject }.to raise_error TypeError }
    end
  end
end
