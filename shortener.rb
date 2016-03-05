#!/usr/bin/ruby

#Copyright 2014 otakbeku <d0lph1n98@yahoo.com>

require 'rubygems'
require 'thor'
require 'googl'

class Shorten  < Thor
  desc "shorten", "shorten the url"
  option :url
  def shorten
	client = Googl.client('user@gmail.com', 'password')
	url = options[:url]
	url = Googl.shorten(url)
	puts url.short_url
  end
end
Shorten.start
