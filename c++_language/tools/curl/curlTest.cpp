#include <iostream>
#include <sstream>
#include <string>
#include <curl/curl.h>

using namespace std;

size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream)
{
  string data((const char*)ptr, (size_t)size*nmemb);
  *((stringstream*)stream) << data << endl;
  return size*nmemb;
}

/*
 * jessie: libcurl4-nss-dev
 * compile : g++ -lcurl curlTest.cpp
 */
int main(void)
{

  CURL *curl;
  // FILE *fp;
  string url = "http://10.143.142.47:55801/flowrpt0.xml";
  char outfilename[FILENAME_MAX] = "page.html";
  curl = curl_easy_init();
  if (curl)
  {
  	// fp = fopen(outfilename, "wb");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    
    stringstream out;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
    // curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    CURLcode res = curl_easy_perform(curl);
    cout << out.str()<< endl;
    curl_easy_cleanup(curl);
    // fclose(fp);
  }
  return 0;
}