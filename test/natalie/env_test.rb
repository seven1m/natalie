require_relative '../spec_helper'

describe 'ENV' do
  describe '#inspect' do
    it 'returns ENV as a hash representation' do
      match = ENV.inspect =~ /^\{.+\}/
      match.should == 0
    end
  end

  describe '[]' do
    it 'returns an environment variable by name' do
      ENV['PATH'].should_not be_nil
    end

    it 'returns nil when the environment variable does not exist' do
      ENV['NATALIE_TEST_ENV_SOMETHING_BOGUS'].should be_nil
    end
  end

  describe '[]=' do
    it 'sets an environment variable by name' do
      ENV['NATALIE_TEST_ENV'] = 'hello world'
      ENV['NATALIE_TEST_ENV'].should == 'hello world'
    end
  end
end
