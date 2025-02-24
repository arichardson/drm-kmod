/*
 * Copyright 2017 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Christian König
 */
#ifndef __AMDGPU_MN_H__
#define __AMDGPU_MN_H__

#include <linux/types.h>
#ifdef __linux__
#include <linux/hmm.h>
#include <linux/rwsem.h>
#endif
#include <linux/workqueue.h>
#include <linux/interval_tree.h>

#if defined(CONFIG_HMM_MIRROR)
int amdgpu_mn_register(struct amdgpu_bo *bo, unsigned long addr);
void amdgpu_mn_unregister(struct amdgpu_bo *bo);
#else
static inline int amdgpu_mn_register(struct amdgpu_bo *bo, unsigned long addr)
{
	DRM_WARN_ONCE("HMM_MIRROR kernel config option is not enabled, "
		      "add CONFIG_ZONE_DEVICE=y in config file to fix this\n");
	return -ENODEV;
}
static inline void amdgpu_mn_unregister(struct amdgpu_bo *bo) {}
#endif

#endif
