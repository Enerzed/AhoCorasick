/*
* AhoCorasick.h
*/


#pragma once


#include "postgres.h"
#include "fmgr.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>


#define STATE_GET(ahocorasick, state) ((ahocorasick)->state_array[(state)])


typedef struct ahocorasick_state_s 
{
	size_t childs[256];

	size_t *output_array;
	size_t output_array_count;
	size_t output_array_size;
} ahocorasick_state_t;


typedef struct ahocorasick_s 
{
	ahocorasick_state_t *state_array;
	size_t state_array_count;
	size_t state_array_size;
} ahocorasick_t;


typedef struct ahocorasick_match_s 
{
	const char *input;
	size_t len;

	size_t state;
	size_t output;
} ahocorasick_match_t;


bool ahocorasick_init(ahocorasick_t *ahocorasick);
bool ahocorasick_add_keyword(ahocorasick_t *ahocorasick, const char *str, size_t len, size_t output);
bool ahocorasick_finalize(ahocorasick_t *ahocorasick);
bool ahocorasick_match_init(ahocorasick_match_t *match, const char *input, size_t len);
bool ahocorasick_match(ahocorasick_t *ahocorasick, ahocorasick_match_t *match, size_t *output);
bool ahocorasick_clean(ahocorasick_t *ahocorasick);

bool ahocorasick_to_dot(ahocorasick_t *ahocorasick, FILE *f);
size_t ahocorasick_size(ahocorasick_t *ahocorasick);