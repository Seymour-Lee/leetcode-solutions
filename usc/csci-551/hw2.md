Name: Yiming Li

Student ID: 2813-8007-46



1a. network interface

1b. (name binding) use DNS to translate

1c. unique

1d. localhost -> 127.0.0.1



2a. may improve the performance

2b. No

2c. WiFi does retransmission locally on the link, also overlaying it end-to-end. This does not violate the end-to-end argument.

2d. Policy based routing

2e. Routers store the policies in their own device

2f. The policy is in the router, not endpoint



3a. AS7

3b. peer-to-peer exports its routes and its customer routes

3c. AS2

3d. AS2 is AS5's provider, which would not be exported to its peers

3e. sibling to sibling

3f. (1, 2, 3)

3g. (1, 4, 3)

3h. AS6

3i. AS6 is a customer

3j. AS6 has two provider

3k. AS_PATH

3l. no



4a. RFC 792

4b. 

```
Echo or Echo Reply Message

    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |     Type      |     Code      |          Checksum             |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |           Identifier          |        Sequence Number        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |     Data ...
   +-+-+-+-+-
```

4c. Mac OSX

4d.

```C++
struct icmphdr
{
  u_int8_t type;		/* message type */
  u_int8_t code;		/* type sub-code */
  u_int16_t checksum;
  union
  {
    struct
    {
      u_int16_t	id;
      u_int16_t	sequence;
    } echo;			/* echo datagram */
    u_int32_t	gateway;	/* gateway address */
    struct
    {
      u_int16_t	__unused;
      u_int16_t	mtu;
    } frag;			/* path mtu discovery */
  } un;
};
```

4e. Yes

4f. It includes stdint.h to support different width of integers

4g. It uses union, which allows different packing rules

4h. Ubuntu

4i. 

```C++
struct tcphdr {
	__be16	source;
	__be16	dest;
	__be32	seq;
	__be32	ack_seq;
#if defined(__LITTLE_ENDIAN_BITFIELD)
	__u16	res1:4,
		doff:4,
		fin:1,
		syn:1,
		rst:1,
		psh:1,
		ack:1,
		urg:1,
		ece:1,
		cwr:1;
#elif defined(__BIG_ENDIAN_BITFIELD)
	__u16	doff:4,
		res1:4,
		cwr:1,
		ece:1,
		urg:1,
		ack:1,
		psh:1,
		rst:1,
		syn:1,
		fin:1;
#else
#error	"Adjust your <asm/byteorder.h> defines"
#endif	
	__be16	window;
	__sum16	check;
	__be16	urg_ptr;
};
```

4j. It includes <types.h>, which includes <stdint.h>, to handle portability



