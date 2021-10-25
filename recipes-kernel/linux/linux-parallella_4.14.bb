LINUX_VERSION = "4.14"
KBRANCH = "parallella-linux-2019.1"
SRCREV = "9d28f3d25f4c5273b8709df906e0be17861aee77"

include linux-parallella.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/linux-parallella/4.14:"

SRC_URI_append = " \
    file://0001-scripts-dtc-Remove-redundant-YYLOC-global-declaration.patch \
    "

# TODO: Add these back if necessary
## add the drivers necessary with SRCREV eb7c3a1
#SRC_URI_append = " \
#	file://0001-dma-proof-concept-pl330.patch \
#	file://0002-dmaengine-commit-6906086.patch \
#	file://0003-dmaengine-commit-0c400db.patch \
#	file://0004-dma-commit-23ef060.patch \
#	file://0005-dma-proof-concept-xilinx-dma.patch \
#	file://0006-drm-proof-concept-adi_axi_hdmi.patch \
#	file://0007-clk-axi-clkgen-proof-concept.patch \
#	file://0008-Sound-SPDIF-DAI-commit-80336ab.patch \
#	file://0009-ASoC-commit-7e44b46.patch \
#	file://0010-Sound-proof-concept-add-adv7511_hdmi.patch \
#	"
#
## add the device tree patches necessary with SRCREV eb7c3a1
#SRC_URI_append = " \
#	file://0012-HDMI-device-tree.patch \
#	"
#
## add the epiphany driver patch necessary with SRCREV eb7c3a1
#SRC_URI_append = " \
#	file://0011-Cache-elink-rxcfg-reg.patch \
#	"
#
