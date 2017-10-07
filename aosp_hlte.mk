$(call inherit-product, device/samsung/hlte/full_hlte.mk)

# Inherit from the common Open Source product configuration
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)

PRODUCT_NAME := aosp_hlte
PRODUCT_DEVICE := hlte
PRODUCT_BRAND := Android
PRODUCT_MODEL := AOSP on hlte
PRODUCT_MANUFACTURER := samsung

PRODUCT_PACKAGES += \
    Terminal \
    WallpaperPicker \
    Launcher3
