#!/bin/bash

# Build an Android kernel that is actually UEFI disguised as the Kernel
cat ./BootShim/AARCH64/BootShim.bin "./Build/idoPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/IDO_UEFI.fd" > "./Build/idoPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/IDO_UEFI.fd-bootshim"||exit 1
gzip -c < "./Build/idoPkg/${_TARGET_BUILD_MODE}_CLANGPDB/FV/IDO_UEFI.fd-bootshim" >./uefi.bin
cat ./uefi.bin ./Resources/DTBs/ido.dtb > ./Mu-ido.img||exit 1


