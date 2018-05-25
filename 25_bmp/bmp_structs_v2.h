#ifndef __BMP_STRUCTS_V2_H__
#define __BMP_STRUCTS_V2_H__

#define WORD   u_int16_t
#define DWORD  u_int32_t
#define SHORT  int16_t
#define LONG   int32_t


// Structs definition

typedef struct{
    char      signature[2];
    unsigned  size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned data_offset;
} BMPHeader;


typedef struct{
    DWORD Size;              // Size of this header in bytes
    SHORT Width;             // Image width in pixels
    SHORT Height;            // Image height in pixels
    WORD  Planes;            // Number of color planes
    WORD  BitsPerPixel;      // Number of bits per pixel

} BITMAPCOREHEADER;

typedef struct{
    DWORD Size;              // Size of this header in bytes
    SHORT Width;             // Image width in pixels
    SHORT Height;            // Image height in pixels
    WORD  Planes;            // Number of color planes
    WORD  BitsPerPixel;      // Number of bits per pixel

    DWORD Compression;       // Bitmap compression scheme
    DWORD ImageDataSize;     // Size of bitmap data in bytes
    DWORD XResolution;       // X resolution of display device
    DWORD YResolution;       // Y resolution of display device
    DWORD ColorsUsed;        // Number of color table indices used
    DWORD ColorsImportant;   // Number of important color indices
    WORD  Units;             // Type of units used to measure resolution
    WORD  Reserved;          // Pad structure to 4-byte boundary
    WORD  Recording;         // Recording algorithm
    WORD  Rendering;         // Halftoning algorithm used
    DWORD Size1;             // Reserved for halftoning algorithm use
    DWORD Size2;             // Reserved for halftoning algorithm use
    DWORD ColorEncoding;     // Color model used in bitmap
    DWORD Identifier;        // Reserved for application use

} BITMAPCOREHEADER2;

typedef struct{
    DWORD Size;              // Size of this header in bytes
    LONG  Width;             // Image width in pixels
    LONG  Height;            // Image height in pixels
    WORD  Planes;            // Number of color planes
    WORD  BitsPerPixel;      // Number of bits per pixel
    DWORD Compression;       // Compression methods used
    DWORD SizeOfBitmap;      // Size of bitmap in bytes
    LONG  HorzResolution;    // Horizontal resolution in pixels per meter
    LONG  VertResolution;    // Vertical resolution in pixels per meter
    DWORD ColorsUsed;        // Number of colors in the image
    DWORD ColorsImportant;   // Minimum number of important colors

} BITMAPINFOHEADER;

typedef struct{
    DWORD Size;              // Size of this header in bytes
    LONG  Width;             // Image width in pixels
    LONG  Height;            // Image height in pixels
    WORD  Planes;            // Number of color planes
    WORD  BitsPerPixel;      // Number of bits per pixel
    DWORD Compression;       // Compression methods used
    DWORD SizeOfBitmap;      // Size of bitmap in bytes
    LONG  HorzResolution;    // Horizontal resolution in pixels per meter
    LONG  VertResolution;    // Vertical resolution in pixels per meter
    DWORD ColorsUsed;        // Number of colors in the image
    DWORD ColorsImportant;   // Minimum number of important colors

    DWORD RedMask;           // Mask identifying bits of red component
    DWORD GreenMask;         // Mask identifying bits of green component
    DWORD BlueMask;          // Mask identifying bits of blue component

} BITMAPV2INFOHEADER;

typedef struct{
    DWORD Size;              // Size of this header in bytes
    LONG  Width;             // Image width in pixels
    LONG  Height;            // Image height in pixels
    WORD  Planes;            // Number of color planes
    WORD  BitsPerPixel;      // Number of bits per pixel
    DWORD Compression;       // Compression methods used
    DWORD SizeOfBitmap;      // Size of bitmap in bytes
    LONG  HorzResolution;    // Horizontal resolution in pixels per meter
    LONG  VertResolution;    // Vertical resolution in pixels per meter
    DWORD ColorsUsed;        // Number of colors in the image
    DWORD ColorsImportant;   // Minimum number of important colors

    DWORD RedMask;           // Mask identifying bits of red component
    DWORD GreenMask;         // Mask identifying bits of green component
    DWORD BlueMask;          // Mask identifying bits of blue component

    DWORD AlphaMask;         // Mask identifying bits of alpha component

} BITMAPV3INFOHEADER;

typedef struct{
    DWORD Size;              // Size of this header in bytes
    LONG  Width;             // Image width in pixels
    LONG  Height;            // Image height in pixels
    WORD  Planes;            // Number of color planes
    WORD  BitsPerPixel;      // Number of bits per pixel
    DWORD Compression;       // Compression methods used
    DWORD SizeOfBitmap;      // Size of bitmap in bytes
    LONG  HorzResolution;    // Horizontal resolution in pixels per meter
    LONG  VertResolution;    // Vertical resolution in pixels per meter
    DWORD ColorsUsed;        // Number of colors in the image
    DWORD ColorsImportant;   // Minimum number of important colors

    DWORD RedMask;           // Mask identifying bits of red component
    DWORD GreenMask;         // Mask identifying bits of green component
    DWORD BlueMask;          // Mask identifying bits of blue component

    DWORD AlphaMask;         // Mask identifying bits of alpha component

    DWORD CSType;            // Color space type
    LONG  RedX;              // X coordinate of red endpoint
    LONG  RedY;              // Y coordinate of red endpoint
    LONG  RedZ;              // Z coordinate of red endpoint
    LONG  GreenX;            // X coordinate of green endpoint
    LONG  GreenY;            // Y coordinate of green endpoint
    LONG  GreenZ;            // Z coordinate of green endpoint
    LONG  BlueX;             // X coordinate of blue endpoint
    LONG  BlueY;             // Y coordinate of blue endpoint
    LONG  BlueZ;             // Z coordinate of blue endpoint
    DWORD GammaRed;          // Gamma red coordinate scale value
    DWORD GammaGreen;        // Gamma green coordinate scale value
    DWORD GammaBlue;         // Gamma blue coordinate scale value

} BITMAPV4HEADER;

typedef struct{
    DWORD Size;              // Size of this header in bytes
    LONG  Width;             // Image width in pixels
    LONG  Height;            // Image height in pixels
    WORD  Planes;            // Number of color planes
    WORD  BitsPerPixel;      // Number of bits per pixel
    DWORD Compression;       // Compression methods used
    DWORD SizeOfBitmap;      // Size of bitmap in bytes
    LONG  HorzResolution;    // Horizontal resolution in pixels per meter
    LONG  VertResolution;    // Vertical resolution in pixels per meter
    DWORD ColorsUsed;        // Number of colors in the image
    DWORD ColorsImportant;   // Minimum number of important colors

    DWORD RedMask;           // Mask identifying bits of red component
    DWORD GreenMask;         // Mask identifying bits of green component
    DWORD BlueMask;          // Mask identifying bits of blue component

    DWORD AlphaMask;         // Mask identifying bits of alpha component

    DWORD CSType;            // Color space type
    LONG  RedX;              // X coordinate of red endpoint
    LONG  RedY;              // Y coordinate of red endpoint
    LONG  RedZ;              // Z coordinate of red endpoint
    LONG  GreenX;            // X coordinate of green endpoint
    LONG  GreenY;            // Y coordinate of green endpoint
    LONG  GreenZ;            // Z coordinate of green endpoint
    LONG  BlueX;             // X coordinate of blue endpoint
    LONG  BlueY;             // Y coordinate of blue endpoint
    LONG  BlueZ;             // Z coordinate of blue endpoint
    DWORD GammaRed;          // Gamma red coordinate scale value
    DWORD GammaGreen;        // Gamma green coordinate scale value
    DWORD GammaBlue;         // Gamma blue coordinate scale value

    DWORD Intent;            // Rendering intent for bitmap
    DWORD ProfileData;       // Offset of the profile data relative to BITMAPV5HEADER
    DWORD ProfileSize;       // Size, in bytes, of embedded profile data
    DWORD Reserved;          // Shall be zero

} BITMAPV5HEADER;


typedef struct{
    DWORD Compression;       // Bitmap compression scheme
    DWORD ImageDataSize;     // Size of bitmap data in bytes
    DWORD XResolution;       // X resolution of display device
    DWORD YResolution;       // Y resolution of display device
    DWORD ColorsUsed;        // Number of color table indices used
    DWORD ColorsImportant;   // Number of important color indices
    WORD  Units;             // Type of units used to measure resolution
    WORD  Reserved;          // Pad structure to 4-byte boundary
    WORD  Recording;         // Recording algorithm
    WORD  Rendering;         // Halftoning algorithm used
    DWORD Size1;             // Reserved for halftoning algorithm use
    DWORD Size2;             // Reserved for halftoning algorithm use
    DWORD ColorEncoding;     // Color model used in bitmap
    DWORD Identifier;        // Reserved for application use
} _BITMAPCOREHEADER2;

typedef struct{
    DWORD RedMask;           // Mask identifying bits of red component
    DWORD GreenMask;         // Mask identifying bits of green component
    DWORD BlueMask;          // Mask identifying bits of blue component
} _BITMAPV2INFOHEADER;


typedef struct{
    DWORD AlphaMask;         // Mask identifying bits of alpha component
} _BITMAPV3INFOHEADER;

typedef struct{
    DWORD CSType;            // Color space type
    LONG  RedX;              // X coordinate of red endpoint
    LONG  RedY;              // Y coordinate of red endpoint
    LONG  RedZ;              // Z coordinate of red endpoint
    LONG  GreenX;            // X coordinate of green endpoint
    LONG  GreenY;            // Y coordinate of green endpoint
    LONG  GreenZ;            // Z coordinate of green endpoint
    LONG  BlueX;             // X coordinate of blue endpoint
    LONG  BlueY;             // Y coordinate of blue endpoint
    LONG  BlueZ;             // Z coordinate of blue endpoint
    DWORD GammaRed;          // Gamma red coordinate scale value
    DWORD GammaGreen;        // Gamma green coordinate scale value
    DWORD GammaBlue;         // Gamma blue coordinate scale value
} _BITMAPV4HEADER;

typedef struct{
    DWORD Intent;            // Rendering intent for bitmap
    DWORD ProfileData;       // Offset of the profile data relative to BITMAPV5HEADER
    DWORD ProfileSize;       // Size, in bytes, of embedded profile data
    DWORD Reserved;          // Shall be zero
} _BITMAPV5HEADER;


// Functions definition

void show_bmp(BMPHeader header) {
    printf("Signature:       %c%c\n",     header.signature[0], header.signature[1]);
    printf("Tamaño:          %i\n",       header.size);
    printf("Datos de imagen: %i (%Xh)\n", header.data_offset, header.data_offset);
}



#endif
