/****************************************************************************
 * Copyleft (L) 2021 CENG - All Rights Not Reserved
 * You may use, distribute and modify this code.
 ****************************************************************************/

 /**
  * @file CE103-HW2-Lib.c
  * @author Omer Polat
  * @date 16 November 2021
  *
  * @brief <b> HW-2 Functions </b>
  *
  * HW-2 Sample Lib Functions
  *
  * @see http://bilgisayar.mmf.erdogan.edu.tr/en/
  *
  */

#include "CE103-HW2-Lib.h"

  /**
   @name TestFunction(fnCE103HW2Lib)
	  @brief \b Auto Generated Test Function

	  Auto Generated Test Function Has Doxygen and Plantuml Integration

   Sample Web Page Link
   @see https://www.cplusplus.com/reference/cstring/strcpy/

   Sample Image AES Block Decryption Operation

   @image html aes_enc_dec.png
   @image rtf aes_enc_dec.png
   @image latex aes_enc_dec.png

   Sample Related Function Link
   @see TestFunction (fnCE103HW2Lib)
   <b> Plant UML Sample </b> <BR>
   @image html fnCE103HW2Lib.png
   @image rtf fnCE103HW2Lib.png
   @image latex fnCE103HW2Lib.png

   <!--

	  @startuml fnCE103HW2Lib.png

	  title Servlet Container

	  (*) --> "ClickServlet.handleRequest()"
	  --> "new Page"

	  if "Page.onSecurityCheck" then
		->[true] "Page.onInit()"

		if "isForward?" then
		 ->[no] "Process controls"

		 if "continue processing?" then
		   -->[yes] ===RENDERING===
		 else
		   -->[no] ===REDIRECT_CHECK===
		 endif

		else
		 -->[yes] ===RENDERING===
		endif

		if "is Post?" then
		  -->[yes] "Page.onPost()"
		  --> "Page.onRender()" as render
		  --> ===REDIRECT_CHECK===
		else
		  -->[no] "Page.onGet()"
		  --> render
		endif

	  else
		-->[false] ===REDIRECT_CHECK===
	  endif

	  if "Do redirect?" then
	   ->[yes] "redirect request"
	   --> ==BEFORE_DESTROY===
	  else
	   if "Do Forward?" then
		-left->[yes] "Forward request"
		--> ==BEFORE_DESTROY===
	   else
		-right->[no] "Render page template"
		--> ==BEFORE_DESTROY===
	   endif
	  endif

	  --> "Page.onDestroy()"
	  -->(*)
	  @enduml

   -->

	 @param [in] fia	[\b unsigned char*] Binary Data Input
	 @param [in] fib	[\b int] Binary Data Input Length
	 @param [out] fic	[\b char*] Hex String Output Array

	  @retval [\b int] operation result success 0 fail 1

	  Example Usage :

	   @code
		#include <stdio.h>
		#include <string.h>

		int main (){
		  unsigned char data[]="\x13\x13\x13x\13";
		 int dataLength = 4;
		  char dataHex[40];

		  if(fnCE103HW2Lib(data,dataLength,dataHex)!=0)
		 {
		   printf("Operation Failed!");
		   return -1;
		 }

		printf("Converted Data [%s]",dataHex);

		  return 0;
	   }
	  @endcode
  **/
int fnCE103HW2Lib(unsigned char* fia, int fib, char* fic)
{
	//Empty Body...
	return -1;
}

/**
*
*	  @name   fibonacciNumber (ce103_fibonacciNumber)
*
*	  @brief Fibonacci Number Calculator
*
*	  Calculates the fibonacci number in the given index and return as output
*
*	  @param  [in] fiIndex [\b int]  index of fibonacci number in the serie
*
*	  @retval [\b int] calculated fibonacci number
**/
int ce103_fibonacciNumber(int fiIndex)
{
	//TODO:Start from Here...
/*
		the value of i should start from 1 and increase to findex
		the third value is the sum of the first and second values.
		the first value is equal to the second value,
		the second value is equal to the third value.
		return the first value 
	*/
	int first = 0, second = 1, third;
	for (int i = 1; i < fiIndex; i++)
	{
		third = first + second;
		first = second;
		second = third;
	}
	return first;
}
/**
	@name   strrev (ce103_strrev)

	@brief \b Reverse String

	Reverse given string

	@param [in] fiStr [\b char*] The given string which is needed to be reversed.

	@retval [\b char*] This function returns the string after reversing the given string
**/
char* ce103_strrev(char* fiStr)
{
	//TODO:Start from Here...
	char temp;
	int x, y, n;
	n = ce103_strlen(fiStr);

	// swapping fiStr[i] and fiStr[j] until i<j
	for (x = 0, y = n - 1; x < y; ++x, --y) {
		temp = fiStr[y];
		fiStr[y] = fiStr[x];
		fiStr[x] = temp;
	}

	return fiStr;
}

/**
	@name   strlen (ce103_strlen)
	@brief \b Get string length

	Returns the length of the C string str.

	The length of a C string is determined by the terminating null-character:
	A C string is as long as the number of characters between the beginning of
	the string and the terminating null character
	(without including the terminating null character itself).

	see more <a href="https://en.cppreference.com/w/c/string/byte/strlen">strlen reference 1</a>
	see more <a href="https://www.programiz.com/c-programming/library-function/string.h/strlen">strlen reference 2</a>
	see more <a href="https://www.cplusplus.com/reference/cstring/strlen/">strlen reference 3</a>

	@param [in] fiStr [\b const char*] pointer to the null-terminated byte string to be examined

	@retval [\b int] The length of the null-terminated byte string str.
**/
int ce103_strlen(const char* fiStr)
{
	//TODO:Start from Here...
	{
		const char* char_ptr;
		const unsigned long int* longword_ptr;
		unsigned long int longword, himagic, lomagic;
		/* Handle the first few characters by reading one character at a time.
		   Do this until CHAR_PTR is aligned on a longword boundary.  */
		for (char_ptr = fiStr; ((unsigned long int) char_ptr
			& (sizeof(longword) - 1)) != 0;
			++char_ptr)
			if (*char_ptr == '\0')
				return char_ptr - fiStr;
		/* All these elucidatory comments refer to 4-byte longwords,
		   but the theory applies equally well to 8-byte longwords.  */
		longword_ptr = (unsigned long int*) char_ptr;
		/* Bits 31, 24, 16, and 8 of this number are zero.  Call these bits
		   the "holes."  Note that there is a hole just to the left of
		   each byte, with an extra at the end:
		   bits:  01111110 11111110 11111110 11111111
		   bytes: AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD
		   The 1-bits make sure that carries propagate to the next 0-bit.
		   The 0-bits provide holes for carries to fall into.  */
		himagic = 0x80808080L;
		lomagic = 0x01010101L;
		if (sizeof(longword) > 4)
		{
			/* 64-bit version of the magic.  */
			/* Do the shift in two steps to avoid a warning if long has 32 bits.  */
			himagic = ((himagic << 16) << 16) | himagic;
			lomagic = ((lomagic << 16) << 16) | lomagic;
		}
		if (sizeof(longword) > 8)
			abort();
		/* Instead of the traditional loop which tests each character,
		   we will test a longword at a time.  The tricky part is testing
		   if *any of the four* bytes in the longword in question are zero.  */
		for (;;)
		{
			longword = *longword_ptr++;
			if (((longword - lomagic) & ~longword & himagic) != 0)
			{
				/* Which of the bytes was the zero?  If none of them were, it was
				   a misfire; continue the search.  */
				const char* cp = (const char*)(longword_ptr - 1);
				if (cp[0] == 0)
					return cp - fiStr;
				if (cp[1] == 0)
					return cp - fiStr + 1;
				if (cp[2] == 0)
					return cp - fiStr + 2;
				if (cp[3] == 0)
					return cp - fiStr + 3;
				if (sizeof(longword) > 4)
				{
					if (cp[4] == 0)
						return cp - fiStr + 4;
					if (cp[5] == 0)
						return cp - fiStr + 5;
					if (cp[6] == 0)
						return cp - +6;
					if (cp[7] == 0)
						return cp - fiStr + 7;
				}
			}
		}
	}




	;
}


/**
	@name   strcat (ce103_strcat)
	@brief \b Concatenate strings

	Appends a copy of the null-terminated byte string pointed to by src to the end of the null-terminated byte string pointed to by dest

	The character src[0] replaces the null terminator at the end of dest. The resulting byte string is null-terminated.

	The behavior is undefined if the destination array is not large enough for the contents of
	both src and dest and the terminating null character. The behavior is undefined if the strings overlap.
	The behavior is undefined if either dest or src is not a pointer to a null-terminated byte string.

	see more <a href="https://en.cppreference.com/w/c/string/byte/strcat">strcat reference</a>
	see more <a href="https://www.cplusplus.com/reference/cstring/strcat/">strcat reference</a>

	@param  [in] fiDest [\b char*] pointer to the null-terminated byte string to append to
	@param  [in] fiSrc  [\b char*] pointer to the null-terminated byte string to copy from

	@retval [\b char*] returns a copy of dest
**/
char* ce103_strcat(char* fiDest, char* fiSrc)
{
	//TODO:Start from Here...
	/*
		synchronize the cp value for this fidest
		as long as there is a cp value, we increase the cp value and increase the cp and FISRC.
		In this way, the first string and the second string (Fidest) are copied.
	*/

	char* cp = fiDest;

	while (*cp)

		cp++;

	while (*cp++ = *fiSrc++);

	return(fiDest);
}

	



/**
	@name   strcmp (ce103_strcmp)
	@brief  \b Compare two strings

	Compares two null-terminated byte strings lexicographically.

	The sign of the result is the sign of the difference between
	the values of the first pair of characters (both interpreted as unsigned char)
	that differ in the strings being compared.The behavior is undefined
	if lhs or rhs are not pointers to null-terminated byte strings.

	see more <a href="https://en.cppreference.com/w/c/string/byte/strcmp">strcmp reference</a>
	see more <a href="https://www.cplusplus.com/reference/cstring/strcmp/">strcmp reference</a>

	@param  [in] fiLhs [\b const char*] pointers to the null-terminated byte strings to compare
	@param  [in] fiRhs [\b const char*] pointers to the null-terminated byte strings to compare

	@retval [\b int] Negative value if lhs appears before rhs in lexicographical order.
			Zero if lhs and rhs compare equal.
			Positive value if lhs appears after rhs in lexicographical order.
**/
int ce103_strcmp(const char* fiLhs, const char* fiRhs)
{
	//TODO:Start from Here...
	int ret;
	/*
		if the filhs characters are equal to the firhs
		if the words are the same, they both increase 
		During the return, the elephant is removed from the fihrs (0 - 0 = 0 is returned.) Words are not the same.
	*/
	while (*fiLhs && (*fiLhs == *fiRhs)) {
		fiLhs++;
		fiRhs++;
	}
	return *fiLhs - *fiRhs;
}

/**
*
	@name  strcpy (ce103_strcpy)
	@brief \b Copy string

	Copies the C string pointed by source into the array pointed by destination,
	including the terminating null character (and stopping at that point).

	To avoid overflows, the size of the array pointed by destination shall be long enough to contain
	the same C string as source (including the terminating null character),
	and should not overlap in memory with source.

	see more <a href="https://en.cppreference.com/w/c/string/byte/strcpy">strcpy reference 1</a>
	see more <a href="https://www.cplusplus.com/reference/cstring/strcpy/">strcpy reference 2</a>

	@param [out] foDestination	[\b char*]			Pointer to the destination array where the content is to be copied.
	@param [in]  fiSource		[\b const char*]	C string to be copied.

	@retval returns a copy of dest
**/
char* ce103_strcpy(char* foDestination, const char* fiSource)
{
	//TODO:Start from Here...
/*
		The variable p is set to foDestination.
	If the value of fiSource is set, foDestination is set to the character of the fiSource.
	As a result, fiSource is returned as a string.
	*/
	char* p = foDestination;
	while (*fiSource)
	{
		*foDestination++ = *fiSource++;
	}
	*foDestination = '\0';
	return p;
}

/**
 * @name    hex2bin (ce103_hex2bin)
 * @brief   \b Hexadecimal to Binary (BCD)  Conversion
 *
 * Hexadecimal to Binary (BCD)  Conversion
 * Packs hexadecimal string to packed binary array, Example: "AB1234" => 0xAB 0x12 0x34
 * If length of the input string is less than the fiHexLen,remaining bytes is not filled.
 * If odd number of characters processed, last nibble is padded with 0
 *
 * @param   [in]  fiHex    [\b unsigned char*] Ascii hex string.
 * @param   [in]  fiHexLen [\b int]     Ascii data length.
 * @param  [out]  foBin    [\b char*]   Convertion result as binary.
 */
void ce103_hex2bin(char* fiHex, int fiHexLen, unsigned char* foBin)
{
	//TODO:Start from Here...
	/*	we have defined two variables. fihex equal to c.
		stop the process if c equal to zero.
		if the value of c is greater than 96, subtract the value of c from 87, if not, proceed to the next step
		if the value of c is greater than 64, subtract the value of c from 55, if not, subtrac the value of c from 48.
		fihex equal to d. if d equal to zero, equalize c to fobin in a 4th system stop the process.
		if the value of d is greater than 96, subtract the value of d from 87, if not, proceed to the next step
		if the value of d is greater than 64, subtract the value of d from 55, if not, subtrac the value of d from 48.
		In the 4th system, the value of c or d equals fobin++.
		return fihex
		
	*/
	int c, d;
	for (;;) {
		c = *fiHex++; if (c == 0) break;
		if (c > 96) c -= 87;
		else if (c > 64) c -= 55;
		else c -= 48;
		d = *fiHex++; if (d == 0) { *foBin = c << 4; break; }
		if (d > 96) d -= 87;
		else if (d > 64) d -= 55;
		else d -= 48;
		*foBin++ = (c << 4) | d;
	}
	return fiHex;
}
/**
* @name    bin2hex (ce103_bin2hex)
* @brief   \b Binary (BCD) to Hexadecimal Conversion
*
* Unpacks alpha numeric value, Example: 0x12 0x34 = "1234".
*
* @param [in]  fiBin      [\b unsigned char*]    Binary data to be converted.
* @param [in]  fiBinLen   [\b int]				 Binary data length.
* @param [out] foHex      [\b char*]			 Convertion result as ascii. Doubles the binary length.
*
*/
void ce103_bin2hex(unsigned char* fiBin, int fiBinLen, char* foHex)
{
	//TODO:Start from Here...
	/* define the values c, d, and end
	 In the process where the fiBin is smaller than the end, it is added to the FIBIN.
	 to convert values to hex code,
	 if d bigger than 9 add 55, if not add 48.
	 4 is added or subtracted from the value of D.
	 the value of d is 15 minus or plus the value of C.
	 fohex equal to zero.
	 return fiBin
	*/
	int c, d, * end = fiBin + fiBinLen;
	while (fiBin < end) {
		c = *(fiBin++);
		d = c >> 4;
		*(foHex++) = d + (d > 9 ? 55 : 48);
		d = c & 15;
		*(foHex++) = d + (d > 9 ? 55 : 48);
	}
	*foHex = 0;
	return fiBin;
}
