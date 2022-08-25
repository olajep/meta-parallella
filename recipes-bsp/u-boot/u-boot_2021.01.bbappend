
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:parallella-common = " \
    file://0001-zynq-Add-Adapteva-Parallella-board-support.patch \
    file://0002-ARM-zynq-Add-ps7_init_gpl.c-h-for-Parallella.patch \
    file://0003-HACK-ARM-zynq-Force-MMC-boot-regardless-of-boot-conf.patch \
    "

do_configure:prepend() {
    [ -n "${UBOOT_DEVICE_TREE}" ] && export DEVICE_TREE="${UBOOT_DEVICE_TREE}"
}
#
do_compile:prepend() {
    [ -n "${UBOOT_DEVICE_TREE}" ] && export DEVICE_TREE="${UBOOT_DEVICE_TREE}"
}
#
do_install:prepend() {
    [ -n "${UBOOT_DEVICE_TREE}" ] && export DEVICE_TREE="${UBOOT_DEVICE_TREE}"
}
