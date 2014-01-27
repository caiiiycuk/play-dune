/* $Id: structure.h 1839 2011-06-20 20:24:26Z truebrain $ */

/** @file src/pool/structure.h %Structure pool definitions. */

#ifndef POOL_STRUCTURE_H
#define POOL_STRUCTURE_H

enum {
	STRUCTURE_INDEX_MAX_SOFT = 79 /* DUNE_2 LIMIT */   + 21,  /*!< The highest possible index for normal Structure. */
	STRUCTURE_INDEX_MAX_HARD = STRUCTURE_INDEX_MAX_SOFT + 3,  /*!< The highest possible index for any Structure. */

	STRUCTURE_INDEX_WALL     = STRUCTURE_INDEX_MAX_SOFT,      /*!< All walls are are put under this index. */
	STRUCTURE_INDEX_SLAB_2x2 = STRUCTURE_INDEX_MAX_SOFT + 1,  /*!< All 2x2 slabs are put under this index. */
	STRUCTURE_INDEX_SLAB_1x1 = STRUCTURE_INDEX_MAX_SOFT + 2,  /*!< All 1x1 slabs are put under this index.*/

	STRUCTURE_INDEX_INVALID  = 0xFFFF
};

struct PoolFindStruct;

extern struct Structure *Structure_Get_ByIndex(uint16 index);
extern struct Structure *Structure_Find(struct PoolFindStruct *find);

extern void Structure_Init();
extern void Structure_Recount();
extern struct Structure *Structure_Allocate(uint16 index, uint8 type);
extern void Structure_Free(struct Structure *s);

#endif /* POOL_STRUCTURE_H */
