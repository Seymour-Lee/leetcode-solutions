/* icmp_checksum.c */
/*
 * sample code to calculate checksum of an ICMP packet.
 */

/*
* This code "USC CSci551 SP2019 Practical Project" is
* Copyright (C) 2019 by Guillermo Baltra.
* All rights reserved.
*
* This program is released ONLY for the purposes of Spring 2019 CSci551
* students who wish to use it as part of their project assignments.
* Use for another other purpose requires prior written approval by
* Guillermo Baltra.
*
* Use in CSci551 is permitted only provided that ALL copyright notices
* are maintained and that this code is distinguished from new
* (student-added) code as much as possible.  We new services to be
* placed in separate (new) files as much as possible.  If you add
* significant code to existing files, identify your new code with
* comments.
*
* As per class assignments, use of any code OTHER than this provided
* code requires explicit approval, ahead of time, by the professor.
*
*/

#include <stdio.h>


// From RFC 1071
unsigned short checksum(char *addr, short count)
{
       /* Compute Internet Checksum for "count" bytes
        *         beginning at location "addr".
        */
       register long sum = 0;

        while( count > 1 )  {
           /*  This is the inner loop */
               sum += *(unsigned short *) addr;
	       addr += 2;
               count -= 2;
       }

           /*  Add left-over byte, if any */
       if( count > 0 )
               sum += * (unsigned char *) addr;

           /*  Fold 32-bit sum to 16 bits */
       while (sum>>16)
           sum = (sum & 0xffff) + (sum >> 16);

       return (unsigned short) ~sum;
}


int main(int argc, char** argv)
{
	/*
	 * For a real proja, make sure you understand ICMP format, and how checksum is calculated.
	 */
	char packet[] = {0x1, 0x2, 0x3, 0x4};
	unsigned short chksum = checksum(packet, 4);
	printf("checksum: %hu\n", chksum);
  	return 0;
}

