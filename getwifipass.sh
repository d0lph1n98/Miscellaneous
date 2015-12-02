usage() {
    echo "Usage: sudo ./$0"
}

if [ -z $0 ]
then
    usage 
    exit 1
fi

if [ $UID != 0 ]
then 
    echo "Need root access."
    exit 1
fi

sudo grep -RE "security=|key-mgmt=|psk=" /etc/NetworkManager/system-connections/*
