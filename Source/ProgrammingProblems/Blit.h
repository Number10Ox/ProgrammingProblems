#pragma once

unsigned int const COLOR_KEY{ 0xFF000000 };

struct PixelBuffer {
	uint32_t* pixels;
	int width;
	int height;
};

// NOTE: Here I assume that offset applies to the source, not destination
// Copies pixel data from source into destination starting at offsetX, offsetY.
// Pixels matching the `COLOR_KEY` are transparent and, thus, skipped.
void blit(const PixelBuffer* dest, const PixelBuffer* src, int offsetX, int offsetY);
