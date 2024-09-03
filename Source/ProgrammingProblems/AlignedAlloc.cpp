#include "AlignedAlloc.h"

// Allocates a block of memory with at least `size` bytes available.
// Returned pointer is guaranteed to be aligned on an `alignment` byte boundary.
__attribute__((visibility("default")))
void* AlignedAlloc(size_t size, size_t alignment)
{
	// Need a minimum alignment of word size
	constexpr size_t wordSize = sizeof(void*);
	const size_t clampedAlignment = alignment < wordSize ? wordSize : alignment;

	// Allocate enough for size + adjustedAlignment
	void* alignedAddress = malloc(size + clampedAlignment);

	// Want to advance the address returned to the next 'adjustedAlignment' boundary,
	// whether this address is aligned or not
	void* returnAddress = reinterpret_cast<void*>((reinterpret_cast<size_t>(alignedAddress) + clampedAlignment) & ~(clampedAlignment - 1));

	// Store the address in memory before the allocated address
	*(static_cast<void**>(alignedAddress) - 1) = alignedAddress;
	
	return returnAddress;
}

// Accepts an aligned pointer and releases the correct block of memory.
// Input of nullptr is acceptable and must do nothing.
__attribute__((visibility("default")))
void AlignedFree(void* ptr)
{
	// Retrieve the original pointer stored just before the aligned memory
	void* originalPtr = *(static_cast<void**>(ptr) - 1);
	free(originalPtr);
}
