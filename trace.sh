#!/bin/bash 
usage() {
    echo "Usage: ./$0 <port>"
}

if [ -z $1 ]
then 
    usage
    exit 1
fi

if [ $UID != 0 ]
then
    echo "For more thorough results use root permissions."
fi

cho "List of IPs"
printf "Total\tIP address\n"
netstat -tn 2>/dev/null | grep :$i | awk '{print "\t"$5}' | cut -d: -f1 | sort | uniq -c | sort -nr | head | sed 's/^[ \t]*//'

for i in `netstat -tn 2>/dev/null | grep :$i | awk '{print $5}' | cut -d: -f1 | sort | uniq | sort -nr | head | sed 's/^[ \t]*//'`
do
    echo
    echo "IP Information"
    curl ipinfo.io/$i
    echo
done

