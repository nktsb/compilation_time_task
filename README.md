# compilation_time_task
Hello, Whoosh!

Здравствуйте!
Мое решение задания можно найти в папке answer (compilation_time.c)

Также я сделал небольшой тестовый проект, который шлет в serial дату и время в нужном формате:
<img width="265" alt="image" src="https://github.com/nktsb/compilation_time_task/assets/55137551/791e8480-946a-4112-9afc-eb4441b148e5">

Тестовый проект собрал в CubeIDE для F103RBT6 (Nucleo).

Также я сделал два варианта решения:
- С использованием функции sscanf
- Без использования функции sscanf

Второй вариант сделал, потому что функция sscanf не всегда применима в микроконтроллерах, т.к. занимает много места во флэше.

Для переключения между вариантами используется дейфайн в начале файла compilation_time.c:
#define USING_SSCANF

Если нужен вариант без sscanf, то его нужно закомментить.
