/*
 * ringbuffer.h
 *
 *  Created on: 18 lis 2022
 *      Author: gerwant22
 */

#ifndef INC_RING_BUFFER_H_
#define INC_RING_BUFFER_H_

#define RING_BUFFER_SIZE 16
// Success status

typedef enum
{
    RB_OK = 0,
    RB_ERROR = 1

} RB_Status;

// Oject ring buffer

typedef struct
{

    uint16_t Head;
    uint16_t Tail;

    uint8_t Buffer[RING_BUFFER_SIZE];

} RingBuffer_t;

// Functions
// Write
RB_Status RB_Write(RingBuffer_t *Buf, uint8_t Value);
// Read
RB_Status RB_Read(RingBuffer_t *Buf, uint8_t *Value);
// Flush
void RB_Flush(RingBuffer_t *Buf);
#endif /* INC_RING_BUFFER_H_ */
