/*
 * parser_simple.c
 *
 *  Created on: 18 lis 2022
 *      Author: gerwant22
 */
#include "main.h"
#include "ring_buffer.h"
#include "parser_simple.h"
#include "utils.h"
#include "string.h"

void Parser_TakeLine(RingBuffer_t *Buf, uint8_t *Destination)
{
    uint8_t Tmp;
    uint8_t i = 0;
    do
    {
        RB_Read(Buf, &Tmp);
        if (Tmp == ENDLINE)
        {
            Destination[i] = 0;
        }
        else
        {
            Destination[i] = Tmp;
        }

        i++;
    } while (Tmp != ENDLINE);
}

// LED=
//      0
//      1

static void Parse_ParseLED()
{
    // String to parse:
    // 0
    // 1

    char *ParsePointer = strtok(NULL, ",");
    if (strlen(ParsePointer) > 0)
    {
        if (ParsePointer[0] < '0' || ParsePointer[0] > '1')
        {
            UartLog("LED wrong value. Please type 0 or 1!\n\r");
            return;
        }

        if (ParsePointer[0] == '1')
        {
            HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
            UartLog("LED turned on!\n\r");
        }
        else if (ParsePointer[0] == '0')
        {
            HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
            UartLog("LED turned off!\n\r");
        }
    }
}

void Parser_Parse(uint8_t *DataToParse)
{

    char *ParsePointer = strtok((char *)DataToParse, "=");

    // LED
    if (strcmp("LED", ParsePointer) == 0)
    {
        Parse_ParseLED();
    }
}