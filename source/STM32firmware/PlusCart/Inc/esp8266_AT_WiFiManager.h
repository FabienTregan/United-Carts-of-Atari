/*
 * ESP8266 AT WiFi Manager templates based on:
 * https://github.com/tzapu/WiFiManager
 *
 */

#ifndef ESP8266_AT_WIFIMANAGER_H
#define	ESP8266_AT_WIFIMANAGER_H

#define GET_ROOT           " / "
#define GET_INDEX_HTML     " /index.html"
#define GET_FAVICON_ICO    " /favicon.ico"

#define GET_EXIT           "/exit"
#define GET_SAVE           "/save"
#define GET_NO_SCAN        "/0wifi"
#define GET_INFO           "/info"
#define GET_WIFI           "/wifi"
#define GET_PLUS_CONNECT   "/conn"
#define GET_SAVE_CONNECT   "/0save"

enum http_response_page{
	http_page_not_found,
	http_favicon_ico,
	http_page_start,
	http_page_exit,
	http_page_save,
	http_page_wifi_no_scan,
	http_page_info,
	http_page_wifi,
	http_page_plus_connect,
	http_page_plus_failed,
	http_page_plus_created,
	http_page_plus_connected,

};

typedef struct{
	char param[3];
	char *value;
}url_param;


const char html_head[]           = "<!DOCTYPE html><html lang=\"en\"><head><meta name=\"viewport\"content=\"width=device-width,initial-scale=1,user-scalable=no\"/><title>PlusCart(+) WiFi Manager Portal</title>"
                                   "<style> .c{text-align:center}div,input{padding:5px;font-size:1em}input{width:95%}a{color:#000}a:hover,a:active{color:red}body{text-align:center;font-family:verdana}button{border:0;border-radius:0.3rem;background-color:#67b9DD;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;cursor:pointer} .q{float:right;width:64px;text-align:right} .l{background:url(\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAMAAABEpIrGAAAALVBMVEX///8EBwfBwsLw8PAzNjaCg4NTVVUjJiZDRUUUFxdiZGSho6OSk5Pg4eFydHTCjaf3AAAAZElEQVQ4je2NSw7AIAhEBamKn97/uMXEGBvozkWb9C2Zx4xzWykBhFAeYp9gkLyZE0zIMno9n4g19hmdY39scwqVkOXaxph0ZCXQcqxSpgQpONa59wkRDOL93eAXvimwlbPbwwVAegLS1HGfZAAAAABJRU5ErkJggg==\")no-repeat left center;background-size:1em} </style>"
                                   "<script>function c(l){document.getElementById('s').value=l.innerText||l.textContent;document.getElementById('p').focus();} </script>"
                                   "</head><body>"
		                           "<div style=\"background-image:linear-gradient(to right,#37609f 0%,#67b9DD 80%);color:#fff;margin:0 0 15px 0\"><h2>PlusCart(+)</h2><h3>WiFi Manager Portal</h3></div>"
                                   "<div style=\"text-align:left;display:inline-block;min-width:260px;\">";

const char html_portal_options[] = "<form action=\"" GET_WIFI "\"method=\"get\"><button>Configure WiFi</button></form><br/>"
		                           "<form action=\"" GET_NO_SCAN "\"method=\"get\"><button>Configure WiFi(No Scan)</button></form><br/>"
		                           "<form action=\"" GET_INFO "\"method=\"get\"><button>Connection Info</button></form><br/>"
		                           "<form action=\"" GET_EXIT "\"method=\"get\"><button>Exit</button></form>";

const char html_form[]           = "<form method='get'action='" GET_SAVE "'><input id='s'name='s'length=32 placeholder='SSID'><br/><input id='p'name='p'length=64 type='password'placeholder='password'><br/>"
                                   "<br/><button type='submit'>Save</button></form>"
								   "<br/><form action=\"" GET_WIFI "\"method=\"get\"><button>Rescan WiFi</button></form>";

const char html_plus_connect[]   = "<br/><form action=\"" GET_PLUS_CONNECT "\"method=\"get\"><button>PlusStore Connect</button></form>";

const char html_connect_form[]   = "<form method='get'action='" GET_SAVE_CONNECT "'><input id='s'name='s'length=32 placeholder='PlusStore User or Email'><br/>"
                                   "<br/><button type='submit'>Request Connect</button></form>";

const char html_back[]           = "</br><form action=\"/index.html\"method=\"get\"><button>Back</button></form>";


const char html_saved[]          = "<div>Credentials Saved<br/>Trying to connect WiFi module to network.<br/>"
		                           "To check if the action was successful go back to the main menu and click the Connection Info button.<br/>"
		                           "If it failed, restart the WiFi Manager Portal to try again</div>";

const char html_exit[]           = "<div>WiFi Manager closed. PlusCart is restarting.</div>";
const char html_plus_failed[]    = "<div>Connection request for your PlusCart failed, maybe the PlusCart is already connected?</div>";
const char html_plus_created[]   = "<div>PlusStore account for your email has been created, please check your mail and finish the registration.</div>";
const char html_plus_connected[] = "<div>Connection request for your PlusCart sent, please check your email and confirm.</div>";


const char html_end[]            = "</div></body></html>";


const char not_found_text[] = "HTTP/1.1 404 Not Found\n"
                              "Content-type: text/plain\r\n\r\n"
                              "page not found";

const char http_header_html[] = "HTTP/1.1 200 OK\n"
                                "Content-type: text/html\r\n\r\n";

const char favicon_ico[] = {
	// HTTP/1.1 200 OK
	// Content-type:image/x-icon
	0x48, 0x54, 0x54, 0x50, 0x2F, 0x31, 0x2E, 0x31, 0x20, 0x32, 0x30, 0x30, 0x20, 0x4F, 0x4B, 0x0A,
	0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x74, 0x79, 0x70, 0x65, 0x3A, 0x20, 0x69, 0x6D,
	0x61, 0x67, 0x65, 0x2F, 0x78, 0x2D, 0x69, 0x63, 0x6F, 0x6E, 0x0D, 0x0A, 0x0D, 0x0A,
    // Content
	0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x10, 0x10, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x03,
	0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE4, 0xBC,
	0x6A, 0xE2, 0xBA, 0x68, 0xD9, 0xB0, 0x61, 0xDC, 0xB3, 0x64, 0xCF, 0xA3, 0x56, 0xD2, 0xA6, 0x59,
	0xCC, 0x9D, 0x53, 0xC9, 0x9A, 0x50, 0xC5, 0x91, 0x4A, 0xC2, 0x8E, 0x47, 0xBD, 0x89, 0x43, 0xB8,
	0x84, 0x3E, 0xB0, 0x79, 0x36, 0xB1, 0x7A, 0x37, 0xAE, 0x74, 0x32, 0xA8, 0x6E, 0x2C, 0xE4, 0xBB,
	0x6C, 0xE0, 0xB9, 0x6B, 0xDC, 0xB6, 0x6E, 0xCF, 0xA9, 0x61, 0xD0, 0xA6, 0x5B, 0xCD, 0x9F, 0x52,
	0xD1, 0xA0, 0x54, 0xCB, 0x99, 0x4D, 0xCD, 0x98, 0x4F, 0xBC, 0x87, 0x3E, 0xC4, 0x8D, 0x48, 0xB9,
	0x85, 0x43, 0xB0, 0x7E, 0x42, 0xAB, 0x77, 0x3B, 0xAE, 0x78, 0x39, 0xA5, 0x6B, 0x2A, 0xEA, 0xC0,
	0x75, 0xD1, 0xAA, 0x65, 0x6F, 0x52, 0x19, 0x80, 0x62, 0x29, 0xD0, 0xA6, 0x63, 0xD4, 0xA3, 0x57,
	0xD3, 0x9E, 0x4E, 0xCC, 0x94, 0x43, 0xC8, 0x8F, 0x40, 0xCB, 0x91, 0x46, 0xB9, 0x81, 0x3A, 0xB4,
	0x82, 0x46, 0x70, 0x46, 0x17, 0x57, 0x2D, 0x00, 0xA1, 0x6C, 0x33, 0xA9, 0x70, 0x32, 0xD8, 0xB2,
	0x72, 0xBE, 0x9C, 0x61, 0x27, 0x0C, 0x00, 0xA8, 0x89, 0x56, 0xDA, 0xAF, 0x6C, 0xD4, 0xA1, 0x58,
	0xCE, 0x99, 0x50, 0xD0, 0x9B, 0x52, 0xCE, 0x96, 0x4F, 0xC2, 0x8A, 0x43, 0xBE, 0x85, 0x40, 0xB7,
	0x83, 0x47, 0x8A, 0x62, 0x38, 0x2F, 0x0A, 0x00, 0x8D, 0x5D, 0x2D, 0x9B, 0x69, 0x34, 0xCC, 0xB0,
	0x81, 0x4B, 0x2F, 0x00, 0x46, 0x28, 0x00, 0xCB, 0xA5, 0x6F, 0xCE, 0x9B, 0x55, 0xD5, 0xA0, 0x57,
	0xC2, 0x93, 0x55, 0xBD, 0x92, 0x59, 0xB8, 0x8C, 0x56, 0xB6, 0x87, 0x4A, 0xBF, 0x86, 0x41, 0xB0,
	0x78, 0x37, 0xA4, 0x78, 0x49, 0x3A, 0x15, 0x00, 0x46, 0x1F, 0x00, 0x88, 0x63, 0x3D, 0xB6, 0xA0,
	0x7D, 0x22, 0x09, 0x00, 0x75, 0x54, 0x23, 0xD0, 0xA5, 0x6C, 0xDA, 0xA6, 0x60, 0xD1, 0x9D, 0x5A,
	0xBF, 0x97, 0x66, 0x4B, 0x29, 0x00, 0x49, 0x26, 0x00, 0xAF, 0x87, 0x57, 0xB8, 0x82, 0x43, 0xB8,
	0x80, 0x3F, 0xAA, 0x7B, 0x47, 0x5E, 0x36, 0x0C, 0x27, 0x06, 0x00, 0x7D, 0x60, 0x45, 0x8B, 0x79,
	0x5C, 0x26, 0x0C, 0x00, 0x90, 0x6B, 0x37, 0xD1, 0xA4, 0x67, 0xC8, 0x98, 0x58, 0xCF, 0xA2, 0x69,
	0xA9, 0x8A, 0x63, 0x3F, 0x27, 0x09, 0x3A, 0x22, 0x06, 0xA8, 0x88, 0x64, 0xAB, 0x7D, 0x47, 0xAA,
	0x76, 0x3A, 0xAF, 0x7E, 0x46, 0x6F, 0x45, 0x16, 0x2B, 0x0C, 0x00, 0x5F, 0x47, 0x2F, 0x69, 0x58,
	0x3E, 0x21, 0x08, 0x00, 0xA5, 0x7F, 0x49, 0xD1, 0xA5, 0x66, 0xBF, 0x90, 0x53, 0x76, 0x4F, 0x1B,
	0x67, 0x4C, 0x2A, 0x2A, 0x16, 0x00, 0x2B, 0x16, 0x00, 0x5B, 0x3F, 0x20, 0x72, 0x49, 0x18, 0xA5,
	0x73, 0x39, 0xA5, 0x73, 0x39, 0x82, 0x57, 0x26, 0x23, 0x06, 0x00, 0x45, 0x30, 0x1A, 0x67, 0x58,
	0x3E, 0x1E, 0x08, 0x00, 0xAA, 0x85, 0x51, 0xCA, 0x9E, 0x61, 0xA7, 0x7A, 0x3D, 0x33, 0x0E, 0x00,
	0x20, 0x07, 0x00, 0x17, 0x05, 0x00, 0x17, 0x05, 0x00, 0x20, 0x07, 0x00, 0x34, 0x0C, 0x00, 0x8A,
	0x5A, 0x20, 0xAC, 0x7C, 0x42, 0x7D, 0x54, 0x23, 0x29, 0x0D, 0x00, 0x43, 0x30, 0x1B, 0x6E, 0x60,
	0x44, 0x1F, 0x0C, 0x00, 0x95, 0x74, 0x42, 0xD0, 0xA6, 0x6B, 0xCE, 0xA2, 0x63, 0xB4, 0x8D, 0x56,
	0xA9, 0x8E, 0x69, 0x41, 0x2C, 0x10, 0x37, 0x21, 0x05, 0x9F, 0x82, 0x5D, 0xA7, 0x7D, 0x48, 0xAD,
	0x7E, 0x41, 0xA5, 0x78, 0x3F, 0x72, 0x4B, 0x1E, 0x22, 0x06, 0x00, 0x4E, 0x39, 0x23, 0x9C, 0x8B,
	0x6A, 0x23, 0x0E, 0x00, 0x78, 0x5C, 0x2D, 0xC0, 0x9B, 0x63, 0xD1, 0xA2, 0x5E, 0xCD, 0xA0, 0x5D,
	0xAF, 0x8E, 0x5D, 0x41, 0x25, 0x00, 0x4A, 0x2E, 0x05, 0xA4, 0x80, 0x50, 0xAF, 0x7E, 0x40, 0xAA,
	0x77, 0x38, 0x98, 0x6D, 0x3A, 0x5F, 0x3C, 0x14, 0x2D, 0x11, 0x00, 0x69, 0x51, 0x35, 0xCD, 0xB5,
	0x87, 0x33, 0x1B, 0x00, 0x3D, 0x25, 0x00, 0xBE, 0x9E, 0x69, 0xCB, 0x9E, 0x5A, 0xC9, 0x99, 0x51,
	0xBE, 0x95, 0x57, 0x89, 0x62, 0x2B, 0x81, 0x5A, 0x23, 0xB0, 0x84, 0x49, 0xB8, 0x83, 0x40, 0xAF,
	0x7C, 0x3D, 0xA3, 0x7A, 0x4D, 0x32, 0x10, 0x00, 0x36, 0x14, 0x00, 0x81, 0x5F, 0x3B, 0xD1, 0xAC,
	0x6E, 0x95, 0x74, 0x3C, 0x23, 0x0B, 0x00, 0xA7, 0x8C, 0x5A, 0xCF, 0xA5, 0x64, 0xCA, 0x98, 0x50,
	0xC6, 0x92, 0x4B, 0xC4, 0x90, 0x49, 0xBE, 0x88, 0x41, 0xBC, 0x85, 0x40, 0xB7, 0x80, 0x3D, 0xA5,
	0x75, 0x3B, 0x87, 0x60, 0x39, 0x2C, 0x08, 0x00, 0x71, 0x45, 0x16, 0x95, 0x65, 0x31, 0xE1, 0xB6,
	0x6D, 0xD4, 0xAD, 0x69, 0x46, 0x28, 0x00, 0x77, 0x58, 0x21, 0xC6, 0x9C, 0x5B, 0xCF, 0x9E, 0x54,
	0xC8, 0x92, 0x45, 0xCB, 0x92, 0x43, 0xCA, 0x8E, 0x42, 0xBA, 0x7F, 0x37, 0xBC, 0x82, 0x40, 0xAA,
	0x78, 0x3E, 0x67, 0x3C, 0x11, 0x45, 0x1A, 0x00, 0xA1, 0x6B, 0x36, 0x9D, 0x64, 0x27, 0xDE, 0xB2,
	0x65, 0xD3, 0xA9, 0x5E, 0xD2, 0xA8, 0x63, 0xCA, 0xA0, 0x5B, 0xCC, 0x9F, 0x56, 0xC7, 0x96, 0x4C,
	0xCF, 0x9A, 0x51, 0xC4, 0x8D, 0x44, 0xC6, 0x8B, 0x45, 0xC2, 0x87, 0x42, 0xB4, 0x7A, 0x38, 0xB5,
	0x7C, 0x3F, 0xA8, 0x71, 0x38, 0x9F, 0x66, 0x2F, 0xA7, 0x6B, 0x30, 0xA0, 0x61, 0x24, 0xE4, 0xB6,
	0x68, 0xDA, 0xAC, 0x5E, 0xDA, 0xA9, 0x5D, 0xD5, 0xA4, 0x58, 0xCD, 0x9C, 0x52, 0xCE, 0x9D, 0x53,
	0xC6, 0x90, 0x49, 0xC5, 0x8F, 0x48, 0xC1, 0x88, 0x43, 0xBA, 0x81, 0x3C, 0xBB, 0x7E, 0x3E, 0xB7,
	0x7A, 0x3A, 0xAF, 0x70, 0x33, 0xAF, 0x70, 0x33, 0xA2, 0x61, 0x24, 0xA9, 0x68, 0x2B, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#endif	/* ESP8266_AT_WIFIMANAGER_H */
