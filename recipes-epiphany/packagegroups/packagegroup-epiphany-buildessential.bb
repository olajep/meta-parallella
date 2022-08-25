
SUMMARY = "Essential Epiphany build dependencies"
LICENSE = "MIT"

inherit packagegroup

RDEPENDS:packagegroup-epiphany-buildessential = " \
		epiphany-toolchain \
		epiphany-libs \
		epiphany-libs-dev \
		epiphany-bsps \
		"

