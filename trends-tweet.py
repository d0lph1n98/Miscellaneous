#!/usr/bin/python
# -*- coding: utf-8 -*-
import tweepy
from bs4 import BeautifulSoup
import urllib2
import sys

print "Usage: python " + sys.argv[0] + " 'Town, state, country, address, zipcode or landmark' 'Query' 'Page Count' "
places = sys.argv[1]
query = sys.argv[2]
page_count = sys.argv[3]
page = urllib2.urlopen("http://woeid.rosselliot.co.nz/lookup/"+ places)
page = page.read()
parsed = BeautifulSoup(page)
x = parsed.find_all('td')[3].text

consumer_key = ''
consumer_secret = ''
access_token = ''
access_token_secret = ''

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)
trends1 = api.trends_place(x)

data = trends1[0] 
trends = data['trends']
names = [trend['name'] for trend in trends]
trendsName = '\n'.join(names)
print(trendsName)
print "\n"

for tweet in tweepy.Cursor(api.search,q=query,count=page_count,result_type="mixed",).items():   
        print tweet.created_at, tweet.user.screen_name, tweet.text
