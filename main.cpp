//подключаем необходимые заголовочные файлы
#include <iostream>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char* argv[])
{
  char *name = argv[1];
  CURL *curl = curl_easy_init(); //объявление объект типа CURL и его инициализация
  if(curl) //обязательная проверка
  {
    CURLcode res;
//    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0); // Не проверять SSL сертификат
//    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0); 
    curl_easy_setopt(curl, CURLOPT_NOBODY, true); // Изменяет метод запроса на HEAD и игнорирует содержимое 
    curl_easy_setopt(curl, CURLOPT_URL, name);   // Получить страницу по адресу 
    res = curl_easy_perform(curl);     //вызываем функцию, выполняющюю все операции, заданные в опциях выше, результат - объект типа CURLcode
    if(res == CURLE_OK)  //проверяем успешность выполнения операции
    {
      char *url = NULL;
      curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
      if(url)
      {
          printf("Redirect to: %s\n", url);
      }
      // вывод кода
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      printf("Код ответа: %ld\n", response_code);
    }
    else printf( "curl_easy_perform() failed: %s\n", curl_easy_strerror(res) );

    curl_easy_cleanup(curl);    //выполняем обязательное завершение сессии
  }
  return 0;
}
