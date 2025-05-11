#!/usr/bin/env bash

INTERFACE=${INTERFACE:-virbr0}
nmap $(ip a show $INTERFACE | grep inet | xargs echo | cut -d' ' -f2)
