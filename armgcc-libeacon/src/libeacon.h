#ifndef LIBEACON_H
 #define LIBEACON_H

#define IBEACONS_LIST_SIZE 15
#define LINES_AT_BUFFER_ONE 30
#define LINES_AT_BUFFER_TWO 15

#define sizeofatbufferone 80*LINES_AT_BUFFER_ONE + 20 + 1
#define sizeofatbuffertwo 80*LINES_AT_BUFFER_ONE + 20 + 1

#define ATCOMMANDSUCCESS "OK+DISCE\r\n"
//#define _IBEACON_TARGET_FACTORYID "4C000215"
//#define _IBEACON_TARGET_UUID "74278BDAB64445208F0C720EAF059935"
#define _IBEACON_TARGET_FACTORYID "10000000"
#define _IBEACON_TARGET_UUID "10000000000000000000000000000000"
#define _IBEACON_TARGET_MAJOR "1000"
#define _IBEACON_TARGET_MINOR "1000"
#define _IBEACON_TARGET_MP "10"
#define _IBEACON_TARGET_MAC "100000000000"
#define _IBEACON_TARGET_RSSI "-100"

#define _FACTORYUUIDsize (8)
#define _UUIDsize (32)
#define _MAJORsize (4)
#define _MINORsize (4)
#define _MPsize (2)
#define _MACsize (12)
#define _RSSIsize (4)

void nprintf(char *str, uint32_t size);
void hexdump(char *p, uint32_t size, char *msg);

//void ibeacon_init(char *ibeacon1, char *ibeacon2...); ???
void ibeacon_init();
char *ibeacon_find_first_uuid_in_str(char *str);

void ibeacon_parse_factoryid(char *strptr, uint32_t size);
void ibeacon_parse_ibeaconuuid(char *strptr, uint32_t size);
void ibeacon_parse_major(char *strptr, uint32_t size);
void ibeacon_parse_minor(char *strptr, uint32_t size);
void ibeacon_parse_rssi(char *strptr, uint32_t size);

uint32_t ibeacon_ATDISI();

//internal helper functions

static inline char *FACTORYUUIDin(char *strptr)
{
	return (strptr+8);
}
static inline char *UUIDin(char *strptr)
{
	return (strptr+17);
}
static inline char *MAJORin(char *strptr)
{
	return (strptr+50);
}
static inline char *MINORin(char *strptr)
{
	return (strptr+54);
}
static inline char *MPin(char *strptr)
{
	return (strptr+58);
}
static inline char *MACin(char *strptr)
{
	return (strptr+61);
}
static inline char *RSSIin(char *strptr)
{
	return (strptr+74);
}
#endif
