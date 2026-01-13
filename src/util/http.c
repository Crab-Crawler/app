#include <curl/curl.h>

struct HttpResponse
{
    long status;
    char *body;
};

static size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    size_t total = size * nmemb;
    struct HttpResponse *resp = (struct HttpResponse *)userdata;

    size_t old_len = resp->body ? strlen(resp->body) : 0;
    char *new_body = (char *)realloc(resp->body, old_len + total + 1);
    if (!new_body)
        return 0;

    resp->body = new_body;
    memcpy(resp->body + old_len, ptr, total);
    resp->body[old_len + total] = '\0';

    return total;
}

struct HttpResponse get(const char *url)
{
    struct HttpResponse resp = {0, NULL};

    CURL *curl = curl_easy_init();
    if (!curl)
        return resp;

    resp.body = (char *)malloc(1);
    resp.body[0] = '\0';

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resp);

    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &resp.status);

    curl_easy_cleanup(curl);
    return resp;
}
