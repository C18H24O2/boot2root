#!/usr/bin/env bash

INTERFACE=${INTERFACE:-vboxnet0}
echo "Probing $INTERFACE..."
IP=$(ip a show $INTERFACE | grep inet | xargs echo | cut -d' ' -f2)
echo "Scanning $IP..."
nmap $IP 
