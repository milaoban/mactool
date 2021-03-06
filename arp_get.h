#ifndef	_ARP_GET_
#define	_ARP_GET_

/*  arp_flags and at_flags field values */
#define ATF_INUSE   0x01    /* entry in use */
#define ATF_COM     0x02    /* completed entry (enaddr valid) */
#define ATF_PERM    0x04    /* permanent entry */
#define ATF_PUBL    0x08    /* publish entry (respond for other host) */
#define ATF_USETRAILERS 0x10    /* has requested trailers */
#define ATF_PROXY   0x20    /* Do PROXY arp */

#define MAC_LENGTH  18
#define IP_LENGTH   16

#define LOOKUP_URL_LENGTH	256
#define VENDOR_LENGTH		128

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(fmt, args...)    fprintf(stderr, fmt, ## args)
#else
#define DEBUG_PRINT(fmt, args...)    /* Don't do anything in release builds */
#endif

struct evhttp_request;

typedef void (*cb_http_response)(struct evhttp_request *, void *);

struct s_vendor {
	char *data;
	int	  vlen;
};

void make_http_get_request(const char *url,  cb_http_response callback, void *baton);

struct s_vendor *get_mac_vendor(const char *mac);

int arp_get_mac(const char *dev_name, const char *i_ip, char *o_mac);
int arp_get_ip(const char *dev_name, const char *i_mac, char *o_ip);

#endif
