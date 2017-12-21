/*
Copyright: Boaz Segev, 2017
License: MIT
*/
#ifndef H_HTTP1_H
#define H_HTTP1_H

#include "http.h"

#ifndef HTTP1_MAX_HEADER_SIZE
/**
Sets the maximum allowed size of a requests header section
(all cookies, headers and other data that isn't the request's "body").

This value includes the request line itself.

Defaults to ~16Kb headers per request.
*/
#define HTTP1_MAX_HEADER_SIZE (16 * 1024) /* ~16kb */
#endif

/** Creates an HTTP1 protocol object and handles any unread data in the buffer
 * (if any). */
protocol_s *http1_new(uintptr_t uuid, http_settings_s *settings,
                      void *unread_data, size_t unread_length);

/** Manually destroys the HTTP1 protocol object. */
void http1_destroy(protocol_s *);

#endif
