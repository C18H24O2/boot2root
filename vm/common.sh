#!/usr/bin/env false

set -euo pipefail

if [ -z "$HOME" ]; then
	echo "ERROR: HOME is not set"
	exit 1
fi

if [ -d "$HOME/sgoinfre" ]; then
	ISO_DIR="$HOME/sgoinfre/isos"
else
	ISO_DIR=${XDG_DATA_HOME:-$HOME/.local/share}/42/isos
fi
mkdir -vp "$ISO_DIR"

ISO="$ISO_DIR/rainfall.iso"
ISO_URL="https://cdn.intra.42.fr/isos/BornToSecHackMe-v1.1.iso"

if [ ! -f "$ISO" ]; then
	echo "Downloading $ISO"
	curl -L -o "$ISO" "$ISO_URL"
fi

echo "To get the machine's IP address, run one of the following:"
echo " ip neigh show"
echo " arp -a"
echo "If those don't work, tough luck."
