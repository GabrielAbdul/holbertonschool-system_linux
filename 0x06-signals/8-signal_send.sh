#!/usr/bin/env sh
# script that sends SIGQUIT to a process given its PID

if  [ "$#" -ne 1 ];
then
    echo "Usage: $0 <pid>"
    exit 1
fi

kill -QUIT "$1"
