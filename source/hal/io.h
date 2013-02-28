// ----------------------------------------------------------------------------
// io.h - MPF - 03/2013
// ----------------------------------------------------------------------------

#ifndef _IO_H_
#define _IO_H_

// enumeration of IO
typedef enum io_enum {
	IO_LED,
	IO_COUNT,
} io_t;

// function prototypes
void io_initialize(void);
void io_set(io_t io);
void io_reset(io_t io);


#endif //_IO_H_
