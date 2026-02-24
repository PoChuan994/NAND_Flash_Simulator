/* This file defines the abstraction of NAND flash memory */

#ifndef NAND_FLASH_H
#define NAND_FLASH_H

#include <stdint.h>
#include <stdbool.h>

#define PAGE_SIZE      4096    // 4KB per page
#define PAGES_PER_BLOCK  64    // pages per block
#define BLOCKS_TOTAL    1024   // total blocks

// Optional features:
// 1. ECC/error flag: Add ECC field or error flag in Page struct if needed
// 2. OP space: Usually block-based, convenient for GC and wear leveling management
// 3. Statistics: erase/write/read counters are recommended in NandFlash struct (hardware abstraction)
// 4. Multi-channel/multi-chip: Can wrap NandFlash with Channel/Chip struct for advanced simulation

typedef enum {
	PAGE_FREE = 0,
	PAGE_VALID,
	PAGE_INVALID
} page_status_t;

typedef struct {
	uint8_t  data[PAGE_SIZE];
	page_status_t status;
	// Optional: ECC/error flag can be added here, e.g., uint8_t ecc; or bool has_error;
} Page;

typedef struct {
	Page pages[PAGES_PER_BLOCK];
	uint32_t wear_count;
	bool is_op_block; // Over-Provision block flag (OP is usually block-based)
	// Optional: Add other block status flags if needed
} Block;

typedef struct {
	Block blocks[BLOCKS_TOTAL];

	// Statistics (recommended at NandFlash level, corresponds to hardware abstraction)
	uint64_t total_erase_count;
	uint64_t total_write_count;
	uint64_t total_read_count;

	// Optional: For multi-channel/multi-chip support, wrap with Channel/Chip struct
} NandFlash;

// NAND Flash API
void nand_init(NandFlash *nand);
bool nand_read_page(NandFlash *nand, uint32_t block, uint32_t page, uint8_t *buffer);
bool nand_write_page(NandFlash *nand, uint32_t block, uint32_t page, const uint8_t *data);
bool nand_erase_block(NandFlash *nand, uint32_t block);

#endif // NAND_FLASH_H