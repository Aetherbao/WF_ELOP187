/*
* Copyright (c) 2016, SHENZHEN HANGSHENG ELECTRONICS Co.,Ltd.
* All Rights Reserved.
* Dept.: Software Department
* File: utils.c
* Description:
* History:
* 2016-6-3, 1007040, original
*/

#include "utils.h"
#include "stdint.h"

/*
 * Function:memoryCopy
 * Param<uint8_t *pScr>: source address data pointer
 * Param<uint8_t *pDst>: target address data pointer
 * Param<uint16_t dlc>: Copy data length, Max to 0xFFFFu
 * Return<void>:
 * Discription: memory copy
 * Note:
*/
void memoryCopy(uint8_t *pScr, uint8_t *pDst, uint16_t dlc)
{
    uint16_t dt_i = 0;

    if ((NULL != pScr) && (NULL != pDst))
    {
        for (; dt_i < dlc; dt_i++)
        {
            pDst[dt_i] = pScr[dt_i];
        }
    }
}

/* Standard CRC */

static const uint32_t crc32table[256] =
{
    0x00000000,0x77073096,0xEE0E612C,0x990951BA,0x076DC419,0x706AF48F,0xE963A535,
    0x9E6495A3,0x0EDB8832,0x79DCB8A4,0xE0D5E91E,0x97D2D988,0x09B64C2B,0x7EB17CBD,
    0xE7B82D07,0x90BF1D91,0x1DB71064,0x6AB020F2,0xF3B97148,0x84BE41DE,0x1ADAD47D,
    0x6DDDE4EB,0xF4D4B551,0x83D385C7,0x136C9856,0x646BA8C0,0xFD62F97A,0x8A65C9EC,
    0x14015C4F,0x63066CD9,0xFA0F3D63,0x8D080DF5,0x3B6E20C8,0x4C69105E,0xD56041E4,
    0xA2677172,0x3C03E4D1,0x4B04D447,0xD20D85FD,0xA50AB56B,0x35B5A8FA,0x42B2986C,
    0xDBBBC9D6,0xACBCF940,0x32D86CE3,0x45DF5C75,0xDCD60DCF,0xABD13D59,0x26D930AC,
    0x51DE003A,0xC8D75180,0xBFD06116,0x21B4F4B5,0x56B3C423,0xCFBA9599,0xB8BDA50F,
    0x2802B89E,0x5F058808,0xC60CD9B2,0xB10BE924,0x2F6F7C87,0x58684C11,0xC1611DAB,
    0xB6662D3D,0x76DC4190,0x01DB7106,0x98D220BC,0xEFD5102A,0x71B18589,0x06B6B51F,
    0x9FBFE4A5,0xE8B8D433,0x7807C9A2,0x0F00F934,0x9609A88E,0xE10E9818,0x7F6A0DBB,
    0x086D3D2D,0x91646C97,0xE6635C01,0x6B6B51F4,0x1C6C6162,0x856530D8,0xF262004E,
    0x6C0695ED,0x1B01A57B,0x8208F4C1,0xF50FC457,0x65B0D9C6,0x12B7E950,0x8BBEB8EA,
    0xFCB9887C,0x62DD1DDF,0x15DA2D49,0x8CD37CF3,0xFBD44C65,0x4DB26158,0x3AB551CE,
    0xA3BC0074,0xD4BB30E2,0x4ADFA541,0x3DD895D7,0xA4D1C46D,0xD3D6F4FB,0x4369E96A,
    0x346ED9FC,0xAD678846,0xDA60B8D0,0x44042D73,0x33031DE5,0xAA0A4C5F,0xDD0D7CC9,
    0x5005713C,0x270241AA,0xBE0B1010,0xC90C2086,0x5768B525,0x206F85B3,0xB966D409,
    0xCE61E49F,0x5EDEF90E,0x29D9C998,0xB0D09822,0xC7D7A8B4,0x59B33D17,0x2EB40D81,
    0xB7BD5C3B,0xC0BA6CAD,0xEDB88320,0x9ABFB3B6,0x03B6E20C,0x74B1D29A,0xEAD54739,
    0x9DD277AF,0x04DB2615,0x73DC1683,0xE3630B12,0x94643B84,0x0D6D6A3E,0x7A6A5AA8,
    0xE40ECF0B,0x9309FF9D,0x0A00AE27,0x7D079EB1,0xF00F9344,0x8708A3D2,0x1E01F268,
    0x6906C2FE,0xF762575D,0x806567CB,0x196C3671,0x6E6B06E7,0xFED41B76,0x89D32BE0,
    0x10DA7A5A,0x67DD4ACC,0xF9B9DF6F,0x8EBEEFF9,0x17B7BE43,0x60B08ED5,0xD6D6A3E8,
    0xA1D1937E,0x38D8C2C4,0x4FDFF252,0xD1BB67F1,0xA6BC5767,0x3FB506DD,0x48B2364B,
    0xD80D2BDA,0xAF0A1B4C,0x36034AF6,0x41047A60,0xDF60EFC3,0xA867DF55,0x316E8EEF,
    0x4669BE79,0xCB61B38C,0xBC66831A,0x256FD2A0,0x5268E236,0xCC0C7795,0xBB0B4703,
    0x220216B9,0x5505262F,0xC5BA3BBE,0xB2BD0B28,0x2BB45A92,0x5CB36A04,0xC2D7FFA7,
    0xB5D0CF31,0x2CD99E8B,0x5BDEAE1D,0x9B64C2B0,0xEC63F226,0x756AA39C,0x026D930A,
    0x9C0906A9,0xEB0E363F,0x72076785,0x05005713,0x95BF4A82,0xE2B87A14,0x7BB12BAE,
    0x0CB61B38,0x92D28E9B,0xE5D5BE0D,0x7CDCEFB7,0x0BDBDF21,0x86D3D2D4,0xF1D4E242,
    0x68DDB3F8,0x1FDA836E,0x81BE16CD,0xF6B9265B,0x6FB077E1,0x18B74777,0x88085AE6,
    0xFF0F6A70,0x66063BCA,0x11010B5C,0x8F659EFF,0xF862AE69,0x616BFFD3,0x166CCF45,
    0xA00AE278,0xD70DD2EE,0x4E048354,0x3903B3C2,0xA7672661,0xD06016F7,0x4969474D,
    0x3E6E77DB,0xAED16A4A,0xD9D65ADC,0x40DF0B66,0x37D83BF0,0xA9BCAE53,0xDEBB9EC5,
    0x47B2CF7F,0x30B5FFE9,0xBDBDF21C,0xCABAC28A,0x53B39330,0x24B4A3A6,0xBAD03605,
    0xCDD70693,0x54DE5729,0x23D967BF,0xB3667A2E,0xC4614AB8,0x5D681B02,0x2A6F2B94,
    0xB40BBE37,0xC30C8EA1,0x5A05DF1B,0x2D02EF8D
};

/*
 * Function:crc32
 * Param<uint32_t seed>: Initial seed for calculator CRC32 value. can used last block calculator CRC32 value
 * Param<uint8_t ckDatas[]>: Current need calculator CRC32 value data block
 * Param<uint32_t dlc>: Current need calculator CRC32 value data length
 * Return<uint32_t>: CRC32 result
 * REQ IDs:
 * Discription:
 * Note:
*/
uint32_t crc32_discrete(uint32_t seed, uint8_t ckDatas[], uint32_t dlc)
{
    uint32_t dt_i = 0;
    uint32_t crc32value = seed ^ 0xFFFFFFFF;

    for (; dt_i < dlc; dt_i++)
    {
        crc32value = crc32table[(uint8_t)((crc32value ^ ckDatas[dt_i]) & 0x00FFu)] ^ (crc32value >> 8);
    }
    return crc32value ^ 0xFFFFFFFF;
}

/*
 * Function:crc32
 * Param<uint8_t ckDatas[]>: Current need calculator CRC32 value data block
 * Param<uint32_t dlc>:  Current need calculator CRC32 value data length
 * Return<uint32_t>: CRC32 result
 * Discription: This function as same as crc32_discrete with seed 0ul.
 * Note:
*/
uint32_t crc32(uint8_t ckDatas[], uint32_t dlc)
{
    uint32_t dt_i = 0;
    uint32_t crc32value = 0xFFFFFFFF;

    for (; dt_i < dlc; dt_i++)
    {
        crc32value = crc32table[(uint8_t)((crc32value ^ ckDatas[dt_i]) & 0x00FFu)] ^ (crc32value >> 8);
    }
    return (uint32_t)(crc32value ^ 0xFFFFFFFF);
}


static const uint16_t crc16table[256] =
{
    0x0000U, 0x1189U, 0x2312U, 0x329BU, 0x4624U, 0x57ADU, 0x6536U, 0x74BFU,
    0x8C48U, 0x9DC1U, 0xAF5AU, 0xBED3U, 0xCA6CU, 0xDBE5U, 0xE97EU, 0xF8F7U,
    0x1081U, 0x0108U, 0x3393U, 0x221AU, 0x56A5U, 0x472CU, 0x75B7U, 0x643EU,
    0x9CC9U, 0x8D40U, 0xBFDBU, 0xAE52U, 0xDAEDU, 0xCB64U, 0xF9FFU, 0xE876U,
    0x2102U, 0x308BU, 0x0210U, 0x1399U, 0x6726U, 0x76AFU, 0x4434U, 0x55BDU,
    0xAD4AU, 0xBCC3U, 0x8E58U, 0x9FD1U, 0xEB6EU, 0xFAE7U, 0xC87CU, 0xD9F5U,
    0x3183U, 0x200AU, 0x1291U, 0x0318U, 0x77A7U, 0x662EU, 0x54B5U, 0x453CU,
    0xBDCBU, 0xAC42U, 0x9ED9U, 0x8F50U, 0xFBEFU, 0xEA66U, 0xD8FDU, 0xC974U,
    0x4204U, 0x538DU, 0x6116U, 0x709FU, 0x0420U, 0x15A9U, 0x2732U, 0x36BBU,
    0xCE4CU, 0xDFC5U, 0xED5EU, 0xFCD7U, 0x8868U, 0x99E1U, 0xAB7AU, 0xBAF3U,
    0x5285U, 0x430CU, 0x7197U, 0x601EU, 0x14A1U, 0x0528U, 0x37B3U, 0x263AU,
    0xDECDU, 0xCF44U, 0xFDDFU, 0xEC56U, 0x98E9U, 0x8960U, 0xBBFBU, 0xAA72U,
    0x6306U, 0x728FU, 0x4014U, 0x519DU, 0x2522U, 0x34ABU, 0x0630U, 0x17B9U,
    0xEF4EU, 0xFEC7U, 0xCC5CU, 0xDDD5U, 0xA96AU, 0xB8E3U, 0x8A78U, 0x9BF1U,
    0x7387U, 0x620EU, 0x5095U, 0x411CU, 0x35A3U, 0x242AU, 0x16B1U, 0x0738U,
    0xFFCFU, 0xEE46U, 0xDCDDU, 0xCD54U, 0xB9EBU, 0xA862U, 0x9AF9U, 0x8B70U,
    0x8408U, 0x9581U, 0xA71AU, 0xB693U, 0xC22CU, 0xD3A5U, 0xE13EU, 0xF0B7U,
    0x0840U, 0x19C9U, 0x2B52U, 0x3ADBU, 0x4E64U, 0x5FEDU, 0x6D76U, 0x7CFFU,
    0x9489U, 0x8500U, 0xB79BU, 0xA612U, 0xD2ADU, 0xC324U, 0xF1BFU, 0xE036U,
    0x18C1U, 0x0948U, 0x3BD3U, 0x2A5AU, 0x5EE5U, 0x4F6CU, 0x7DF7U, 0x6C7EU,
    0xA50AU, 0xB483U, 0x8618U, 0x9791U, 0xE32EU, 0xF2A7U, 0xC03CU, 0xD1B5U,
    0x2942U, 0x38CBU, 0x0A50U, 0x1BD9U, 0x6F66U, 0x7EEFU, 0x4C74U, 0x5DFDU,
    0xB58BU, 0xA402U, 0x9699U, 0x8710U, 0xF3AFU, 0xE226U, 0xD0BDU, 0xC134U,
    0x39C3U, 0x284AU, 0x1AD1U, 0x0B58U, 0x7FE7U, 0x6E6EU, 0x5CF5U, 0x4D7CU,
    0xC60CU, 0xD785U, 0xE51EU, 0xF497U, 0x8028U, 0x91A1U, 0xA33AU, 0xB2B3U,
    0x4A44U, 0x5BCDU, 0x6956U, 0x78DFU, 0x0C60U, 0x1DE9U, 0x2F72U, 0x3EFBU,
    0xD68DU, 0xC704U, 0xF59FU, 0xE416U, 0x90A9U, 0x8120U, 0xB3BBU, 0xA232U,
    0x5AC5U, 0x4B4CU, 0x79D7U, 0x685EU, 0x1CE1U, 0x0D68U, 0x3FF3U, 0x2E7AU,
    0xE70EU, 0xF687U, 0xC41CU, 0xD595U, 0xA12AU, 0xB0A3U, 0x8238U, 0x93B1U,
    0x6B46U, 0x7ACFU, 0x4854U, 0x59DDU, 0x2D62U, 0x3CEBU, 0x0E70U, 0x1FF9U,
    0xF78FU, 0xE606U, 0xD49DU, 0xC514U, 0xB1ABU, 0xA022U, 0x92B9U, 0x8330U,
    0x7BC7U, 0x6A4EU, 0x58D5U, 0x495CU, 0x3DE3U, 0x2C6AU, 0x1EF1U, 0x0F78U
};

/*
 * Function:crc16_discrete
 * Param<uint16_t seed>: Initial seed for calculator CRC16 value. can used last block calculator CRC16 value
 * Param<uint8_t ckDatas[]>: Current need calculator CRC16 value data block
 * Param<uint16_t dlc>: Current need calculator CRC16 value data length
 * Return<uint16_t>: CRC16 result
 * Discription:
 * Note:
*/
uint16_t crc16_discrete(uint16_t seed, uint8_t ckDatas[], uint16_t dlc)
{
    uint16_t dt_i = 0;
    uint16_t crc16value = seed ^ 0xFFFFu;

    for (; dt_i < dlc; dt_i++)
    {
    	crc16value = crc16table[(uint8_t)((crc16value ^ ckDatas[dt_i]) & 0xFFu)] ^ (crc16value >> 8);
    }

    return (uint16_t)(crc16value ^ 0xFFFFu);
}

/*
 * Function:crc16
 * Param<uint8_t ckDatas[]>: Current need calculator CRC16 value data block
 * Param<uint16_t dlc>: Current need calculator CRC16 value data length
 * Return<uint16_t>: CRC16 result
 * Discription: This function as same as crc16_discrete with seed 0u.
 * Note:
*/
uint16_t crc16(uint8_t ckDatas[], uint16_t dlc)
{
    uint16_t dt_i = 0;
    uint16_t crc16value = 0xFFFFu;

    for (; dt_i < dlc; dt_i++)
    {
        crc16value = crc16table[(uint8_t)((crc16value ^ ckDatas[dt_i]) & 0xFFu)] ^ (crc16value >> 8);
    }

    return (uint16_t)(crc16value ^ 0xFFFFu);
}







