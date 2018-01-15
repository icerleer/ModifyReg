////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
/// @par 模块名
/// 
/// @par 相关文件
/// 
/// @par 功能详细描述
/// @par 多线程安全性
/// [否，说明]
/// @par 异常时安全性
/// [否，说明]
/// @note         -
/// @file         XXTEA.h
/// @brief        -
/// @author       Li.xl
/// @version      1.0
/// @date         2015/05/25
/// @todo         -
/// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "XXTEA.h"


#define     MX							(z>>5^y<<2) + (y>>3^z<<4)^(sum^y) + (k[p&3^e]^z)
#define     XXTEA_ALIGNMENT_BYTES       4

CXTeaCode::CXTeaCode(){
    
}

CXTeaCode::~CXTeaCode(){
    
}

size_t CXTeaCode::XXTEAGetBufferLength(size_t nLength, bool bIsEncode)
{
    if (true == bIsEncode) 
	{
        size_t nSize = nLength / XXTEA_ALIGNMENT_BYTES + (nLength % XXTEA_ALIGNMENT_BYTES  ? 1 : 0);
        return (nSize * XXTEA_ALIGNMENT_BYTES * 2 + 1);
    }
    else
	{
        return (nLength / 2 + 1);
    }
}

bool CXTeaCode::XXTEAEncode(char* lpDstBuffer, const char* lpSrcBuffer, size_t nLength, const XXTEA_TYPE* lpKey)
{
    long ret = 1;
    if (nLength > XXTEA_ALIGNMENT_BYTES && lpDstBuffer && lpSrcBuffer) {
        size_t nSize = nLength / XXTEA_ALIGNMENT_BYTES + (nLength % XXTEA_ALIGNMENT_BYTES  ? 1 : 0);
        char* data = (char*)malloc(nSize * XXTEA_ALIGNMENT_BYTES * 2);
        memset(data, 0, nSize * XXTEA_ALIGNMENT_BYTES * 2);
        memcpy(data, lpSrcBuffer, nLength);
        ret = btea((XXTEA_TYPE*)data, nSize, lpKey);
        memset(lpDstBuffer, 0, XXTEAGetBufferLength(nLength, true));
        StringToHex(data, (int)nSize * XXTEA_ALIGNMENT_BYTES, lpDstBuffer);
        free(data);
    }
    return (ret == 0);
}

bool CXTeaCode::XXTEADecode(char* lpDstBuffer, const char* lpSrcBuffer, size_t nLength, const XXTEA_TYPE* lpKey)
{
    long ret = 1;
    if (nLength > XXTEA_ALIGNMENT_BYTES * 2 && lpDstBuffer && lpSrcBuffer) {
        size_t nSize = XXTEAGetBufferLength(nLength, false);
        memset(lpDstBuffer, 0, nSize);
        HexToString(lpSrcBuffer, lpDstBuffer);
        ret = btea((XXTEA_TYPE*)lpDstBuffer, -((nSize - 1)/ XXTEA_ALIGNMENT_BYTES), lpKey);
    }
    return (ret == 0);
}

long CXTeaCode::btea(XXTEA_TYPE* v, long n, const XXTEA_TYPE* k)
{
    unsigned XXTEA_TYPE z, y;
    unsigned long sum = 0, e, DELTA = 0x9e3779b9;
    long p, q;
    if (n > 1) {          /* Coding Part */
        z = v[n-1];
        q = 6 + 52 / n;
        while (q-- > 0) {
            sum += DELTA;
            e = (sum >> 2) & 3;
            for (p = 0; p < n-1; ++p) y = v[p+1], z = v[p] += MX;
            y = v[0];
            z = v[n-1] += MX;
        }
        return 0;
    } else if (n < -1) {  /* Decoding Part */
        y = v[0];
        n = -n;
        q = 6 + 52 / n;
        sum = q * DELTA ;
        while (sum != 0) {
            e = (sum >> 2) & 3;
            for (p = n-1; p > 0; --p) z = v[p-1], y = v[p] -= MX;
            z = v[n-1];
            y = v[0] -= MX;
            sum -= DELTA;
        }
        return 0;
    }
    return 1;
}

void CXTeaCode::StringToHex(const char* surBuffer, int length, char* dstBuffer)
{
    for (int i = 0; i < length; i++)
    {
        sprintf(&dstBuffer[2*i], "%02X", (unsigned char)surBuffer[i]);
    }
    dstBuffer[2 * length] = '\0';
}

int CXTeaCode::HexToString(const char* surBuffer,  char* dstBuffer)
{
    size_t length = strlen((char*)surBuffer) ;
    for(int i = 0; i < length/2; i++)
    {
        int temp;
        sscanf(&surBuffer[2 * i], "%02X", &temp);
        dstBuffer[i] = (char)temp;
    }
    dstBuffer[length/2] = '\0';
    return (int)strlen((char*)dstBuffer);
}
