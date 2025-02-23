// SPDX-License-Identifier: LGPL-2.0-or-later
#ifndef _KBD_LIBKEYMAP_ARRAY_H_
#define _KBD_LIBKEYMAP_ARRAY_H_

#include <sys/param.h>
#include <sys/types.h>

#include <kbd/compiler_attributes.h>

/**
 * @brief Basic structure for array implementation.
 * @details The array is designed to store an arbitrary number of similar items.
 */
struct lk_array {
	char *array KBD_ATTR_NONSTRING;   /**< Data pointer. */
	ssize_t memb;                     /**< One element size. */
	ssize_t count;                    /**< Number of elements. */
	ssize_t total;                    /**< Total number of allocated elements. */
};

int lk_array_init(struct lk_array *a, ssize_t memb, ssize_t size);
int lk_array_free(struct lk_array *a);

int lk_array_empty(struct lk_array *a);

int lk_array_append(struct lk_array *a, const void *e);

int lk_array_set(struct lk_array *a, ssize_t i, const void *e);
void *lk_array_get(struct lk_array *a, ssize_t i);
void *lk_array_get_ptr(struct lk_array *a, ssize_t i);

int lk_array_unset(struct lk_array *a, ssize_t i);
int lk_array_exists(struct lk_array *a, ssize_t i);

#endif /* _KBD_LIBKEYMAP_ARRAY_H_ */
