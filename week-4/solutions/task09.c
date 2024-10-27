#include <stdio.h>

int main(void)
{
	unsigned char a, b, c;
	scanf("%hhu%hhu%hhu", &a, &b, &c);

	const unsigned char  mask_bit6_bit7 = 0xC0; // 1100 0000
	const unsigned char	      mask_bit7 = 0x80; // 1000 0000
	const unsigned char       mask_bit0 = 0x01; // 0000 0001
	const unsigned char mask_nibble_low = 0x0F; // 0000 1111

	// notice that the encoding functions for the 2nd and the 3rd symbols are self-inverse, but this is not the case for the 1st
	unsigned char decoded_a =
		(a << 2) |						// a5 a4 a3 a2 a1 a0  0  0 |
		((a & mask_bit6_bit7) >> 6);	//  0  0  0  0  0  0 a7 a6
	unsigned char decoded_b =
		(b & ~(mask_bit0 | mask_bit7)) |	//  0 b6 b5 b4 b3 b2 b1  0 |
		((b & mask_bit7) >> 7) |			//  0  0  0  0  0  0  0 b7 |
		(b << 7);							// b0  0  0  0  0  0  0  0
	unsigned char decoded_c = c ^ (mask_nibble_low << 2);

	// assuming that the encoding was correctly done
	// and the type `char` had the same signedness on the machine where the encoding was done
	// otherwise, if `char` cannot represent some ot the values, the result is implementation-defined
	printf("%c%c%c\n", (char)decoded_a, (char)decoded_b, (char)decoded_c);

	return 0;
}

/*
11011000 - 216
11100000 - 224
01001000 - 72
*/

/*
00010010 - 18
11010110 - 214
00001101 - 13
*/
