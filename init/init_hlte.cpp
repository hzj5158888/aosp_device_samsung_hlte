/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <unistd.h>
#include <stdio.h>

#include <android-base/properties.h>
#include <cutils/properties.h>
#include "vendor_init.h"
#include "log.h"

#include "init_msm8974.h"

using android::base::GetProperty;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void gsm_properties()
{
    property_override("ro.telephony.default_network", "9");
    property_override("telephony.lteOnGsmDevice", "1");
}

void init_target_properties()
{
    std::string platform, bootloader, device, devicename;

    platform = GetProperty("ro.board.platform", "");
    if (platform != ANDROID_TARGET)
        return;

    bootloader = GetProperty("ro.bootloader", "");

    if (bootloader == "N900S") {
        /* hlteskt */
        property_override("ro.build.fingerprint", "samsung/hlteskt/hlte:4.4.2/KOT49H/N900SKSUFNH4:user/release-keys");
        property_override("ro.build.description", "hlteskt-user 4.4.2 KOT49H N900SKSUFNH4 release-keys");
        property_override("ro.product.model", "SM-N900S");
        property_override("ro.product.device", "hlteskt");
        gsm_properties();
    } else if (bootloader == "N900K") {
        /* hltektt */
        property_override("ro.build.fingerprint", "samsung/hltektt/hlte:4.4.2/KOT49H/N900KKKUFNI1:user/release-keys");
        property_override("ro.build.description", "hltektt-user 4.4.2 KOT49H N900KKKUFNI1 release-keys");
        property_override("ro.product.model", "SM-N900K");
        property_override("ro.product.device", "hltektt");
        gsm_properties();
    } else if (bootloader == "N9006") {
        /* hltezh */
        property_override("ro.build.fingerprint", "samsung/hltezh/hlte:4.4.2/KOT49H/N9006ZHUENE6:user/release-keys");
        property_override("ro.build.description", "hltezh-user 4.4.2 KOT49H N9006ZHUENE6 release-keys");
        property_override("ro.product.model", "SM-N9006");
        property_override("ro.product.device", "hltezh");
        gsm_properties();
    } else {
        /* hltezh */
        property_override("ro.build.fingerprint", "samsung/hltezh/hlte:4.4.2/KOT49H/N9006ZHUENE6:user/release-keys");
        property_override("ro.build.description", "hltezh-user 4.4.2 KOT49H N9006ZHUENE6 release-keys");
        property_override("ro.product.model", "SM-N9006");
        property_override("ro.product.device", "hltezh");
        gsm_properties();
    }

    device = GetProperty("ro.product.device", "");
    //strlcpy(devicename, device, sizeof(devicename));
    LOG(INFO) << "Found bootloader id : " << bootloader.c_str() << " setting build properties for " << devicename.c_str() << " devicename\n";
}
