SUMMARY = "Parallella Kernel"

# This version extension should match CONFIG_LOCALVERSION in defconfig
LINUX_VERSION_EXTENSION ?= "-parallella"
PV = "${LINUX_VERSION}${LINUX_VERSION_EXTENSION}+git${SRCPV}"

KBRANCH ?= "parallella-linux-2016.3"

# Default linux-parallella source
SRC_URI = "git://github.com/parallella/parallella-linux.git;protocol=https;branch=${KBRANCH}"

# add config fragments
FILESEXTRAPATHS:prepend := "${THISDIR}/config:"
SRC_URI:append = " \
		file://parallella/parallella.cfg \
		file://parallella/epiphany.cfg \
		file://parallella/extra.cfg \
		file://parallella/hdmi.cfg \
		"

require recipes-kernel/linux/linux-yocto.inc

COMPATIBLE_MACHINE = "^$"
COMPATIBLE_MACHINE:parallella = "parallella"
COMPATIBLE_MACHINE:parallella-hdmi = "parallella-hdmi"

# defconfig is based on multi_v7
KBUILD_DEFCONFIG = "multi_v7_defconfig"
