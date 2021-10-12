#ifndef _MCORE_MDATA_H
#define _MCORE_MDATA_H

#include "mcore/mfile.h"

//
// TEXTURE
//

typedef struct mdata_texture_t {
    void *json_val;
    const char *filter;
    const unsigned char *data;
} mdata_texture_t;

void mdata_texture_import(mfile_t *file);
mdata_texture_t *mdata_texture_load(const char *path);
void mdata_texture_free(mdata_texture_t *data);

//
// CONFIG
//

typedef struct mdata_config {
    void *json_val;
} mdata_config_t;

void mdata_config_import(mfile_t *file);
mdata_config_t *mdata_config_load(const char *path);
void mdata_config_free(mdata_config_t *data);

//
// SHADER
//

typedef struct mdata_shader {
    void *json_val;
    const char *glsl300es_fs, *glsl300es_vs; 
    const char *glsl330_fs, *glsl330_vs; 
} mdata_shader_t;

void mdata_shader_import(mfile_t *file);
mdata_shader_t *mdata_shader_load(const char *path);
void mdata_shader_free(mdata_shader_t *data);

//
// FONT
//

typedef struct mdata_font_atlas_char_data {
    float x0, y0, x1, y1;
    float xoff, yoff, xadvance;
} mdata_font_atlas_char_data_t;

typedef struct mdata_font_atlas {
    int bmp_size;
    unsigned char *bmp_data;
    float ascent, descent, linegap, font_size;
    mdata_font_atlas_char_data_t char_data[96];
} mdata_font_atlas_t;

typedef struct mdata_font {
    void *json_val;
    mdata_font_atlas_t atlases[3];
} mdata_font_t;

void mdata_font_import(mfile_t *file);
mdata_texture_t *mdata_font_load(const char *path);
void mdata_font_free(mdata_texture_t *data);

#endif
