#!/usr/bin/env bash

INTERFACE=${INTERFACE:-vboxnet0}
echo "Probing $INTERFACE..."
IP=$(ip a show $INTERFACE | grep inet | xargs echo | cut -d' ' -f2)
echo "Scanning $IP..."
VM_IP=$(nmap $IP 2>&1 | grep "^Nmap scan report for" | head -2 | tail -1 | cut -d' ' -f5)
echo "VM IP: $VM_IP" 
echo -n $VM_IP | xclip -selection clipboard
echo "Copied to clipboard."
