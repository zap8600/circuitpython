MCU_SERIES = m4
MCU_VARIANT = nrf52
MCU_SUB_VARIANT = nrf52840
SD ?= s140
SOFTDEV_VERSION ?= 6.0.0

BOOT_SETTING_ADDR = 0xFF000

ifeq ($(SD),)
	LD_FILE = boards/nrf52840_1M_256k.ld
else
	LD_FILE = boards/adafruit_$(MCU_SUB_VARIANT)_$(SD_LOWER)_v$(firstword $(subst ., ,$(SOFTDEV_VERSION))).ld
endif

NRF_DEFINES += -DNRF52840_XXAA
