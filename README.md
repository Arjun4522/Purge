# Purge: An Automated Garbage Collector for C/C++
Purge is a lightweight garbage collector for C that automatically detects and frees unreachable memory. It eliminates memory leaks by scanning and cleaning up unused objects, making your C programs more efficient and resource-friendly without manual memory management headaches.

Link to the article: https://medium.com/@ghosalarjun/efficient-memory-management-exploring-garbage-collection-in-c-c-and-the-purge-project-d7f87db9bb95

# Results
Valgrind memory leak test results before integrating Purge:

![nogc](https://github.com/user-attachments/assets/5cdc9a63-2b21-4681-a1e7-ab18be5dcdfa)

Valgrind memory leak test results after integrating Purge:

![gc](https://github.com/user-attachments/assets/e93292b7-55ed-4c78-909e-f3a5f504ea79)
