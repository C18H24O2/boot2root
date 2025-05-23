#!/usr/bin/env bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <target>"
    exit 1
fi

nmap -sV -sC -Pn -T4 -p- $1
