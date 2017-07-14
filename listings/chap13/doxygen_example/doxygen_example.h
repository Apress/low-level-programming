#pragma once
#include <common.h>
#include <vm.h>

/** @defgroup const_pool Constant pool */

/** Free allocated memory for the pool contents
*/
void const_pool_deinit( struct vm_const_pool* pool );

/** Non-destructive constant pool combination
 * @param a First pool.
 * @param b Second pool.
 * @returns An initialized constant pool combining contents of both arguments
 */
struct vm_const_pool const_combine(
        struct vm_const_pool const* a, 
        struct vm_const_pool const* b );


/** Change the constant pool by adding the other pool's contents in its end.
 * @param[out] src The source pool which will be modified.
 * @param fresh The pool to merge with the `src` pool.
 */
void const_merge( 
        struct vm_const_pool* src, 
        struct vm_const_pool const* fresh );

/**@} */

