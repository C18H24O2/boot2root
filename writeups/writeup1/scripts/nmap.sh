#!/usr/bin/env bash

nmap $(ip a show vboxnet0 | grep inet | xargs echo | cut -d' ' -f2)
