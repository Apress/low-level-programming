#include <stdint.h>
#include <stdio.h>

struct pixel { uint8_t b,g,r; };

struct image {
    uint64_t width, height;
    struct pixel_t* data;
};

/*  deserializer  */
enum read_status {
    READ_OK = 0, 
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
        /* more codes  */
};

enum read_status from_bmp( FILE* in, struct image* const read );

/*  image_t from_jpg( FILE* );...
 *  and other deserializers are possible
 *  All information needed will be 
 *  stored in image structure */

/* makes a rotated copy */
struct image rotate( struct image const source );


/*  serializer  */
enum write_status {
    WRITE_OK = 0, 
    WRITE_ERROR
        /* more codes  */
};

enum write_status to_bmp( FILE* out, struct image const* img );
