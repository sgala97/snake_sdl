#include "funciones.hpp"
Uint32 ColourToUint(int R, int G, int B, int A)
{
	return (Uint32)((A << 24) + (B << 16) + (G << 8) + R);
}

SDL_Colour UintToColour(Uint32 colour)
{
	SDL_Colour tempcol;
	tempcol.a = (colour >> 24) & 0xFF;
	tempcol.b = (colour >> 16) & 0xFF;
	tempcol.g = (colour >> 8) & 0xFF;
	tempcol.r = colour & 0xFF;
	return tempcol;
}