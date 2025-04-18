#!/usr/bin/env bash

. $(dirname $0)/common.sh

echo "Running VM"
VM_NAME="boot2root_VM"
VBoxManage unregistervm "$VM_NAME" --delete || true
VBoxManage createvm --name "$VM_NAME" --register
VBoxManage modifyvm "$VM_NAME" --memory 2048 --cpus 2 --ostype Debian --nic1 nat
VBoxManage storagectl "$VM_NAME" --name "IDE Controller" --add ide
VBoxManage storageattach "$VM_NAME" --storagectl "IDE Controller" --port 0 --device 0 --type dvddrive --medium "$ISO"
if [ $# -gt 0 ] && [ "x$1" = "x--internet" ]; then
	:
else
	VBoxManage modifyvm "$VM_NAME" --nic1 hostonly --hostonlyadapter1 vboxnet0 
fi
VBoxManage startvm "$VM_NAME"
