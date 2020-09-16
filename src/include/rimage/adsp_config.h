// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2020 Intel Corporation. All rights reserved.

#include <rimage/rimage.h>
#include <stdbool.h>

int adsp_parse_config(const char *file, struct adsp *out, bool verbose);
int adsp_dump_config(const struct adsp *out, bool verbose);
void adsp_free(struct adsp *adsp);
