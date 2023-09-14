# compilation_time_task

Здравствуйте!
Мое решение задания можно найти в папке answer (compilation_time.c)

Также я сделал небольшой тестовый проект, который шлет в serial дату и время в нужном формате:
<img width="521" alt="image" src="https://github.com/nktsb/compilation_time_task/assets/55137551/6dc79c27-8b75-4b34-8c11-b173fcd2df76">

Тестовый проект собирается для STM32F103RBT6 через make в `test_project/compilation_time_task`:
```
# build
make

# clean up
make clean

# flash
make burn
```

Также я сделал два варианта решения:
- С использованием функции sscanf
- Без использования функции sscanf

Второй вариант сделал, потому что функция sscanf не всегда применима в микроконтроллерах, т.к. занимает много места во флэше.

Для переключения между вариантами используется дейфайн в начале файла compilation_time.c:

`#define USING_SSCANF`

Если нужен вариант без sscanf, то его нужно закомментить.
