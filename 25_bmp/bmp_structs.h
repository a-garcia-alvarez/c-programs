#define WORD	unsigned int16_t
#define DWORD 	unsigned int32_t
#define LONG 	int32_t
#define BI_RGB 	0
#define BI_RLE8 	1
#define BI_RLE4 	2
#define BI_BITFIELDS 	3
#define (Huffman 1D) 	3
#define BI_JPEG 	4
#define (24-bit RLE) 	4
#define BI_PNG 	5
#define BI_ALPHABITFIELDS 	6
#define BI_SRCPREROTATE 	0x8000 (?)
#define LCS_CALIBRATED_RGB 	0
#define LCS_sRGB 	'sRGB' = 0x73524742
#define LCS_WINDOWS_COLOR_SPACE 	'Win ' = 0x57696e20
#define PROFILE_LINKED 	'LINK' = 0x4c494e4b
#define PROFILE_EMBEDDED 	'MBED' = 0x4d424544
#define LCS_GM_BUSINESS 	1
#define LCS_GM_GRAPHICS 	2
#define LCS_GM_IMAGES 	4
#define LCS_GM_ABS_COLORIMETRIC 	8


struct BITMAPFILEHEADER {
    char magic[2];              // 'B' 'M'
    int32_t file_size;
    int16_t reserved[2];
    int32_t offset;            // offset to bitmap data, relative to start of file
} BITMAPFILEHEADER;


struct BITMAPCOREHEADER {
    int32_t header_size;       // 12
    int16_t width;
    int16_t height;
    int16_t planes;            // 1
    int16_t bits_per_pixel;    // must be 1, 4, 8 or 24
} BITMAPCOREHEADER;

typedef struct {
    DWORD bc2Size;
    DWORD bc2Width;
    DWORD bc2Height;
    WORD  bc2Planes;
    WORD  bc2BitCount;
    DWORD bc2Compression;
    DWORD bc2SizeImage;
    DWORD bc2XRes;
    DWORD bc2YRes;
    DWORD bc2ClrUsed;
    DWORD bc2ClrImportant;
    /* same as BITMAPINFOHEADER until this point */
    WORD  bc2ResUnit;
    WORD  bc2Reserved;
    WORD  bc2Orientation;
    WORD  bc2Halftoning;
    DWORD bc2HalftoneSize1;
    DWORD bc2HalftoneSize2;
    DWORD bc2ColorSpace;
    DWORD bc2AppData;
} BITMAPCOREHEADER2;


typedef struct {
  DWORD biSize;
  LONG  biWidth;
  LONG  biHeight;
  WORD  biPlanes;
  WORD  biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG  biXPelsPerMeter;
  LONG  biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
  DWORD Size              // Size of this header in bytes
  LONG  Width             // Image width in pixels
  LONG  Height            // Image height in pixels
  WORD  Planes            // Number of color planes
  WORD  BitsPerPixel      // Number of bits per pixel
  DWORD Compression       // Compression methods used
  DWORD SizeOfBitmap      // Size of bitmap in bytes
  LONG  HorzResolution    // Horizontal resolution in pixels per meter
  LONG  VertResolution    // Vertical resolution in pixels per meter
  DWORD ColorsUsed        // Number of colors in the image
  DWORD ColorsImportant   // Minimum number of important colors
} BITMAPINFOHEADER;


typedef struct {
  DWORD biSize;
  LONG  biWidth;
  LONG  biHeight;
  WORD  biPlanes;
  WORD  biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG  biXPelsPerMeter;
  LONG  biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
  
} BITMAPV2INFOHEADER;

typedef struct {
  DWORD Size              // Size of this header in bytes
  LONG  Width             // Image width in pixels
  LONG  Height            // Image height in pixels
  WORD  Planes            // Number of color planes
  WORD  BitsPerPixel      // Number of bits per pixel
  DWORD Compression       // Compression methods used
  DWORD SizeOfBitmap      // Size of bitmap in bytes
  LONG  HorzResolution    // Horizontal resolution in pixels per meter
  LONG  VertResolution    // Vertical resolution in pixels per meter
  DWORD ColorsUsed        // Number of colors in the image
  DWORD ColorsImportant   // Minimum number of important colors
        //    - BITMAPINFOHEADER ends here -
  DWORD RedMask           // Mask identifying bits of red component
  DWORD GreenMask         // Mask identifying bits of green component
  DWORD BlueMask          // Mask identifying bits of blue component
} BITMAPV2INFOHEADER;

typedef struct {
    DWOR DbiSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount
    DWOR DbiCompression;
    DWOR DbiSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWOR DbiClrUsed;
    DWOR DbiClrImportant;
} BITMAPINFOHEADER_W5;

typedef struct {
  DWORD        bV4Size;
  LONG         bV4Width;
  LONG         bV4Height;
  WORD         bV4Planes;
  WORD         bV4BitCount;
  DWORD        bV4V4Compression;
  DWORD        bV4SizeImage;
  LONG         bV4XPelsPerMeter;
  LONG         bV4YPelsPerMeter;
  DWORD        bV4ClrUsed;
  DWORD        bV4ClrImportant;
  DWORD        bV4RedMask;
  DWORD        bV4GreenMask;
  DWORD        bV4BlueMask;
  DWORD        bV4AlphaMask;
  DWORD        bV4CSType;
  CIEXYZTRIPLE bV4Endpoints;
  DWORD        bV4GammaRed;
  DWORD        bV4GammaGreen;
  DWORD        bV4GammaBlue;
} BITMAPV4HEADER;

typedef struct {
  DWORD        bV5Size;
  LONG         bV5Width;
  LONG         bV5Height;
  WORD         bV5Planes;
  WORD         bV5BitCount;
  DWORD        bV5Compression;
  DWORD        bV5SizeImage;
  LONG         bV5XPelsPerMeter;
  LONG         bV5YPelsPerMeter;
  DWORD        bV5ClrUsed;
  DWORD        bV5ClrImportant;
  DWORD        bV5RedMask;
  DWORD        bV5GreenMask;
  DWORD        bV5BlueMask;
  DWORD        bV5AlphaMask;
  DWORD        bV5CSType;
  CIEXYZTRIPLE bV5Endpoints;
  DWORD        bV5GammaRed;
  DWORD        bV5GammaGreen;
  DWORD        bV5GammaBlue;
  DWORD        bV5Intent;
  DWORD        bV5ProfileData;
  DWORD        bV5ProfileSize;
  DWORD        bV5Reserved;
} BITMAPV5HEADER;

