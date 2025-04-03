#!/usr/bin/env bash

set -eou pipefail

squser="laurie@borntosec.net"
sqpass='!q\]Ej?*5K5cy*AJ'

curl -s -k -D /tmp/sqdata -d"login_username=$squser&secretkey=$sqpass&js_autodetect_results=1&just_logged_in=1" $URL/src/redirect.php | tee login | grep -q incorrect
if [ $? -eq 0 ]; then
	echo "Invalid creds"
	exit 2
fi

sessid="`cat /tmp/sqdata | grep SQMSESS | tail -n1 | cut -d'=' -f2 | cut -d';' -f1`"
keyid="`cat /tmp/sqdata | grep key | tail -n1 | cut -d'=' -f2 | cut -d';' -f1`"

echo sessid=$sessid
echo keyid=$keyid
