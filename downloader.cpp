#include "downloader.h"

using namespace std;

Downloader::Downloader(Source source) : source(source)
{
//    this->source = source;
}

struct MemoryStruct {
  char *data = NULL;
  size_t size = 0;
};

//static?
size_t Downloader::WriteAudio(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  if (mem->data == NULL) {
      qDebug() << "malloc";
    mem->data = (char *) malloc(realsize);
  } else {
      qDebug() << (mem -> data);
    mem->data = (char *) realloc(mem->data, mem->size + realsize);
  }
  qDebug() << realsize;
  qDebug() << mem->size;

  memcpy(&(mem->data[mem->size]), contents, realsize);
  mem->size += realsize;

  return realsize;
}

void Downloader::download() {

      CURL *curl;
      string url = source.getUrl();

      qDebug() << url.c_str();

      struct MemoryStruct mem;
      curl_global_init(CURL_GLOBAL_DEFAULT); //not thread-safe
      curl = curl_easy_init(); //check for errors after calling these functions
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteAudio);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &mem); //?? how to work with these data chunks? there was an example
// write to string?

//       FILE* file = fopen("new_file", "w");
//       curl_easy_setopt(curl, CURLOPT_WRITEDATA, file) ;

      CURLcode res = curl_easy_perform(curl); //TODO: make the download asynchronous with multi handler
//      //check res
//      curl_easy_cleanup(curl);
//      curl_global_cleanup();

//      std::ofstream file;
//      file.open("data", fstream::out);
//      file << data << std::endl;

//      file.close();
}

//int main() {
//  CURL *curl;
//  CURLM *curlm;
//  CURLcode res;
//  curl_global_init(CURL_GLOBAL_DEFAULT); //not thread-safe
//  curl = curl_easy_init(); //check for errors after calling these functions
//  curl_easy_setopt(curl, CURLOPT_URL, url);
//  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
//  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk); //?? how to work with these data chunks? there was an example

//  int still_running;
//  curl_multi_perform(curlm, &still_running);
//  do {
//    CURLMcode mc; /* curl_multi_wait() return code */
//    int numfds;

//    /* wait for activity, timeout or "nothing" */
//    mc = curl_multi_wait(multi_handle, NULL, 0, 1000, &numfds);

//    if(mc != CURLM_OK) {
//      fprintf(stderr, "curl_multi_wait() failed, code %d.\n", mc);
//      break;
//    }

//    /* 'numfds' being zero means either a timeout or no file descriptors to
//       wait for. Try timeout on first occurrence, then assume no file
//       descriptors and no file descriptors to wait for means wait for 100
//       milliseconds. */

//    if(!numfds) {
//      repeats++; /* count number of repeated zero numfds */
//      if(repeats > 1) {
//        WAITMS(100); /* sleep 100 milliseconds */
//      }
//    }
//    else
//      repeats = 0;

//    curl_multi_perform(multi_handle, &still_running);
//  } while(still_running);

//  curl_easy_cleanup(curl);
//  curl_multi_cleanup(curlm);
//  curl_global_cleanup();
//}
