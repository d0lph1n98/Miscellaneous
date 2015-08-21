#!/bin/bash 
usage() {
    echo "Usage: ./$0 <domain>"
}

if [ -z $1 ]
then
    usage
    exit 1
fi

for i in `curl -s http://download.maxmind.com/download/geoip/database/asnum/GeoIPASNum2.zip | gunzip | cut -d"," -f3 | sed 's/"//g' | sort -u | grep -i $1 | cut -d' ' -f1`
do 
    whois -h whois.radb.net -- '-i origin '"$i"'' | grep -Eo '([0-9.]+){4}/[0-9]+'
done

