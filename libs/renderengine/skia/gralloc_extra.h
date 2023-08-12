/*
 * Copyright (C) 2011-2014 MediaTek Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MTK_GRALLOC_EXTRA_H
#define MTK_GRALLOC_EXTRA_H

#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <hardware/gralloc1.h>

__BEGIN_DECLS
enum {
	GRALLOC_EXTRA_OK,
	GRALLOC_EXTRA_UNKNOWN,
	GRALLOC_EXTRA_NOT_SUPPORTED,
	GRALLOC_EXTRA_NO_IMPLEMENTATION,
	GRALLOC_EXTRA_NOT_INIT,
	GRALLOC_EXTRA_INVALIDE_PARAMS,
	GRALLOC_EXTRA_INVALIDE_OPERATION,
	GRALLOC_EXTRA_ERROR,
};
typedef int GRALLOC_EXTRA_RESULT;
typedef enum {
	GRALLOC_EXTRA_GET_ION_FD = 1,
	GRALLOC_EXTRA_GET_SF_INFO = 100,
} GRALLOC_EXTRA_ATTRIBUTE_QUERY;
typedef int (*gralloc_extra_query_handle)(buffer_handle_t, GRALLOC_EXTRA_ATTRIBUTE_QUERY, void *);
#define GRALLOC_EXTRA_MAKE_BIT(start_bit, index)        ( (index##u) << (start_bit) )
#define GRALLOC_EXTRA_MAKE_MASK(start_bit, end_bit)     ( ( ((unsigned int)-1) >> (sizeof(int) * __CHAR_BIT__ - 1 - (end_bit) + (start_bit) ) ) << (start_bit) )
enum {
	GRALLOC_EXTRA_BIT2_VIDEO_PQ_ON      = GRALLOC_EXTRA_MAKE_BIT(19,1),
	GRALLOC_EXTRA_BIT2_VIDEO_PQ_OFF     = GRALLOC_EXTRA_MAKE_BIT(19,0),
	GRALLOC_EXTRA_MASK2_VIDEO_PQ        = GRALLOC_EXTRA_MAKE_MASK(19,19),
};
typedef struct _crop_t {
	int32_t x;
	int32_t y;
	int32_t w;
	int32_t h;
} _crop_t;
typedef struct ge_sf_info_t {
	uint32_t magic;
	_crop_t src_crop;
	_crop_t dst_crop;
	int32_t status;
	int32_t pool_id;
	uint32_t sequence;
	uint32_t secure_handle_hwc;
	uint32_t timestamp;
	int32_t status2;
	int32_t videobuffer_status;
} ge_sf_info_t;
__END_DECLS

#endif /* MTK_GRALLOC_EXTRA_H */
