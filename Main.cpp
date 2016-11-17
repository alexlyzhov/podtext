#include <iostream>
#include <string>
#include <curl/curl.h>
#include <cstring>
// windows: urlmon.dll, URLDownloadToFile? Or libcurl which could have been easier

using namespace std;

// const string url = "http://www.slow-chinese.com/podcasts/Slow_Chinese_150.mp3";
char *url = "http://www.slow-chinese.com/podcasts/Slow_Chinese_150.mp3";

struct MemoryStruct {
  char *data = NULL;
  size_t size = 0;
};

static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  if (mem->data == NULL) {
    mem->data = (char *) malloc(realsize);
  } else {
    mem->data = (char *) realloc(mem->data, mem->size + realsize);
  }
  printf("realsize: %d\n", realsize);
  printf("mem size: %d\n", mem->size);

  memcpy(&(mem->data[mem->size]), contents, realsize);
  mem->size += realsize;

  return realsize;
}

int main() {
  CURL *curl;
  CURLcode res;
  struct MemoryStruct mem;
  curl_global_init(CURL_GLOBAL_DEFAULT); //not thread-safe
  curl = curl_easy_init(); //check for errors after calling these functions
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &mem); //?? how to work with these data chunks? there was an example
  curl_easy_perform(curl); //TODO: make the download asynchronous with multi handler

  curl_easy_cleanup(curl);
  curl_global_cleanup();
}
