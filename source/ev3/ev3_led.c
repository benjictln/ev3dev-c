
/*  ev3_led.c was generated by yup.py (yupp) 0.7b6
    out of ev3_led.yu-c at 2014-10-01 15:21
 *//**
 *  \file  ev3_led.c (ev3_led.yu-c)
 *  \brief  EV3 LEDs.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#define EV3_LED_IMPLEMENT

#include <string.h>
#include <stdio.h>
#include "ev3.h"
#include "ev3_led.h"

/**
 *  \addtogroup ev3_led
 *  \{
 */

const char * const led_attr_brightness[] = {
	"/sys/class/leds" "/" "ev3:green:left" "/" "brightness",
	"/sys/class/leds" "/" "ev3:green:right" "/" "brightness",
	"/sys/class/leds" "/" "ev3:red:left" "/" "brightness",
	"/sys/class/leds" "/" "ev3:red:right" "/" "brightness",

};

const char * const led_attr_delay_off[] = {
	"/sys/class/leds" "/" "ev3:green:left" "/" "delay_off",
	"/sys/class/leds" "/" "ev3:green:right" "/" "delay_off",
	"/sys/class/leds" "/" "ev3:red:left" "/" "delay_off",
	"/sys/class/leds" "/" "ev3:red:right" "/" "delay_off",

};

const char * const led_attr_delay_on[] = {
	"/sys/class/leds" "/" "ev3:green:left" "/" "delay_on",
	"/sys/class/leds" "/" "ev3:green:right" "/" "delay_on",
	"/sys/class/leds" "/" "ev3:red:left" "/" "delay_on",
	"/sys/class/leds" "/" "ev3:red:right" "/" "delay_on",

};

const char * const led_attr_trigger[] = {
	"/sys/class/leds" "/" "ev3:green:left" "/" "trigger",
	"/sys/class/leds" "/" "ev3:green:right" "/" "trigger",
	"/sys/class/leds" "/" "ev3:red:left" "/" "trigger",
	"/sys/class/leds" "/" "ev3:red:right" "/" "trigger",

};

const char * const led_trigger[] = {
	"none",
	"mmc0",
	"timer",
	"heartbeat",
	"default-on",
	"legoev3-battery-charging-or-full",
	"legoev3-battery-charging",
	"legoev3-battery-full",
	"legoev3-battery-charging-blink-full-solid",
	"phy0rx",
	"phy0tx",
	"phy0assoc",
	"phy0radio",
	"phy0tpt",

	"<unknown>"
};

size_t get_led_brightness( uint8_t id, int *buf )
{
	if ( id >= LED__COUNT_ ) return ( 0 );

	return ev3_read_int( led_attr_brightness[ id ], buf );
}

size_t set_led_brightness( uint8_t id, int value )
{
	if ( id >= LED__COUNT_ ) return ( 0 );

	return ev3_write_int( led_attr_brightness[ id ], value );
}

size_t get_led_delay_off( uint8_t id, int *buf )
{
	if ( id >= LED__COUNT_ ) return ( 0 );

	return ev3_read_int( led_attr_delay_off[ id ], buf );
}

size_t set_led_delay_off( uint8_t id, int value )
{
	if ( id >= LED__COUNT_ ) return ( 0 );

	return ev3_write_int( led_attr_delay_off[ id ], value );
}

size_t get_led_delay_on( uint8_t id, int *buf )
{
	if ( id >= LED__COUNT_ ) return ( 0 );

	return ev3_read_int( led_attr_delay_on[ id ], buf );
}

size_t set_led_delay_on( uint8_t id, int value )
{
	if ( id >= LED__COUNT_ ) return ( 0 );

	return ev3_write_int( led_attr_delay_on[ id ], value );
}

size_t get_led_trigger( uint8_t id, char *buf, size_t sz )
{
	if ( id >= LED__COUNT_ ) return ( 0 );

	return ev3_read_char_array( led_attr_trigger[ id ], buf, sz );
}

size_t set_led_trigger( uint8_t id, char *value )
{
	if ( id >= LED__COUNT_ ) return ( 0 );

	return ev3_write_char_array( led_attr_trigger[ id ], value );
}

size_t set_led_trigger_inx( uint8_t id, uint8_t inx )
{
	return set_led_trigger( id, ( char* ) led_trigger[ inx ]);
}

uint8_t get_led_trigger_inx( uint8_t id )
{
	char buf[ 256 ];
	char *p;
	uint8_t inx = 0;

	if ( !get_led_trigger( id, buf, sizeof( buf ))) return ( TRIGGER__COUNT_ );

	p = strtok( buf, " " );
	while ( p ) {
		if ( *p == '[' ) return ( inx );
		inx++;
		p = strtok( NULL, " " );
	}
	return ( TRIGGER__COUNT_ );
}

/** \} */
