include linux-parallella.inc

LINUX_VERSION = "5.10"
KBRANCH = "parallella-linux-2022.1"
SRCREV = "c4a1af3187b0320fd0b87eb3806f0afba352c414"
SRC_URI = "git://github.com/olajep/parallella-linux.git;protocol=https;branch=${KBRANCH}"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}/${LINUX_VERSION}:"

KBUILD_DEFCONFIG = "parallella_defconfig"

KERNEL_DEVICETREE = "zynq-parallella.dtb"
KERNEL_DEVICETREE:parallella = "zynq-parallella-headless.dtb"
KERNEL_DEVICETREE:parallella-hdmi = "zynq-parallella.dtb"
