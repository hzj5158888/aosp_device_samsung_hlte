$(call inherit-product, device/samsung/hlte/device.mk)

# Enhanced NFC
#$(call inherit-product, vendor/du/config/nfc_enhanced.mk)

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)

PRODUCT_DEVICE := hlte
PRODUCT_NAME := aosp_hlte
