/*
*
* BSD 2-Clause License
* 
* Copyright (c) 2018, Taymindis Woon
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 
* * Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
* 
* * Redistributions in binary form must reproduce the above copyright notice,
*   this list of conditions and the following disclaimer in the documentation
*   and/or other materials provided with the distribution.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef LFQUEUE_H
#define LFQUEUE_H

#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef struct lfqueue_cas_node_s {
	void * value;
	struct lfqueue_cas_node_s *next;
} lfqueue_cas_node_t;

typedef struct lfqueue_cas_chain_s {
	lfqueue_cas_node_t *p;
	lfqueue_cas_node_t *next;
} lfqueue_cas_chain_t;

typedef struct {
	lfqueue_cas_node_t *head, *tail;
	size_t size;
	size_t capacity;
	lfqueue_cas_chain_t *chain, *root;
} lfqueue_t;

int   lfqueue_init(lfqueue_t *lfqueue, size_t queue_size);
int   lfqueue_enq(lfqueue_t *lfqueue, void *value);
void *lfqueue_deq(lfqueue_t *lfqueue);
void lfqueue_destroy(lfqueue_t *lfqueue);
size_t lfqueue_size(lfqueue_t *lfqueue);

#ifdef __cplusplus
}
#endif

#endif


