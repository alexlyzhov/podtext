#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

// const string url = "http://www.slow-chinese.com/podcasts/Slow_Chinese_150.mp3";
char *url = "http://www.slow-chinese.com/podcasts/Slow_Chinese_150.mp3";
char outfilename[FILENAME_MAX] = "Slow_Chinese_150.mp3"; // absolute path?

int main() {
  CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}
