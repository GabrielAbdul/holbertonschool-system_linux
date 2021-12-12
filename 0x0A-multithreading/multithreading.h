#ifndef MULTITHREADING_H
#define MULTITHREADING_H

#include <stdio.h>
#include <stdlib.h>

void *thread_entry(void *arg);
int tprintf(char const *format, ...);
void blur_portion(blur_portion_t const *portion);
void blur_image(img_t *img_blur, img_t const *img, kernel_t const *kernel);
int tprintf(char const *format, ...);
list_t *prime_factors(char const *s);
task_t *create_task(task_entry_t entry, void *param);
void destroy_task(task_t *task);
void *exec_tasks(list_t const *tasks);

#endif /* MULTITHREADING_H */