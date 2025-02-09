DEFAULTTUNE = "cortexa9thf-neon"

MACHINE_EXTRA_RRECOMMENDS += "kernel-modules"

require conf/machine/include/arm/armv7a/tune-cortexa9.inc

MACHINEOVERRIDES =. "parallella-common:"

SERIAL_CONSOLE = "115200 ttyPS0"

MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

# Kernel
KERNEL_IMAGETYPE = "uImage"
KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_ENTRYPOINT}"

# U-Boot
UBOOT_MACHINE= "xilinx_zynq_virt_defconfig"
UBOOT_DEVICE_TREE = "zynq-parallella"
UBOOT_SUFFIX = "img"
UBOOT_ENTRYPOINT = "0x8000"
UBOOT_LOADADDRESS = "0x8000"
SPL_BINARY ?= "spl/boot.bin"

# providers
PREFERRED_PROVIDER_virtual/kernel ?= "linux-parallella"
PREFERRED_PROVIDER_virtual/bootloader ?= "u-boot"

EXTRA_IMAGEDEPENDS += "virtual/bootloader"

IMAGE_FSTYPES ?= "tar.gz cpio.gz.u-boot"

