/* Automatically generated nanopb header */
/* Generated by nanopb-0.2.1 at Sun Jun  9 15:04:56 2013. */

#ifndef _PB_NANIM_PB_H_
#define _PB_NANIM_PB_H_
#include <pb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _im_bci_nanim_PixelFormat {
    im_bci_nanim_PixelFormat_RGB_888 = 1,
    im_bci_nanim_PixelFormat_RGBA_8888 = 2
} im_bci_nanim_PixelFormat;

/* Struct definitions */
typedef struct _im_bci_nanim_Animation {
    pb_callback_t name;
    pb_callback_t frames;
} im_bci_nanim_Animation;

typedef struct _im_bci_nanim_Frame {
    pb_callback_t imageName;
    int32_t duration;
    float u1;
    float v1;
    float u2;
    float v2;
} im_bci_nanim_Frame;

typedef struct _im_bci_nanim_Image {
    pb_callback_t name;
    int32_t width;
    int32_t height;
    im_bci_nanim_PixelFormat format;
    pb_callback_t pixels;
} im_bci_nanim_Image;

typedef struct _im_bci_nanim_Nanim {
    pb_callback_t images;
    pb_callback_t animations;
    pb_callback_t author;
    pb_callback_t license;
} im_bci_nanim_Nanim;

/* Default values for struct fields */

/* Struct field encoding specification for nanopb */
extern const pb_field_t im_bci_nanim_Frame_fields[7];
extern const pb_field_t im_bci_nanim_Animation_fields[3];
extern const pb_field_t im_bci_nanim_Image_fields[6];
extern const pb_field_t im_bci_nanim_Nanim_fields[5];

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif