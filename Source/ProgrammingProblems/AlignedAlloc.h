
// Implements memory allocation and deallocation functions assuming
// * `posix_memalign` / `_aligned_malloc` / etc. do not exist or are unsuitable on the target platform
// * `new` / `delete` / `malloc` / `free` are available and the alignment of `malloc` is 1 byte
// * `size` is always greater than zero
// * `alignment` is a power of two

// Allocates a block of memory with at least `size` bytes available.
// Returned pointer is guaranteed to be aligned on an `alignment` byte boundary.
void* AlignedAlloc(size_t size, size_t alignment);

// Accepts an aligned pointer and releases the correct block of memory.
// Input of nullptr is acceptable and must do nothing.
void AlignedFree(void* ptr);
