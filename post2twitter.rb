#!/usr/bin/ruby 
require 'twitter'

print "Tweet: "
msg = gets

while true
  begin
    client = Twitter::REST::Client.new do |config|
        config.consumer_key        = ""
	config.consumer_secret     = ""
	config.access_token        = ""
	config.access_token_secret = ""
    end
    client.update(msg)
    puts("Status updated!")
    break
  end
end
