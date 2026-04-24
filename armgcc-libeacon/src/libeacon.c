#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include <libeacon.h>
static inline char *FACTORYUUIDin(char *strptr);
static inline char *UUIDin(char *strptr);
static inline char *MAJORin(char *strptr);
static inline char *MINORin(char *strptr);
static inline char *MPin(char *strptr);
static inline char *MACin(char *strptr);
static inline char *RSSIin(char *strptr);

//OK+DISC:4C000215:74278BDAB64445208F0C720EAF059935:0AEA0026C5:685E1C1A68F3:-063
//OK+DISC:4C000215:74278BDAB64445208F0C720EAF059935:0AEA0037C5:685E1C1A5F78:-066
//OK+DISC:4C000215:74278BDAB64445208F0C720EAF059935:0AEA0032C5:685E1C1A5341:-051

char atbufferone[sizeofatbufferone];
char atbuffertwo[sizeofatbuffertwo];
volatile uint32_t atbufferoneIndex = 0;
//char ibeacon_target_factoryid_str[17] = "OK+DISC:00000000";
char ibeacon_target_factoryid_str[9] = "00000000";
char ibeacon_target_ibeaconuuid_str[33] = "00000000000000000000000000000000";

char ibeacon_target_major_str[5] = "0000";
char ibeacon_target_minor_str[5] = "0000";
char ibeacon_target_mp_str[3] = "00";
char ibeacon_target_mac_str[13] = "000000000000";
char ibeacon_target_rssi_str[5] = "0000";

char ibeacon_target_majorminor_str[9] = "00000000";

char ibeacon_majorminor_list[IBEACONS_LIST_SIZE][8+1] = {
"0AEA0037",
"0AEA0026",
"0AEA0032",
"00000000",
"00000000",
"00000000",
"00000000",
"00000000",
"00000000",
"00000000",
"00000000",
"00000000",
"00000000",
"00000000",
"00000000" };
uint32_t majorminor_MATCHED = 0;
uint32_t rssi_treshold_MATCHED = 0;
uint32_t target = 0;

void ibeacon_init_next_target(void)
{
	if (target >= IBEACONS_LIST_SIZE)
	{
		//should not happen
		printf("target overflow in ibeacon_init_next_target()");
	}
	if (majorminor_MATCHED && rssi_treshold_MATCHED)
	{
		target++;
		for (uint32_t i=0; i < _MAJORsize+_MINORsize; i++)
			ibeacon_target_majorminor_str[i] = ibeacon_majorminor_list[target][i];
		majorminor_MATCHED = 0;
		rssi_treshold_MATCHED = 0;
	}
}
void nprintf(char *str, uint32_t size)
{
	uint32_t i = 0;
	while (str[i] && i < size)
		printf("%c", str[i++]);
	printf("\n");
}
void ibeacon_init()
{
	//init first major_str
	for (uint32_t i=0; i < _MAJORsize+_MINORsize; i++)
		ibeacon_target_majorminor_str[i] = ibeacon_majorminor_list[0][i];

//this function is not needed, there should be a function that receives input from admin mode
//and initializes ibeacon_majorminor_list[] or something like that
//
//this is a placeholder
//	strncpy(ibeacon_target_factoryid_str,	_IBEACON_TARGET_FACTORYID,	_FACTORYUUIDsize);
//	strncpy(ibeacon_target_ibeaconuuid_str,	_IBEACON_TARGET_UUID,		_UUIDsize);
//	strncpy(ibeacon_target_major_str,		_IBEACON_TARGET_MAJOR,		_MAJORsize);
//	strncpy(ibeacon_target_minor_str,		_IBEACON_TARGET_MINOR,		_MINORsize);
//	strncpy(ibeacon_target_mp_str,			_IBEACON_TARGET_MP,			_MPsize);
//	strncpy(ibeacon_target_mac_str,			_IBEACON_TARGET_MAC,		_MACsize);
//	strncpy(ibeacon_target_rssi_str,		_IBEACON_TARGET_RSSI,		_RSSIsize);
}
char *ibeacon_find_first_uuid_in_str(char *str)
{
	while (strncmp("OK+DISC", str, 7))
		str++;
	return(str);
}
void ibeacon_parse_factoryid(char *strptr, uint32_t size)
{
	char *strptr_backup = strptr;
	uint32_t i = 0;
	uint32_t loop = 1;
	while (loop && i < size)
	{
		printf("i in ibeacon_parse_factoryid = %ld\n", i);
		if (strncmp(FACTORYUUIDin(strptr), ibeacon_target_factoryid_str, _FACTORYUUIDsize))
		{
			strptr += 80;
			i = strptr - strptr_backup;
		}
		else
		{
			//do something
			printf("Matched factoryid %s ibeacon_target_factoryid_str\n", ibeacon_target_factoryid_str);
			loop = 0;
		}
	}
	if (loop)
		printf("cant match %s in ibeacon_parse_factoryid()\n", ibeacon_target_factoryid_str);
	printf("exiting ibeacon_parse_factoryid\n");

}
void ibeacon_parse_ibeaconuuid(char *strptr, uint32_t size)
{
	char *strptr_backup = strptr;
	uint32_t i = 0;
	uint32_t loop = 1;
	while (loop && i < size)
	{
		if (strncmp(UUIDin(strptr), ibeacon_target_ibeaconuuid_str, _UUIDsize))
		{
			strptr += 80;
			i = strptr - strptr_backup;
		}
		else
		{
			//do something here
			printf("Matched ibeaconuuid %s in ibeacon_target_ibeaconuuid_str()\n", ibeacon_target_ibeaconuuid_str);
			loop = 0;
		}
	}
	if (loop)
		printf("cant match ibeaconuuid %s in ibeacon_parse_ibeaconuuid()\n", ibeacon_target_ibeaconuuid_str);
	printf("exiting ibeacon_parse_ibeaconuuid\n");
}
char *ibeacon_parse_majorminor(char *strptr, uint32_t size)
{
	char *strptr_backup = strptr;
	uint32_t i = 0;
	uint32_t loop = 1;
	while (loop && i < size)
	{
		if (strncmp(MAJORin(strptr), ibeacon_target_majorminor_str, _MAJORsize+_MINORsize))
		{
			strptr += 80;
			i = strptr - strptr_backup;
		}
		else
		{
		#ifdef DEBUG
		printf("target=%ld\n", target);
		printf("Matched majorminor %s in ibeacon_target_majorminor()\n", ibeacon_target_majorminor_str);
		#endif //DEBUG
			//do something here
			majorminor_MATCHED=1;
		//	ibeacon_init_next_target();
			loop = 0;
		}
	}
	if (loop)
	{
	#ifdef DEBUG
	printf("cant match majorminor %s in ibeacon_parse_major()\n", ibeacon_target_majorminor_str);
	printf("target=%ld\n", target);
	#endif //DEBUG
		return (NULL);
	}
	return (strptr);	//return pointer to string here
	printf("exiting ibeacon_parse_major\n");
}
char *ibeacon_parse_major(char *strptr, uint32_t size)
//this function will return pointer to whole string so we can get IRSS
{
	char *strptr_backup = strptr;
	uint32_t i = 0;
	uint32_t loop = 1;
	while (loop && i < size)
	{
		if (strncmp(MAJORin(strptr), ibeacon_target_major_str, _MAJORsize))
		{
			strptr += 80;
			i = strptr - strptr_backup;
		}
		else
		{
			//do something here
			printf("target=%ld\n", target);
			printf("Matched major %s in ibeacon_target_major_str()\n", ibeacon_target_major_str);
			majorminor_MATCHED=1;
			ibeacon_init_next_target();
			loop = 0;
		}
	}
	if (loop)
	{
		printf("cant match major %s in ibeacon_parse_major()\n", ibeacon_target_major_str);
		printf("target=%ld\n", target);
		return (NULL);
	}
	return (strptr);	//return pointer to string here
	printf("exiting ibeacon_parse_major\n");
}
void ibeacon_parse_minor(char *strptr, uint32_t size)
{
	char *strptr_backup = strptr;
	uint32_t i = 0;
	uint32_t loop = 1;
	while (loop && i < size)
	{
		if (strncmp(MINORin(strptr), ibeacon_target_minor_str, _MINORsize))
		{
			strptr += 80;
			i = strptr - strptr_backup;
		}
		else
		{
			//do something here
			printf("Matched minor %s in ibeacon_target_minor_str()\n", ibeacon_target_minor_str);
			loop = 0;
		}
	}
	if (loop)
		printf("cant match minor %s in ibeacon_parse_minor()\n", ibeacon_target_minor_str);
	printf("exiting ibeacon_parse_minor\n");
}

void ibeacon_parse_mp(char *strptr, uint32_t size)
{
	char *strptr_backup = strptr;
	uint32_t i = 0;
	uint32_t loop = 1;
	while (loop && i < size)
	{
		if (strncmp(MPin(strptr), ibeacon_target_mp_str, _MPsize))
		{
			strptr += 80;
			i = strptr - strptr_backup;
		}
		else
		{
			//do something here
			printf("Matched mp %s in ibeacon_target_mp_str()\n", ibeacon_target_mp_str);
			loop = 0;
		}
	}
	if (loop)
		printf("cant match mp in ibeacon_parse_mp()\n");
	printf("exiting ibeacon_parse_mp\n");
}
void ibeacon_parse_mac(char *strptr, uint32_t size)
{
	char *strptr_backup = strptr;
	uint32_t i = 0;
	uint32_t loop = 1;
	while (loop && i < size)
	{
		if (strncmp(MACin(strptr), ibeacon_target_mac_str, _MACsize))
		{
			strptr += 80;
			i = strptr - strptr_backup;
		}
		else
		{
			//do something here
			printf("Matched mac %s in ibeacon_target_mac_str()\n", ibeacon_target_mac_str);
			loop = 0;
		}
	}
	if (loop)
		printf("cant match mac %s in ibeacon_parse_mac()\n", ibeacon_target_mac_str);
	printf("exiting ibeacon_parse_mac\n");
}
void ibeacon_parse_rssi(char *strptr, uint32_t size)
{
	char *strptr_backup = strptr;
	uint32_t i = 0;
	uint32_t loop = 1;
	while (loop && i < size)
	{
		if (strncmp(RSSIin(strptr), ibeacon_target_rssi_str, _RSSIsize))
		{
			strptr += 80;
			i = strptr - strptr_backup;
		}
		else
		{
			//do something here
			printf("Matched rssi %s in ibeacon_target_rssi_str()\n", ibeacon_target_rssi_str);
			loop = 0;
		}
	}
	if (loop)
		printf("cant match rssi %s in ibeacon_parse_rssi()\n", ibeacon_target_rssi_str);
	printf("exiting ibeacon_parse_rssi\n");
}
void hexdump(char *p, uint32_t size, char *msg)
{
	printf(msg);
	for (uint32_t i = 0, row = 0; i < size; i++)
	{
		char c = *(p+i);
		char c1 = ((c & 0xF0)>>4);
		char c2 = (c & 0x0F);

		c1 += c1 > 9 ? 55 : 48;
		c2 += c2 > 9 ? 55 : 48;
		printf("%c", c1);
		printf("%c", c2);
		row++;

		if (row > 7)
		{
			printf("\n");
			row = 0;
		}
	}
		printf("\n");
}
uint32_t ibeacon_ATDISI()
{
	if (atbufferoneIndex > 9)
	{
	    if (!strncmp(ATCOMMANDSUCCESS, (char *)(atbufferone+(atbufferoneIndex-10)), 10))
	    {
			atbufferone[atbufferoneIndex] = '\0';
//			ibeacon_parse_factoryid(ibeacon_find_first_uuid_in_str(atbufferone), atbufferoneIndex);
//			ibeacon_parse_ibeaconuuid(ibeacon_find_first_uuid_in_str(atbufferone), atbufferoneIndex);
			char *strptr = ibeacon_parse_majorminor(ibeacon_find_first_uuid_in_str(atbufferone), atbufferoneIndex);
				if (NULL != strptr)
				{
				#ifdef DEBUG
				nprintf(RSSIin(strptr)+1, 4);
				#endif //DEBUG
					int32_t rssiInStr = strtol(RSSIin(strptr)+1, NULL, 10);
					if (rssiInStr > RSSI_TRESHOLD)
					{
						printf("distance to next ibeacon(%s) is to big(%ld, %d)\n", ibeacon_target_majorminor_str, rssiInStr, RSSI_TRESHOLD);
					}
					else
					{
						printf("distance to next ibeacon(%s) is to fine(%ld, %d)\n", ibeacon_target_majorminor_str, rssiInStr, RSSI_TRESHOLD);
						rssi_treshold_MATCHED=1;
						ibeacon_init_next_target();
					}
				}
//			ibeacon_parse_minor(ibeacon_find_first_uuid_in_str(atbufferone), atbufferoneIndex);
//			ibeacon_parse_mp(ibeacon_find_first_uuid_in_str(atbufferone), atbufferoneIndex);
//			ibeacon_parse_mac(ibeacon_find_first_uuid_in_str(atbufferone), atbufferoneIndex);
//			ibeacon_parse_rssi(ibeacon_find_first_uuid_in_str(atbufferone), atbufferoneIndex);
				printf(atbufferone);
				printf("atbufferoneIndex = %ld\n", atbufferoneIndex);
////				hexdump(atbufferone, atbufferoneIndex+1);
	        //goto parse-ibeacons or exit?
			atbufferoneIndex = 0;
	    }
		return (0);	//should return number of detected ibeacons
					//really?
	}
	else return (0);
}
