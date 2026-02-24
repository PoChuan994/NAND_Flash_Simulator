/* Mapping Table abstraction for FTL */

#ifndef MAPPING_TABLE_H
#define MAPPING_TABLE_H

#include <stdint.h>
#include <stdbool.h>

#include "nand_flash.h"


// Physical address as struct for flexibility and maintainability
typedef struct {
	uint32_t block;
	uint32_t page;
} PhysicalAddress;

// Example usage:
// PhysicalAddress addr;
// addr.block = 5;
// addr.page = 3;
// uint32_t block = addr.block;
// uint32_t page = addr.page;

typedef uint32_t LogicalAddress; // Can be extended if needed

// Macro for mapping table size (should match logical space)
#define MAPPING_TABLE_SIZE (BLOCKS_TOTAL * PAGES_PER_BLOCK)

// Mapping entry structure
typedef struct {
	LogicalAddress logical;
	PhysicalAddress physical;
	bool valid;
	uint32_t timestamp;
} MappingEntry;

// Mapping table array
MappingEntry mapping_table[MAPPING_TABLE_SIZE];

#endif // MAPPING_TABLE_H
