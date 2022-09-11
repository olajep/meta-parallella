SECTION = "bsp"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${WORKDIR}/LICENSE;md5=a6a9379d3abeee2cd13eef007e9324fd"

PV = "2022.1"
TAG = "parallella-2022.1-rc1"
BASE_URL = "https://github.com/olajep/oh/releases/download/${TAG}"

SRC_URI = "https://raw.githubusercontent.com/olajep/oh/master/LICENSE;name=license"
SRC_URI:append:parallella = " \
    ${BASE_URL}/parallella_e16_headless_gpiose_7010.bit.bin;name=headless-z7010 \
    ${BASE_URL}/parallella_e16_headless_gpiose_7020.bit.bin;name=headless-z7020 \
"
SRC_URI:append:parallella-hdmi = " \
    ${BASE_URL}/parallella_e16_hdmi_gpiose_7010.bit.bin;name=hdmi-z7010 \
    ${BASE_URL}/parallella_e16_hdmi_gpiose_7020.bit.bin;name=hdmi-z7020 \
"

SRC_URI[license.sha256sum]        = "6547723dd941be2cca0b3ea7cc2a9d484de3d3a78b3620062d9538c071317b79"
SRC_URI[headless-z7010.sha256sum] = "02e5ecc3c8586930d0dacb674f161025a6144f8ff2799fb15c5a48bbe0e14924"
SRC_URI[headless-z7020.sha256sum] = "335e8803ba0673fbf6982b876fb2a927fa2586cc59c948720c1e59e49e9c16df"
SRC_URI[hdmi-z7010.sha256sum]     = "4708a5143b86e578bb81f2b2c74831e5992f82c5b41fb48c46f1ddd3a6b38b12"
SRC_URI[hdmi-z7020.sha256sum]     = "d0353244f09049d18a384542f853f3f496c64afdf09c8930af35320f3f950c15"

INHIBIT_DEFAULT_DEPS = "1"
PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit deploy

do_compile() {
	:
}

do_install() {
	:
}

BITSTREAM_PATTERN:parallella = "parallella_*headless_*.bit.bin"
BITSTREAM_PATTERN:parallella-hdmi = "parallella_*hdmi_*.bit.bin"

do_deploy() {
	install -d ${DEPLOYDIR}/bitstreams
	for i in ${WORKDIR}/${BITSTREAM_PATTERN}; do
		install ${i} ${DEPLOYDIR}/bitstreams
	done
}
addtask deploy before do_build after do_install
