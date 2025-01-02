# Purge: An Automated Garbage Collector for C/C++
Purge is a lightweight garbage collector for C that automatically detects and frees unreachable memory. It eliminates memory leaks by scanning and cleaning up unused objects, making your C programs more efficient and resource-friendly without manual memory management headaches.

Link to the article: https://medium.com/@ghosalarjun/efficient-memory-management-exploring-garbage-collection-in-c-c-and-the-purge-project-d7f87db9bb95

# Results
Below are the Valgrind memory leak test results before and after integrating Purge:

![nogc](https://github.com/user-attachments/assets/abfcb88d-6c0e-4473-a956-073054691652)

![gc](https://github.com/user-attachments/assets/4bcce11a-0198-4da1-a7f7-82e624c80c94)
