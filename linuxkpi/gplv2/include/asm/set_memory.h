/*-
 * Copyright (c) 2010 Isilon Systems, Inc.
 * Copyright (c) 2016 Matt Macy (mmacy@nextbsd.org)
 * Copyright (c) 2017 Mellanox Technologies, Ltd.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _ASM_SET_MEMORY_H
#define _ASM_SET_MEMORY_H

#include <linux/page.h>

static inline int
set_memory_uc(unsigned long addr, int numpages)
{
	return (pmap_change_attr(addr, numpages, VM_MEMATTR_UNCACHEABLE));
}

static inline int
set_memory_wc(unsigned long addr, int numpages)
{
	return (pmap_change_attr(addr, numpages, VM_MEMATTR_WRITE_COMBINING));
}

static inline int
set_memory_wb(unsigned long addr, int numpages)
{
	return (pmap_change_attr(addr, numpages, VM_MEMATTR_WRITE_BACK));
}

static inline int
set_pages_uc(vm_page_t page, int numpages)
{
	KASSERT(numpages == 1, ("%s: numpages %d", __func__, numpages));

	pmap_page_set_memattr(page, VM_MEMATTR_UNCACHEABLE);
	return (0);
}

static inline int
set_pages_wc(vm_page_t page, int numpages)
{
	KASSERT(numpages == 1, ("%s: numpages %d", __func__, numpages));

	pmap_page_set_memattr(page, VM_MEMATTR_WRITE_COMBINING);
	return (0);
}

static inline int
set_pages_wb(vm_page_t page, int numpages)
{
	KASSERT(numpages == 1, ("%s: numpages %d", __func__, numpages));

	pmap_page_set_memattr(page, VM_MEMATTR_WRITE_BACK);
	return (0);
}

static inline int
set_pages_array_wb(vm_page_t *pages, int addrinarray)
{
	int i;

	for (i = 0; i < addrinarray; i++)
		set_pages_wb(pages[i], 1);
	return (0);
}

static inline int
set_pages_array_wc(vm_page_t *pages, int addrinarray)
{
	int i;

	for (i = 0; i < addrinarray; i++)
		set_pages_wc(pages[i], 1);
	return (0);
}

static inline int
set_pages_array_uc(vm_page_t *pages, int addrinarray)
{
	int i;

	for (i = 0; i < addrinarray; i++)
		set_pages_uc(pages[i], 1);
	return (0);
}

#endif
