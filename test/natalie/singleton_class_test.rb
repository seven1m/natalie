require_relative '../spec_helper'

class Foo
end

class Bar < Foo
end

describe 'singleton_class' do
  it 'has the correct hierarchy' do
    klass = Bar.singleton_class
    klass.inspect.should == '#<Class:Bar>'
    klass = klass.superclass
    klass.inspect.should == '#<Class:Foo>'
    klass = klass.superclass
    klass.inspect.should == '#<Class:Object>'
    klass = klass.superclass
    klass.inspect.should == '#<Class:BasicObject>'
    klass = klass.superclass
    klass.should == Class
    klass = klass.superclass
    klass.should == Module
    klass = klass.superclass
    klass.should == Object
    klass = klass.superclass
    klass.should == BasicObject
    klass = klass.superclass
    klass.should == nil

    klass = Class.singleton_class
    klass.inspect.should == '#<Class:Class>'
    klass = klass.superclass
    klass.inspect.should == '#<Class:Module>'
    klass = klass.superclass
    klass.inspect.should == '#<Class:Object>'
    klass = klass.superclass
    klass.inspect.should == '#<Class:BasicObject>'
    klass = klass.superclass
    klass.should == Class
  end

  it 'knows it is a singleton class' do
    Bar.singleton_class.singleton_class?.should == true
    Bar.singleton_class?.should == false
  end
end
