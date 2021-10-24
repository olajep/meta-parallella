
FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_append_parallella-common = " \
    file://0001-zynq-Add-Adapteva-Parallella-board-support.patch \
    file://0002-ARM-zynq-Add-ps7_init_gpl.c-h-for-Parallella.patch \
    file://0003-HACK-ARM-zynq-Force-MMC-boot-regardless-of-boot-conf.patch \
    "

do_configure_prepend() {
    [ -n "${UBOOT_DEVICE_TREE}" ] && export DEVICE_TREE="${UBOOT_DEVICE_TREE}"
}
#
do_compile_prepend() {
    [ -n "${UBOOT_DEVICE_TREE}" ] && export DEVICE_TREE="${UBOOT_DEVICE_TREE}"
}
#
do_install_prepend() {
    [ -n "${UBOOT_DEVICE_TREE}" ] && export DEVICE_TREE="${UBOOT_DEVICE_TREE}"
}
