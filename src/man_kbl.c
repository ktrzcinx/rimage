// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2018 Intel Corporation. All rights reserved.

#include <rimage/css.h>
#include <rimage/cse.h>
#include <rimage/plat_auth.h>
#include <rimage/manifest.h>

/*
 * TODO: check if all platform for 1.5 are the same base and length.
 * if yes, define it as HARDWARE_BUFFER_BASE_V1_5, HARDWARE_BUFFER_LEN_v1_5
 * if not, define a platform specific base and length.
 */
#define KBL_HARDWARE_BUFFER_BASE	0xBE500000
#define KBL_HARDWARE_BUFFER_LEN		0x4A000

/* manifest template */
struct fw_image_manifest_v1_5 kbl_manifest = {
	.css_header = {
		.module_type	= MAN_CSS_LT_MODULE_TYPE,
		.header_len	= MAN_CSS_HDR_SIZE,
		.header_version	= MAN_CSS_HDR_VERSION,
		.module_vendor	= MAN_CSS_MOD_VENDOR,
		.size		= 0x800,
		.key_size	= MAN_CSS_KEY_SIZE,
		.modulus_size	= MAN_CSS_MOD_SIZE,
		.exponent_size	= MAN_CSS_EXP_SIZE,
	},

	.desc = {
		.header = {
			.header_id	= SOF_MAN_FW_HDR_ID,
			.header_len	= sizeof(struct sof_man_fw_header),
			.name		= SOF_MAN_FW_HDR_NAME,
			/* size in pages from $CPD */
			.preload_page_count	= 0,
			.fw_image_flags	= SOF_MAN_FW_HDR_FLAGS,
			.feature_mask	= SOF_MAN_FW_HDR_FEATURES,
			.major_version	= 0,
			.minor_version	= 0,
			.hotfix_version	= 0,
			.build_version	= 0,
			.load_offset	= 0,
			.hw_buf_base_addr	= KBL_HARDWARE_BUFFER_BASE,
			.hw_buf_length		= KBL_HARDWARE_BUFFER_LEN
		},
	},
};
