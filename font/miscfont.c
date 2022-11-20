/*******************************************************************************
 * Size: 15 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#include "lvgl.h"


#ifndef MISCFONT
#define MISCFONT 1
#endif

#if MISCFONT

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002D "-" */
    0xf0,

    /* U+0030 "0" */
    0x38, 0x8b, 0x1c, 0x18, 0x30, 0x60, 0xc1, 0xc6,
    0x88, 0xe0,

    /* U+0031 "1" */
    0x74, 0x92, 0x49, 0x24, 0x80,

    /* U+0032 "2" */
    0x38, 0x8a, 0xc, 0x10, 0x20, 0x82, 0x8, 0x20,
    0x83, 0xf8,

    /* U+0033 "3" */
    0x7d, 0x8e, 0x8, 0x31, 0x80, 0x80, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+0034 "4" */
    0x2, 0x3, 0x2, 0x83, 0x43, 0x21, 0x11, 0x9,
    0xff, 0x2, 0x1, 0x0, 0x80,

    /* U+0035 "5" */
    0x7e, 0x40, 0x40, 0x40, 0x7c, 0x2, 0x1, 0x81,
    0x81, 0x42, 0x3c,

    /* U+0036 "6" */
    0x8, 0x30, 0x41, 0x7, 0x88, 0xa0, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+0037 "7" */
    0xfe, 0xc, 0x10, 0x60, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x0,

    /* U+0038 "8" */
    0x38, 0x89, 0x12, 0x23, 0x88, 0xa0, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+0039 "9" */
    0x3d, 0x8e, 0xc, 0x1c, 0x6f, 0x82, 0xc, 0x10,
    0x41, 0x80,

    /* U+0043 "C" */
    0x1f, 0xc, 0x34, 0x3, 0x0, 0x80, 0x20, 0x8,
    0x3, 0x0, 0x40, 0xc, 0x31, 0xf0,

    /* U+0048 "H" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0x7f, 0xf8,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+004F "O" */
    0x1f, 0x83, 0xc, 0x40, 0x28, 0x1, 0x80, 0x18,
    0x1, 0x80, 0x18, 0x3, 0x40, 0x23, 0xc, 0x1f,
    0x80,

    /* U+0054 "T" */
    0xff, 0xc2, 0x0, 0x80, 0x20, 0x8, 0x2, 0x0,
    0x80, 0x20, 0x8, 0x2, 0x0, 0x80,

    /* U+0056 "V" */
    0x80, 0x48, 0x9, 0x3, 0x10, 0x42, 0x18, 0x62,
    0x4, 0x40, 0xd0, 0xa, 0x1, 0x80, 0x10, 0x0,

    /* U+0061 "a" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3d,

    /* U+0064 "d" */
    0x1, 0x1, 0x1, 0x3d, 0x43, 0x81, 0x81, 0x81,
    0x81, 0x42, 0x3c,

    /* U+0065 "e" */
    0x3c, 0x42, 0x81, 0xff, 0x80, 0x80, 0x42, 0x3c,

    /* U+0069 "i" */
    0x9f, 0xe0,

    /* U+006D "m" */
    0xb9, 0xec, 0xe3, 0x84, 0x18, 0x41, 0x84, 0x18,
    0x41, 0x84, 0x18, 0x41,

    /* U+0070 "p" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0xc2, 0xbc,
    0x80, 0x80, 0x80,

    /* U+0072 "r" */
    0xbe, 0x21, 0x8, 0x42, 0x10,

    /* U+0074 "t" */
    0x20, 0x82, 0x3e, 0x20, 0x82, 0x8, 0x20, 0x81,
    0xc0,

    /* U+0075 "u" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3d,

    /* U+0079 "y" */
    0x0, 0x81, 0x43, 0x42, 0x26, 0x24, 0x1c, 0x18,
    0x18, 0x10, 0x10, 0x20,

    /* U+00B0 "°" */
    0x7b, 0x38, 0x61, 0xcd, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 94, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 1, .adv_w = 137, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 91, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 26, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 155, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 49, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 60, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 136, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 184, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 203, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 221, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 157, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 172, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 175, .adv_w = 162, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 170, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 147, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 69, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 227, .box_w = 12, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 216, .adv_w = 170, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 227, .adv_w = 110, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 96, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 162, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 132, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 261, .adv_w = 113, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9,
    0xa, 0xb, 0xc, 0x16, 0x1b, 0x22, 0x27, 0x29,
    0x34, 0x37, 0x38, 0x3c, 0x40, 0x43, 0x45, 0x47,
    0x48, 0x4c, 0x83
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 45, .range_length = 132, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 27, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    1, 4,
    1, 9,
    1, 12,
    1, 14,
    1, 15,
    1, 16,
    1, 17,
    1, 18,
    1, 19,
    2, 3,
    2, 9,
    4, 17,
    4, 18,
    4, 19,
    5, 9,
    6, 7,
    8, 9,
    9, 1,
    9, 2,
    9, 5,
    9, 6,
    9, 8,
    9, 10,
    9, 12,
    9, 14,
    9, 17,
    9, 18,
    9, 19,
    10, 9,
    10, 11,
    11, 6,
    11, 12,
    11, 14,
    12, 17,
    12, 18,
    12, 19,
    14, 9,
    14, 10,
    14, 12,
    14, 14,
    14, 15,
    14, 16,
    14, 27,
    15, 1,
    15, 12,
    15, 14,
    15, 17,
    15, 18,
    15, 19,
    15, 20,
    15, 21,
    15, 22,
    15, 23,
    15, 24,
    15, 25,
    15, 26,
    16, 1,
    16, 12,
    16, 14,
    16, 15,
    16, 17,
    16, 18,
    16, 19,
    16, 21,
    16, 22,
    16, 23,
    16, 25,
    16, 26,
    17, 15,
    18, 15,
    19, 15,
    19, 17,
    19, 18,
    19, 19,
    21, 15,
    22, 9,
    22, 15,
    22, 26,
    23, 17,
    23, 18,
    23, 19,
    25, 15,
    25, 27,
    26, 12,
    26, 14,
    26, 15,
    26, 17,
    26, 18,
    26, 19
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -12, -10, -7, -7, -26, -22, -2, -2,
    -2, -10, -14, -10, -10, -10, -10, -12,
    -10, -24, -5, -17, -22, -24, -12, -14,
    -14, -26, -26, -26, -10, -10, -14, -12,
    -12, -10, -10, -10, -12, -10, -5, -5,
    -14, -2, -5, -31, -12, -12, -36, -36,
    -36, -2, -34, -34, -34, -14, -36, -26,
    -19, -12, -12, 5, -26, -26, -26, -17,
    -17, -17, -14, -10, -29, -29, -36, -5,
    -5, -5, -29, -14, -34, -7, -10, -10,
    -10, -34, -19, -2, -2, -22, -5, -5,
    -5
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 89,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t miscfont = {
#else
lv_font_t miscfont = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if MISCFONT*/

