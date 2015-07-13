
/*  ev3_sensor.c was generated by yup.py (yupp) 0.8b7
    out of ev3_sensor.yu-c at 2015-07-13 15:31
 *//**
 *  \file  ev3_sensor.c (ev3_sensor.yu-c)
 *  \brief  EV3 Sensors.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#define EV3_SENSOR_IMPLEMENT

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modp_numtoa.h"
#include "crc32.h"
#include "ev3.h"
#include "ev3_port.h"
#include "ev3_sensor.h"

#define PATH_PREF_LEN  29
#define _ID_SPOT  "///"

#define PATH_BIN_DATA  "/sys/class/lego-sensor/sensor" _ID_SPOT "bin_data"
#define PATH_BIN_DATA_FORMAT  "/sys/class/lego-sensor/sensor" _ID_SPOT "bin_data_format"
#define PATH_COMMAND  "/sys/class/lego-sensor/sensor" _ID_SPOT "command"
#define PATH_COMMANDS  "/sys/class/lego-sensor/sensor" _ID_SPOT "commands"
#define PATH_DIRECT  "/sys/class/lego-sensor/sensor" _ID_SPOT "direct"
#define PATH_DECIMALS  "/sys/class/lego-sensor/sensor" _ID_SPOT "decimals"
#define PATH_DRIVER_NAME  "/sys/class/lego-sensor/sensor" _ID_SPOT "driver_name"
#define PATH_FW_VERSION  "/sys/class/lego-sensor/sensor" _ID_SPOT "fw_version"
#define PATH_MODE  "/sys/class/lego-sensor/sensor" _ID_SPOT "mode"
#define PATH_MODES  "/sys/class/lego-sensor/sensor" _ID_SPOT "modes"
#define PATH_NUM_VALUES  "/sys/class/lego-sensor/sensor" _ID_SPOT "num_values"
#define PATH_POLL_MS  "/sys/class/lego-sensor/sensor" _ID_SPOT "poll_ms"
#define PATH_PORT_NAME  "/sys/class/lego-sensor/sensor" _ID_SPOT "port_name"
#define PATH_UNITS  "/sys/class/lego-sensor/sensor" _ID_SPOT "units"
#define PATH_VALUE0  "/sys/class/lego-sensor/sensor" _ID_SPOT "value0"
#define PATH_VALUE1  "/sys/class/lego-sensor/sensor" _ID_SPOT "value1"
#define PATH_VALUE2  "/sys/class/lego-sensor/sensor" _ID_SPOT "value2"
#define PATH_VALUE3  "/sys/class/lego-sensor/sensor" _ID_SPOT "value3"
#define PATH_VALUE4  "/sys/class/lego-sensor/sensor" _ID_SPOT "value4"
#define PATH_VALUE5  "/sys/class/lego-sensor/sensor" _ID_SPOT "value5"
#define PATH_VALUE6  "/sys/class/lego-sensor/sensor" _ID_SPOT "value6"
#define PATH_VALUE7  "/sys/class/lego-sensor/sensor" _ID_SPOT "value7"

#define PATH_VALUE  "/sys/class/lego-sensor/sensor" _ID_SPOT "value"

size_t get_sensor_bin_data( uint8_t sn, byte *buf, size_t sz )
{
	char s[] = PATH_BIN_DATA;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_byte_array( s, buf, sz );
}

size_t set_sensor_bin_data( uint8_t sn, byte *value, size_t sz )
{
	char s[] = PATH_BIN_DATA;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_byte_array( s, value, sz );
}

size_t get_sensor_bin_data_format( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_BIN_DATA_FORMAT;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_sensor_command( uint8_t sn, char *value )
{
	char s[] = PATH_COMMAND;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t get_sensor_commands( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_COMMANDS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_direct( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_DIRECT;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_sensor_direct( uint8_t sn, char *value )
{
	char s[] = PATH_DIRECT;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t get_sensor_decimals( uint8_t sn, dword *buf )
{
	char s[] = PATH_DECIMALS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_dword( s, buf );
}

size_t get_sensor_driver_name( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_DRIVER_NAME;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_fw_version( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_FW_VERSION;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_mode( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_MODE;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_sensor_mode( uint8_t sn, char *value )
{
	char s[] = PATH_MODE;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t get_sensor_modes( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_MODES;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_num_values( uint8_t sn, dword *buf )
{
	char s[] = PATH_NUM_VALUES;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_dword( s, buf );
}

size_t get_sensor_poll_ms( uint8_t sn, dword *buf )
{
	char s[] = PATH_POLL_MS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_dword( s, buf );
}

size_t set_sensor_poll_ms( uint8_t sn, dword value )
{
	char s[] = PATH_POLL_MS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_dword( s, value );
}

size_t get_sensor_port_name( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_PORT_NAME;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_units( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_UNITS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_sensor_value0( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE0;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value1( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE1;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value2( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE2;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value3( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE3;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value4( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE4;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value5( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE5;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value6( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE6;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value7( uint8_t sn, float *buf )
{
	char s[] = PATH_VALUE7;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_float( s, buf );
}

size_t get_sensor_value( uint8_t inx, uint8_t sn, int *buf )
{
	char s[] = PATH_VALUE "    ";

	if ( inx > 8 ) return ( 0 );

	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';
	modp_uitoa10( inx, s + PATH_PREF_LEN + 3 + 5 );

	return ev3_read_int( s, buf );
}

const char *ev3_sensor_type( inx_t type_inx )
{
	switch ( type_inx ) {
	case EV3_ANALOG_XX:
		return "ev3-analog-XX";
	case NXT_ANALOG:
		return "nxt-analog";
	case HT_NXT_COLOR:
		return "ht-nxt-color";
	case HT_NXT_ANGLE:
		return "ht-nxt-angle";
	case HT_NXT_ACCEL:
		return "ht-nxt-accel";
	case HT_NXT_BAROMETRIC:
		return "ht-nxt-barometric";
	case HT_NXT_COLOR_V2:
		return "ht-nxt-color-v2";
	case HT_NXT_EOPD:
		return "ht-nxt-eopd";
	case HT_NXT_FORCE:
		return "ht-nxt-force";
	case HT_NXT_GYRO:
		return "ht-nxt-gyro";
	case HT_NXT_IR_LINK:
		return "ht-nxt-ir-link";
	case HT_NXT_IR_RECEIVER:
		return "ht-nxt-ir-receiver";
	case HT_NXT_PIR:
		return "ht-nxt-pir";
	case HT_NXT_COMPASS:
		return "ht-nxt-compass";
	case HT_NXT_MAG:
		return "ht-nxt-mag";
	case HT_NXT_IR_SEEK_V2:
		return "ht-nxt-ir-seek-v2";
	case HT_NXT_SMUX:
		return "ht-nxt-smux";
	case HT_SUPER_PRO:
		return "ht-super-pro";
	case LEGO_EV3_US:
		return "lego-ev3-us";
	case LEGO_EV3_GYRO:
		return "lego-ev3-gyro";
	case LEGO_EV3_COLOR:
		return "lego-ev3-color";
	case LEGO_EV3_TOUCH:
		return "lego-ev3-touch";
	case LEGO_EV3_IR:
		return "lego-ev3-ir";
	case WEDO_HUB:
		return "wedo-hub";
	case WEDO_MOTION:
		return "wedo-motion";
	case WEDO_TILT:
		return "wedo-tilt";
	case LEGO_POWER_STORAGE:
		return "lego-power-storage";
	case LEGO_NXT_TOUCH:
		return "lego-nxt-touch";
	case LEGO_NXT_LIGHT:
		return "lego-nxt-light";
	case LEGO_NXT_SOUND:
		return "lego-nxt-sound";
	case LEGO_NXT_US:
		return "lego-nxt-us";
	case MI_XG1300L:
		return "mi-xg1300l";
	case MS_ABSOLUTE_IMU:
		return "ms-absolute-imu";
	case MS_ANGLE:
		return "ms-angle";
	case MS_EV3_SMUX:
		return "ms-ev3-smux";
	case MS_LIGHT_ARRAY:
		return "ms-light-array";
	case MS_LINE_LEADER:
		return "ms-line-leader";
	case MS_NXTMMX:
		return "ms-nxtmmx";
	case MS_8CH_SERVO:
		return "ms-8ch-servo";
	case MS_NXT_TOUCH_MUX:
		return "ms-nxt-touch-mux";

	}
	return ( STR_unknown_ );
}

inx_t get_sensor_type_inx( uint8_t sn )
{
	char buf[ 64 ];

	if ( !get_sensor_driver_name( sn, buf, sizeof( buf ))) return ( SENSOR_TYPE__NONE_ );

	switch ( crc32( 0, buf, strlen( buf ))) {
	case 0x9aaef5b7L:  /* "ev3-analog-XX" */
		return EV3_ANALOG_XX;
	case 0xf7e1ce2cL:  /* "nxt-analog" */
		return NXT_ANALOG;
	case 0x49a6f8bfL:  /* "ht-nxt-color" */
		return HT_NXT_COLOR;
	case 0x2f71f55fL:  /* "ht-nxt-angle" */
		return HT_NXT_ANGLE;
	case 0x720c86b3L:  /* "ht-nxt-accel" */
		return HT_NXT_ACCEL;
	case 0xd5e63331L:  /* "ht-nxt-barometric" */
		return HT_NXT_BAROMETRIC;
	case 0x53b4575dL:  /* "ht-nxt-color-v2" */
		return HT_NXT_COLOR_V2;
	case 0x941b59bbL:  /* "ht-nxt-eopd" */
		return HT_NXT_EOPD;
	case 0xb898337eL:  /* "ht-nxt-force" */
		return HT_NXT_FORCE;
	case 0x835df5f8L:  /* "ht-nxt-gyro" */
		return HT_NXT_GYRO;
	case 0xcc91b174L:  /* "ht-nxt-ir-link" */
		return HT_NXT_IR_LINK;
	case 0xe6e18e7bL:  /* "ht-nxt-ir-receiver" */
		return HT_NXT_IR_RECEIVER;
	case 0xd2b1e8faL:  /* "ht-nxt-pir" */
		return HT_NXT_PIR;
	case 0x7786eae3L:  /* "ht-nxt-compass" */
		return HT_NXT_COMPASS;
	case 0x634bb63aL:  /* "ht-nxt-mag" */
		return HT_NXT_MAG;
	case 0xc6cc6277L:  /* "ht-nxt-ir-seek-v2" */
		return HT_NXT_IR_SEEK_V2;
	case 0x8b9b2d9cL:  /* "ht-nxt-smux" */
		return HT_NXT_SMUX;
	case 0x7da3900fL:  /* "ht-super-pro" */
		return HT_SUPER_PRO;
	case 0xfec0d84eL:  /* "lego-ev3-us" */
		return LEGO_EV3_US;
	case 0x90a8a92dL:  /* "lego-ev3-gyro" */
		return LEGO_EV3_GYRO;
	case 0xbf0c2bb8L:  /* "lego-ev3-color" */
		return LEGO_EV3_COLOR;
	case 0x2fec4ea3L:  /* "lego-ev3-touch" */
		return LEGO_EV3_TOUCH;
	case 0x6fb0b585L:  /* "lego-ev3-ir" */
		return LEGO_EV3_IR;
	case 0x7756e9ceL:  /* "wedo-hub" */
		return WEDO_HUB;
	case 0x69420300L:  /* "wedo-motion" */
		return WEDO_MOTION;
	case 0x68b17c4bL:  /* "wedo-tilt" */
		return WEDO_TILT;
	case 0xc62761bdL:  /* "lego-power-storage" */
		return LEGO_POWER_STORAGE;
	case 0x399f89bbL:  /* "lego-nxt-touch" */
		return LEGO_NXT_TOUCH;
	case 0xa433f8beL:  /* "lego-nxt-light" */
		return LEGO_NXT_LIGHT;
	case 0x37a767cdL:  /* "lego-nxt-sound" */
		return LEGO_NXT_SOUND;
	case 0x2df4f668L:  /* "lego-nxt-us" */
		return LEGO_NXT_US;
	case 0x5ea03e09L:  /* "mi-xg1300l" */
		return MI_XG1300L;
	case 0x33431ceaL:  /* "ms-absolute-imu" */
		return MS_ABSOLUTE_IMU;
	case 0x8edd0449L:  /* "ms-angle" */
		return MS_ANGLE;
	case 0x718c778L:  /* "ms-ev3-smux" */
		return MS_EV3_SMUX;
	case 0xe337cbb5L:  /* "ms-light-array" */
		return MS_LIGHT_ARRAY;
	case 0xfae1806dL:  /* "ms-line-leader" */
		return MS_LINE_LEADER;
	case 0x1613fa0aL:  /* "ms-nxtmmx" */
		return MS_NXTMMX;
	case 0x993a454aL:  /* "ms-8ch-servo" */
		return MS_8CH_SERVO;
	case 0xb033713fL:  /* "ms-nxt-touch-mux" */
		return MS_NXT_TOUCH_MUX;

	}

	return ( SENSOR_TYPE__UNKNOWN_ );
}

size_t get_sensor_desc( uint8_t sn, EV3_SENSOR *desc )
{
	uint8_t addr;
	char buf[ 32 ];

	desc->type_inx = get_sensor_type_inx( sn );
	if ( desc->type_inx == SENSOR_TYPE__NONE_ ) return ( 0 );

	if ( !get_sensor_port_name( sn, buf, sizeof( buf ))) return ( 0 );

	ev3_parse_port_name( buf, &desc->port, &desc->extport, &addr );
	desc->addr = addr;

	return ( sizeof( EV3_SENSOR ));
}

EV3_SENSOR *ev3_sensor_desc( uint8_t sn )
{
	if ( sn >= SENSOR_DESC__LIMIT_) sn = SENSOR_DESC__LIMIT_ - 1;
	return ( ev3_sensor + sn );
}

inx_t ev3_sensor_desc_type_inx( uint8_t sn )
{
	return ( ev3_sensor_desc( sn )->type_inx );
}

uint8_t ev3_sensor_desc_port( uint8_t sn )
{
	return ( ev3_sensor_desc( sn )->port );
}

uint8_t ev3_sensor_desc_extport( uint8_t sn )
{
	return ( ev3_sensor_desc( sn )->extport );
}

uint8_t ev3_sensor_desc_addr( uint8_t sn )
{
	return ( ev3_sensor_desc( sn )->addr );
}

char *ev3_sensor_port_name( uint8_t sn, char *buf )
{
	return ( ev3_port_name( ev3_sensor_desc( sn )->port, ev3_sensor_desc( sn )->extport, ev3_sensor_desc( sn )->addr, buf ));
}

bool ev3_search_sensor( inx_t type_inx, uint8_t *sn, uint8_t from )
{
	uint8_t _sn = from;

	while ( _sn < SENSOR_DESC__LIMIT_) {
		if ( ev3_sensor[ _sn ].type_inx == type_inx ) {
			*sn = _sn;
			return ( true );
		}
		++_sn;
	}
	*sn = SENSOR__NONE_;
	return ( false );
}

bool ev3_search_sensor_plugged_in( uint8_t port, uint8_t extport, uint8_t *sn, uint8_t from )
{
	uint8_t _sn = from;

	while ( _sn < SENSOR_DESC__LIMIT_) {
		if ( ev3_sensor[ _sn ].port == port ) {
			if ( extport ) {
				if ( ev3_sensor[ _sn ].extport == extport ) {
					*sn = _sn;
					return ( true );
				}
			} else {
				*sn = _sn;
				return ( true );
			}
		}
		++_sn;
	}
	*sn = SENSOR__NONE_;
	return ( false );
}

const char *ev3_sensor_mode( inx_t mode_inx )
{
	switch ( mode_inx ) {
	case EV3_ANALOG_XX_ANALOG:
		return "ANALOG";

	case NXT_ANALOG_ANALOG_0:
		return "ANALOG-0";
	case NXT_ANALOG_ANALOG_1:
		return "ANALOG-1";

	case HT_NXT_COLOR_COLOR:
		return "COLOR";
	case HT_NXT_COLOR_RED:
		return "RED";
	case HT_NXT_COLOR_GREEN:
		return "GREEN";
	case HT_NXT_COLOR_BLUE:
		return "BLUE";
	case HT_NXT_COLOR_RAW:
		return "RAW";
	case HT_NXT_COLOR_NORM:
		return "NORM";
	case HT_NXT_COLOR_ALL:
		return "ALL";

	case HT_NXT_ANGLE_ANGLE:
		return "ANGLE";
	case HT_NXT_ANGLE_ANGLE_ACC:
		return "ANGLE-ACC";
	case HT_NXT_ANGLE_SPEED:
		return "SPEED";

	case HT_NXT_ACCEL_ACCEL:
		return "ACCEL";
	case HT_NXT_ACCEL_ALL:
		return "ALL";

	case HT_NXT_BAROMETRIC_PRESS:
		return "PRESS";
	case HT_NXT_BAROMETRIC_TEMP:
		return "TEMP";

	case HT_NXT_COLOR_V2_COLOR:
		return "COLOR";
	case HT_NXT_COLOR_V2_RED:
		return "RED";
	case HT_NXT_COLOR_V2_GREEN:
		return "GREEN";
	case HT_NXT_COLOR_V2_BLUE:
		return "BLUE";
	case HT_NXT_COLOR_V2_WHITE:
		return "WHITE";
	case HT_NXT_COLOR_V2_NORM:
		return "NORM";
	case HT_NXT_COLOR_V2_ALL:
		return "ALL";
	case HT_NXT_COLOR_V2_RAW:
		return "RAW";

	case HT_NXT_EOPD_LONG:
		return "LONG";
	case HT_NXT_EOPD_SHORT:
		return "SHORT";

	case HT_NXT_FORCE_FORCE:
		return "FORCE";

	case HT_NXT_GYRO_GYRO:
		return "GYRO";

	case HT_NXT_IR_LINK_IRLINK:
		return "IRLINK";

	case HT_NXT_IR_RECEIVER_1_MOTOR:
		return "1-MOTOR";
	case HT_NXT_IR_RECEIVER_8_MOTOR:
		return "8-MOTOR";

	case HT_NXT_PIR_PROX:
		return "PROX";

	case HT_NXT_COMPASS_COMPASS:
		return "COMPASS";

	case HT_NXT_MAG_MAG:
		return "MAG";

	case HT_NXT_IR_SEEK_V2_DC:
		return "DC";
	case HT_NXT_IR_SEEK_V2_AC:
		return "AC";
	case HT_NXT_IR_SEEK_V2_DC_ALL:
		return "DC-ALL";
	case HT_NXT_IR_SEEK_V2_AC_ALL:
		return "AC-ALL";

	case HT_NXT_SMUX_MUX:
		return "MUX";

	case HT_SUPER_PRO_AIN:
		return "AIN";
	case HT_SUPER_PRO_DIN:
		return "DIN";
	case HT_SUPER_PRO_DOUT:
		return "DOUT";
	case HT_SUPER_PRO_DCTRL:
		return "DCTRL";
	case HT_SUPER_PRO_STROBE:
		return "STROBE";
	case HT_SUPER_PRO_LED:
		return "LED";
	case HT_SUPER_PRO_AOUT_0:
		return "AOUT-0";
	case HT_SUPER_PRO_AOUT_1:
		return "AOUT-1";

	case LEGO_EV3_US_US_DIST_CM:
		return "US-DIST-CM";
	case LEGO_EV3_US_US_DIST_IN:
		return "US-DIST-IN";
	case LEGO_EV3_US_US_LISTEN:
		return "US-LISTEN";
	case LEGO_EV3_US_US_SI_CM:
		return "US-SI-CM";
	case LEGO_EV3_US_US_SI_IN:
		return "US-SI-IN";
	case LEGO_EV3_US_US_DC_CM:
		return "US-DC-CM";
	case LEGO_EV3_US_US_DC_IN:
		return "US-DC-IN";

	case LEGO_EV3_GYRO_GYRO_ANG:
		return "GYRO-ANG";
	case LEGO_EV3_GYRO_GYRO_RATE:
		return "GYRO-RATE";
	case LEGO_EV3_GYRO_GYRO_FAS:
		return "GYRO-FAS";
	case LEGO_EV3_GYRO_GYRO_G_AND_A:
		return "GYRO-G&A";
	case LEGO_EV3_GYRO_GYRO_CAL:
		return "GYRO-CAL";

	case LEGO_EV3_COLOR_COL_REFLECT:
		return "COL-REFLECT";
	case LEGO_EV3_COLOR_COL_AMBIENT:
		return "COL-AMBIENT";
	case LEGO_EV3_COLOR_COL_COLOR:
		return "COL-COLOR";
	case LEGO_EV3_COLOR_REF_RAW:
		return "REF-RAW";
	case LEGO_EV3_COLOR_RGB_RAW:
		return "RGB-RAW";
	case LEGO_EV3_COLOR_COL_CAL:
		return "COL-CAL";

	case LEGO_EV3_TOUCH_TOUCH:
		return "TOUCH";

	case LEGO_EV3_IR_IR_PROX:
		return "IR-PROX";
	case LEGO_EV3_IR_IR_SEEK:
		return "IR-SEEK";
	case LEGO_EV3_IR_IR_REMOTE:
		return "IR-REMOTE";
	case LEGO_EV3_IR_IR_REM_A:
		return "IR-REM-A";
	case LEGO_EV3_IR_IR_S_ALT:
		return "IR-S-ALT";
	case LEGO_EV3_IR_IR_CAL:
		return "IR-CAL";

	case WEDO_HUB_HUB:
		return "HUB";

	case WEDO_MOTION_PROX:
		return "PROX";
	case WEDO_MOTION_RAW:
		return "RAW";

	case WEDO_TILT_TILT:
		return "TILT";
	case WEDO_TILT_TILT_AXIS:
		return "TILT-AXIS";
	case WEDO_TILT_RAW:
		return "RAW";

	case LEGO_POWER_STORAGE_IN_VOLT:
		return "IN-VOLT";
	case LEGO_POWER_STORAGE_IN_AMP:
		return "IN-AMP";
	case LEGO_POWER_STORAGE_OUT_VOLT:
		return "OUT-VOLT";
	case LEGO_POWER_STORAGE_OUT_AMP:
		return "OUT-AMP";
	case LEGO_POWER_STORAGE_JOULE:
		return "JOULE";
	case LEGO_POWER_STORAGE_IN_WATT:
		return "IN-WATT";
	case LEGO_POWER_STORAGE_OUT_WATT:
		return "OUT-WATT";
	case LEGO_POWER_STORAGE_ALL:
		return "ALL";

	case LEGO_NXT_TOUCH_TOUCH:
		return "TOUCH";

	case LEGO_NXT_LIGHT_REFLECT:
		return "REFLECT";
	case LEGO_NXT_LIGHT_AMBIENT:
		return "AMBIENT";

	case LEGO_NXT_SOUND_DB:
		return "DB";
	case LEGO_NXT_SOUND_DBA:
		return "DBA";

	case LEGO_NXT_US_US_DIST_CM:
		return "US-DIST-CM";
	case LEGO_NXT_US_US_DIST_IN:
		return "US-DIST-IN";
	case LEGO_NXT_US_US_SI_CM:
		return "US-SI-CM";
	case LEGO_NXT_US_US_SI_IN:
		return "US-SI-IN";
	case LEGO_NXT_US_US_LISTEN:
		return "US-LISTEN";

	case MI_XG1300L_ANGLE:
		return "ANGLE";
	case MI_XG1300L_SPEED:
		return "SPEED";
	case MI_XG1300L_ACCEL:
		return "ACCEL";
	case MI_XG1300L_ALL:
		return "ALL";

	case MS_ABSOLUTE_IMU_TILT:
		return "TILT";
	case MS_ABSOLUTE_IMU_ACCEL:
		return "ACCEL";
	case MS_ABSOLUTE_IMU_COMPASS:
		return "COMPASS";
	case MS_ABSOLUTE_IMU_MAG:
		return "MAG";
	case MS_ABSOLUTE_IMU_GYRO:
		return "GYRO";
	case MS_ABSOLUTE_IMU_ALL:
		return "ALL";

	case MS_ANGLE_ANGLE:
		return "ANGLE";
	case MS_ANGLE_ANGLE2:
		return "ANGLE2";
	case MS_ANGLE_SPEED:
		return "SPEED";
	case MS_ANGLE_ALL:
		return "ALL";

	case MS_EV3_SMUX_MUX:
		return "MUX";

	case MS_LIGHT_ARRAY_CAL:
		return "CAL";
	case MS_LIGHT_ARRAY_RAW:
		return "RAW";

	case MS_LINE_LEADER_PID:
		return "PID";
	case MS_LINE_LEADER_PID_ALL:
		return "PID-ALL";
	case MS_LINE_LEADER_CAL:
		return "CAL";
	case MS_LINE_LEADER_RAW:
		return "RAW";

	case MS_NXTMMX_STATUS:
		return "STATUS";
	case MS_NXTMMX_STATUS_OLD:
		return "STATUS-OLD";

	case MS_8CH_SERVO_V3:
		return "V3";
	case MS_8CH_SERVO_OLD:
		return "OLD";

	case MS_NXT_TOUCH_MUX_TOUCH_MUX:
		return "TOUCH-MUX";

	}
	return ( STR_unknown_ );
}

inx_t get_sensor_mode_inx( uint8_t sn, inx_t type_inx )
{
	char buf[ 64 ];

	if ( !get_sensor_mode( sn, buf, sizeof( buf ))) return ( SENSOR_MODE__NONE_ );

	switch ( type_inx ) {
			
	case EV3_ANALOG_XX:
		if ( strcmp( buf, "ANALOG" ) == 0 ) return EV3_ANALOG_XX_ANALOG;

		break;

	case NXT_ANALOG:
		if ( strcmp( buf, "ANALOG-0" ) == 0 ) return NXT_ANALOG_ANALOG_0;
		if ( strcmp( buf, "ANALOG-1" ) == 0 ) return NXT_ANALOG_ANALOG_1;

		break;

	case HT_NXT_COLOR:
		if ( strcmp( buf, "COLOR" ) == 0 ) return HT_NXT_COLOR_COLOR;
		if ( strcmp( buf, "RED" ) == 0 ) return HT_NXT_COLOR_RED;
		if ( strcmp( buf, "GREEN" ) == 0 ) return HT_NXT_COLOR_GREEN;
		if ( strcmp( buf, "BLUE" ) == 0 ) return HT_NXT_COLOR_BLUE;
		if ( strcmp( buf, "RAW" ) == 0 ) return HT_NXT_COLOR_RAW;
		if ( strcmp( buf, "NORM" ) == 0 ) return HT_NXT_COLOR_NORM;
		if ( strcmp( buf, "ALL" ) == 0 ) return HT_NXT_COLOR_ALL;

		break;

	case HT_NXT_ANGLE:
		if ( strcmp( buf, "ANGLE" ) == 0 ) return HT_NXT_ANGLE_ANGLE;
		if ( strcmp( buf, "ANGLE-ACC" ) == 0 ) return HT_NXT_ANGLE_ANGLE_ACC;
		if ( strcmp( buf, "SPEED" ) == 0 ) return HT_NXT_ANGLE_SPEED;

		break;

	case HT_NXT_ACCEL:
		if ( strcmp( buf, "ACCEL" ) == 0 ) return HT_NXT_ACCEL_ACCEL;
		if ( strcmp( buf, "ALL" ) == 0 ) return HT_NXT_ACCEL_ALL;

		break;

	case HT_NXT_BAROMETRIC:
		if ( strcmp( buf, "PRESS" ) == 0 ) return HT_NXT_BAROMETRIC_PRESS;
		if ( strcmp( buf, "TEMP" ) == 0 ) return HT_NXT_BAROMETRIC_TEMP;

		break;

	case HT_NXT_COLOR_V2:
		if ( strcmp( buf, "COLOR" ) == 0 ) return HT_NXT_COLOR_V2_COLOR;
		if ( strcmp( buf, "RED" ) == 0 ) return HT_NXT_COLOR_V2_RED;
		if ( strcmp( buf, "GREEN" ) == 0 ) return HT_NXT_COLOR_V2_GREEN;
		if ( strcmp( buf, "BLUE" ) == 0 ) return HT_NXT_COLOR_V2_BLUE;
		if ( strcmp( buf, "WHITE" ) == 0 ) return HT_NXT_COLOR_V2_WHITE;
		if ( strcmp( buf, "NORM" ) == 0 ) return HT_NXT_COLOR_V2_NORM;
		if ( strcmp( buf, "ALL" ) == 0 ) return HT_NXT_COLOR_V2_ALL;
		if ( strcmp( buf, "RAW" ) == 0 ) return HT_NXT_COLOR_V2_RAW;

		break;

	case HT_NXT_EOPD:
		if ( strcmp( buf, "LONG" ) == 0 ) return HT_NXT_EOPD_LONG;
		if ( strcmp( buf, "SHORT" ) == 0 ) return HT_NXT_EOPD_SHORT;

		break;

	case HT_NXT_FORCE:
		if ( strcmp( buf, "FORCE" ) == 0 ) return HT_NXT_FORCE_FORCE;

		break;

	case HT_NXT_GYRO:
		if ( strcmp( buf, "GYRO" ) == 0 ) return HT_NXT_GYRO_GYRO;

		break;

	case HT_NXT_IR_LINK:
		if ( strcmp( buf, "IRLINK" ) == 0 ) return HT_NXT_IR_LINK_IRLINK;

		break;

	case HT_NXT_IR_RECEIVER:
		if ( strcmp( buf, "1-MOTOR" ) == 0 ) return HT_NXT_IR_RECEIVER_1_MOTOR;
		if ( strcmp( buf, "8-MOTOR" ) == 0 ) return HT_NXT_IR_RECEIVER_8_MOTOR;

		break;

	case HT_NXT_PIR:
		if ( strcmp( buf, "PROX" ) == 0 ) return HT_NXT_PIR_PROX;

		break;

	case HT_NXT_COMPASS:
		if ( strcmp( buf, "COMPASS" ) == 0 ) return HT_NXT_COMPASS_COMPASS;

		break;

	case HT_NXT_MAG:
		if ( strcmp( buf, "MAG" ) == 0 ) return HT_NXT_MAG_MAG;

		break;

	case HT_NXT_IR_SEEK_V2:
		if ( strcmp( buf, "DC" ) == 0 ) return HT_NXT_IR_SEEK_V2_DC;
		if ( strcmp( buf, "AC" ) == 0 ) return HT_NXT_IR_SEEK_V2_AC;
		if ( strcmp( buf, "DC-ALL" ) == 0 ) return HT_NXT_IR_SEEK_V2_DC_ALL;
		if ( strcmp( buf, "AC-ALL" ) == 0 ) return HT_NXT_IR_SEEK_V2_AC_ALL;

		break;

	case HT_NXT_SMUX:
		if ( strcmp( buf, "MUX" ) == 0 ) return HT_NXT_SMUX_MUX;

		break;

	case HT_SUPER_PRO:
		if ( strcmp( buf, "AIN" ) == 0 ) return HT_SUPER_PRO_AIN;
		if ( strcmp( buf, "DIN" ) == 0 ) return HT_SUPER_PRO_DIN;
		if ( strcmp( buf, "DOUT" ) == 0 ) return HT_SUPER_PRO_DOUT;
		if ( strcmp( buf, "DCTRL" ) == 0 ) return HT_SUPER_PRO_DCTRL;
		if ( strcmp( buf, "STROBE" ) == 0 ) return HT_SUPER_PRO_STROBE;
		if ( strcmp( buf, "LED" ) == 0 ) return HT_SUPER_PRO_LED;
		if ( strcmp( buf, "AOUT-0" ) == 0 ) return HT_SUPER_PRO_AOUT_0;
		if ( strcmp( buf, "AOUT-1" ) == 0 ) return HT_SUPER_PRO_AOUT_1;

		break;

	case LEGO_EV3_US:
		if ( strcmp( buf, "US-DIST-CM" ) == 0 ) return LEGO_EV3_US_US_DIST_CM;
		if ( strcmp( buf, "US-DIST-IN" ) == 0 ) return LEGO_EV3_US_US_DIST_IN;
		if ( strcmp( buf, "US-LISTEN" ) == 0 ) return LEGO_EV3_US_US_LISTEN;
		if ( strcmp( buf, "US-SI-CM" ) == 0 ) return LEGO_EV3_US_US_SI_CM;
		if ( strcmp( buf, "US-SI-IN" ) == 0 ) return LEGO_EV3_US_US_SI_IN;
		if ( strcmp( buf, "US-DC-CM" ) == 0 ) return LEGO_EV3_US_US_DC_CM;
		if ( strcmp( buf, "US-DC-IN" ) == 0 ) return LEGO_EV3_US_US_DC_IN;

		break;

	case LEGO_EV3_GYRO:
		if ( strcmp( buf, "GYRO-ANG" ) == 0 ) return LEGO_EV3_GYRO_GYRO_ANG;
		if ( strcmp( buf, "GYRO-RATE" ) == 0 ) return LEGO_EV3_GYRO_GYRO_RATE;
		if ( strcmp( buf, "GYRO-FAS" ) == 0 ) return LEGO_EV3_GYRO_GYRO_FAS;
		if ( strcmp( buf, "GYRO-G&A" ) == 0 ) return LEGO_EV3_GYRO_GYRO_G_AND_A;
		if ( strcmp( buf, "GYRO-CAL" ) == 0 ) return LEGO_EV3_GYRO_GYRO_CAL;

		break;

	case LEGO_EV3_COLOR:
		if ( strcmp( buf, "COL-REFLECT" ) == 0 ) return LEGO_EV3_COLOR_COL_REFLECT;
		if ( strcmp( buf, "COL-AMBIENT" ) == 0 ) return LEGO_EV3_COLOR_COL_AMBIENT;
		if ( strcmp( buf, "COL-COLOR" ) == 0 ) return LEGO_EV3_COLOR_COL_COLOR;
		if ( strcmp( buf, "REF-RAW" ) == 0 ) return LEGO_EV3_COLOR_REF_RAW;
		if ( strcmp( buf, "RGB-RAW" ) == 0 ) return LEGO_EV3_COLOR_RGB_RAW;
		if ( strcmp( buf, "COL-CAL" ) == 0 ) return LEGO_EV3_COLOR_COL_CAL;

		break;

	case LEGO_EV3_TOUCH:
		if ( strcmp( buf, "TOUCH" ) == 0 ) return LEGO_EV3_TOUCH_TOUCH;

		break;

	case LEGO_EV3_IR:
		if ( strcmp( buf, "IR-PROX" ) == 0 ) return LEGO_EV3_IR_IR_PROX;
		if ( strcmp( buf, "IR-SEEK" ) == 0 ) return LEGO_EV3_IR_IR_SEEK;
		if ( strcmp( buf, "IR-REMOTE" ) == 0 ) return LEGO_EV3_IR_IR_REMOTE;
		if ( strcmp( buf, "IR-REM-A" ) == 0 ) return LEGO_EV3_IR_IR_REM_A;
		if ( strcmp( buf, "IR-S-ALT" ) == 0 ) return LEGO_EV3_IR_IR_S_ALT;
		if ( strcmp( buf, "IR-CAL" ) == 0 ) return LEGO_EV3_IR_IR_CAL;

		break;

	case WEDO_HUB:
		if ( strcmp( buf, "HUB" ) == 0 ) return WEDO_HUB_HUB;

		break;

	case WEDO_MOTION:
		if ( strcmp( buf, "PROX" ) == 0 ) return WEDO_MOTION_PROX;
		if ( strcmp( buf, "RAW" ) == 0 ) return WEDO_MOTION_RAW;

		break;

	case WEDO_TILT:
		if ( strcmp( buf, "TILT" ) == 0 ) return WEDO_TILT_TILT;
		if ( strcmp( buf, "TILT-AXIS" ) == 0 ) return WEDO_TILT_TILT_AXIS;
		if ( strcmp( buf, "RAW" ) == 0 ) return WEDO_TILT_RAW;

		break;

	case LEGO_POWER_STORAGE:
		if ( strcmp( buf, "IN-VOLT" ) == 0 ) return LEGO_POWER_STORAGE_IN_VOLT;
		if ( strcmp( buf, "IN-AMP" ) == 0 ) return LEGO_POWER_STORAGE_IN_AMP;
		if ( strcmp( buf, "OUT-VOLT" ) == 0 ) return LEGO_POWER_STORAGE_OUT_VOLT;
		if ( strcmp( buf, "OUT-AMP" ) == 0 ) return LEGO_POWER_STORAGE_OUT_AMP;
		if ( strcmp( buf, "JOULE" ) == 0 ) return LEGO_POWER_STORAGE_JOULE;
		if ( strcmp( buf, "IN-WATT" ) == 0 ) return LEGO_POWER_STORAGE_IN_WATT;
		if ( strcmp( buf, "OUT-WATT" ) == 0 ) return LEGO_POWER_STORAGE_OUT_WATT;
		if ( strcmp( buf, "ALL" ) == 0 ) return LEGO_POWER_STORAGE_ALL;

		break;

	case LEGO_NXT_TOUCH:
		if ( strcmp( buf, "TOUCH" ) == 0 ) return LEGO_NXT_TOUCH_TOUCH;

		break;

	case LEGO_NXT_LIGHT:
		if ( strcmp( buf, "REFLECT" ) == 0 ) return LEGO_NXT_LIGHT_REFLECT;
		if ( strcmp( buf, "AMBIENT" ) == 0 ) return LEGO_NXT_LIGHT_AMBIENT;

		break;

	case LEGO_NXT_SOUND:
		if ( strcmp( buf, "DB" ) == 0 ) return LEGO_NXT_SOUND_DB;
		if ( strcmp( buf, "DBA" ) == 0 ) return LEGO_NXT_SOUND_DBA;

		break;

	case LEGO_NXT_US:
		if ( strcmp( buf, "US-DIST-CM" ) == 0 ) return LEGO_NXT_US_US_DIST_CM;
		if ( strcmp( buf, "US-DIST-IN" ) == 0 ) return LEGO_NXT_US_US_DIST_IN;
		if ( strcmp( buf, "US-SI-CM" ) == 0 ) return LEGO_NXT_US_US_SI_CM;
		if ( strcmp( buf, "US-SI-IN" ) == 0 ) return LEGO_NXT_US_US_SI_IN;
		if ( strcmp( buf, "US-LISTEN" ) == 0 ) return LEGO_NXT_US_US_LISTEN;

		break;

	case MI_XG1300L:
		if ( strcmp( buf, "ANGLE" ) == 0 ) return MI_XG1300L_ANGLE;
		if ( strcmp( buf, "SPEED" ) == 0 ) return MI_XG1300L_SPEED;
		if ( strcmp( buf, "ACCEL" ) == 0 ) return MI_XG1300L_ACCEL;
		if ( strcmp( buf, "ALL" ) == 0 ) return MI_XG1300L_ALL;

		break;

	case MS_ABSOLUTE_IMU:
		if ( strcmp( buf, "TILT" ) == 0 ) return MS_ABSOLUTE_IMU_TILT;
		if ( strcmp( buf, "ACCEL" ) == 0 ) return MS_ABSOLUTE_IMU_ACCEL;
		if ( strcmp( buf, "COMPASS" ) == 0 ) return MS_ABSOLUTE_IMU_COMPASS;
		if ( strcmp( buf, "MAG" ) == 0 ) return MS_ABSOLUTE_IMU_MAG;
		if ( strcmp( buf, "GYRO" ) == 0 ) return MS_ABSOLUTE_IMU_GYRO;
		if ( strcmp( buf, "ALL" ) == 0 ) return MS_ABSOLUTE_IMU_ALL;

		break;

	case MS_ANGLE:
		if ( strcmp( buf, "ANGLE" ) == 0 ) return MS_ANGLE_ANGLE;
		if ( strcmp( buf, "ANGLE2" ) == 0 ) return MS_ANGLE_ANGLE2;
		if ( strcmp( buf, "SPEED" ) == 0 ) return MS_ANGLE_SPEED;
		if ( strcmp( buf, "ALL" ) == 0 ) return MS_ANGLE_ALL;

		break;

	case MS_EV3_SMUX:
		if ( strcmp( buf, "MUX" ) == 0 ) return MS_EV3_SMUX_MUX;

		break;

	case MS_LIGHT_ARRAY:
		if ( strcmp( buf, "CAL" ) == 0 ) return MS_LIGHT_ARRAY_CAL;
		if ( strcmp( buf, "RAW" ) == 0 ) return MS_LIGHT_ARRAY_RAW;

		break;

	case MS_LINE_LEADER:
		if ( strcmp( buf, "PID" ) == 0 ) return MS_LINE_LEADER_PID;
		if ( strcmp( buf, "PID-ALL" ) == 0 ) return MS_LINE_LEADER_PID_ALL;
		if ( strcmp( buf, "CAL" ) == 0 ) return MS_LINE_LEADER_CAL;
		if ( strcmp( buf, "RAW" ) == 0 ) return MS_LINE_LEADER_RAW;

		break;

	case MS_NXTMMX:
		if ( strcmp( buf, "STATUS" ) == 0 ) return MS_NXTMMX_STATUS;
		if ( strcmp( buf, "STATUS-OLD" ) == 0 ) return MS_NXTMMX_STATUS_OLD;

		break;

	case MS_8CH_SERVO:
		if ( strcmp( buf, "V3" ) == 0 ) return MS_8CH_SERVO_V3;
		if ( strcmp( buf, "OLD" ) == 0 ) return MS_8CH_SERVO_OLD;

		break;

	case MS_NXT_TOUCH_MUX:
		if ( strcmp( buf, "TOUCH-MUX" ) == 0 ) return MS_NXT_TOUCH_MUX_TOUCH_MUX;

		break;

	}
	return ( SENSOR_MODE__UNKNOWN_ );
}

size_t set_sensor_mode_inx( uint8_t sn, inx_t mode_inx )
{
	return set_sensor_mode( sn, ( char* ) ev3_sensor_mode( mode_inx ));
}

const char *ev3_sensor_command( inx_t command_inx )
{
	switch ( command_inx ) {
					
	case HT_NXT_ANGLE_RESET:
		return "RESET";
	case HT_NXT_ANGLE_CAL:
		return "CAL";

	case HT_NXT_SMUX_HALT:
		return "HALT";
	case HT_NXT_SMUX_DETECT:
		return "DETECT";
	case HT_NXT_SMUX_RUN:
		return "RUN";

	case WEDO_HUB_OUT_OFF:
		return "OUT-OFF";
	case WEDO_HUB_OUT_ON:
		return "OUT-ON";
	case WEDO_HUB_CLEAR_ERR:
		return "CLEAR-ERR";

	case MI_XG1300L_RESET:
		return "RESET";
	case MI_XG1300L_ACCEL_2G:
		return "ACCEL-2G";
	case MI_XG1300L_ACCEL_4G:
		return "ACCEL-4G";
	case MI_XG1300L_ACCEL_8G:
		return "ACCEL-8G";

	case MS_ABSOLUTE_IMU_BEGIN_COMP_CAL:
		return "BEGIN-COMP-CAL";
	case MS_ABSOLUTE_IMU_END_COMP_CAL:
		return "END-COMP-CAL";
	case MS_ABSOLUTE_IMU_ACCEL_2G:
		return "ACCEL-2G";
	case MS_ABSOLUTE_IMU_ACCEL_4G:
		return "ACCEL-4G";
	case MS_ABSOLUTE_IMU_ACCEL_8G:
		return "ACCEL-8G";
	case MS_ABSOLUTE_IMU_ACCEL_16G:
		return "ACCEL-16G";

	case MS_ANGLE_RESET:
		return "RESET";

	case MS_LIGHT_ARRAY_CAL_WHITE:
		return "CAL-WHITE";
	case MS_LIGHT_ARRAY_CAL_BLACK:
		return "CAL-BLACK";
	case MS_LIGHT_ARRAY_SLEEP:
		return "SLEEP";
	case MS_LIGHT_ARRAY_WAKE:
		return "WAKE";
	case MS_LIGHT_ARRAY_60HZ:
		return "60HZ";
	case MS_LIGHT_ARRAY_50HZ:
		return "50HZ";
	case MS_LIGHT_ARRAY_UNIVERSAL:
		return "UNIVERSAL";

	case MS_LINE_LEADER_CAL_WHITE:
		return "CAL-WHITE";
	case MS_LINE_LEADER_CAL_BLACK:
		return "CAL-BLACK";
	case MS_LINE_LEADER_SLEEP:
		return "SLEEP";
	case MS_LINE_LEADER_WAKE:
		return "WAKE";
	case MS_LINE_LEADER_INV_COL:
		return "INV-COL";
	case MS_LINE_LEADER_RST_COL:
		return "RST-COL";
	case MS_LINE_LEADER_SNAP:
		return "SNAP";
	case MS_LINE_LEADER_60HZ:
		return "60HZ";
	case MS_LINE_LEADER_50HZ:
		return "50HZ";
	case MS_LINE_LEADER_UNIVERSAL:
		return "UNIVERSAL";

	}
	return ( STR_unknown_ );
}

size_t set_sensor_command_inx( uint8_t sn, inx_t command_inx )
{
	return set_sensor_command( sn, ( char* ) ev3_sensor_command( command_inx ));
}

int ev3_sensor_init( void )
{
	char list[ 256 ];
	char *p;
	uint32_t sn;
	int cnt = 0;

	memset( ev3_sensor, 0, sizeof( ev3_sensor ));

	if ( !ev3_listdir( "/sys/class/lego-sensor", list, sizeof( list ))) return ( -1 );

	p = strtok( list, " " );
	while ( p ) {
		if (( ev3_string_suffix( "sensor", &p, &sn ) == 1 ) && ( sn < SENSOR_DESC__LIMIT_)) {
			get_sensor_desc( sn, ev3_sensor + sn );
			++cnt;
		}
		p = strtok( NULL, " " );
	}
	return ( cnt );
}

