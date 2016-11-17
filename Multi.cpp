#include <iostream>
#include <string>
#include <curl/curl.h>
// windows: urlmon.dll, URLDownloadToFile? Or libcurl which could have been easier

using namespace std;

// const string url = "http://www.slow-chinese.com/podcasts/Slow_Chinese_150.mp3";
char *url = "http://www.slow-chinese.com/podcasts/Slow_Chinese_150.mp3";
char outfilename[FILENAME_MAX] = "Slow_Chinese_150.mp3"; // absolute path?

int main() {
  CURL *curl;
  CURLM *curlm;
  CURLcode res;
  curl_global_init(CURL_GLOBAL_DEFAULT); //not thread-safe
  curl = curl_easy_init(); //check for errors after calling these functions
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk); //?? how to work with these data chunks? there was an example

  int still_running;
  curl_multi_perform(curlm, &still_running);
  do {
    CURLMcode mc; /* curl_multi_wait() return code */
    int numfds;

    /* wait for activity, timeout or "nothing" */
    mc = curl_multi_wait(multi_handle, NULL, 0, 1000, &numfds);

    if(mc != CURLM_OK) {
      fprintf(stderr, "curl_multi_wait() failed, code %d.\n", mc);
      break;
    }

    /* 'numfds' being zero means either a timeout or no file descriptors to
       wait for. Try timeout on first occurrence, then assume no file
       descriptors and no file descriptors to wait for means wait for 100
       milliseconds. */

    if(!numfds) {
      repeats++; /* count number of repeated zero numfds */
      if(repeats > 1) {
        WAITMS(100); /* sleep 100 milliseconds */
      }
    }
    else
      repeats = 0;

    curl_multi_perform(multi_handle, &still_running);
  } while(still_running);

  curl_easy_cleanup(curl);
  curl_multi_cleanup(curlm);
  curl_global_cleanup();
}
