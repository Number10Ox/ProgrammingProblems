#include "Blit.h"

__attribute__((visibility("default")))
void blit(const PixelBuffer* dest, const PixelBuffer* src, const int offsetX, const int offsetY)
{
	const int srcWidth = src->width;
	const int srcHeight = src->height;
	const int destWidth = dest->width;
	const int destHeight = dest->height;

	int destX = 0;
	int destY = 0;
	for (int srcY = offsetY; srcY < srcHeight; ++srcY, ++destY)
	{
		if (destY >= destHeight)
		{
			break;
		}
		for (int srcX = offsetX; srcX < srcWidth; ++srcX, ++destX)
		{
			if (destX >= destWidth)
			{
				break;
			}
			const uint32_t pixel = src->pixels[srcY * srcWidth + srcX];
			if (pixel != COLOR_KEY)
			{
				dest->pixels[destY * destWidth + destX] = pixel;
			}
		}
	}
}
