#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include "frame.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif
#include "app.h"

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
	std::cout << std::string(ptr, size*nmemb) << std::endl;
	return size*nmemb;
}

// wxWidgets: https://www.wxwidgets.org/ wx-config

int fetch_url() {
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://random-stuff.netlify.app");
		/* example.com is redirected, so we tell libcurl to follow redirection */
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);
	}
	return 0;
}